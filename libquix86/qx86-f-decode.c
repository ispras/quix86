/* +------------------------------------------------------------------------+
   | quix86                                                                 |
   +------------------------------------------------------------------------+
   | This file is part of quix86, an x86-64 instruction decoder.            |
   |                                                                        |
   | Copyright (C) 2011 Institute for System Programming of Russian Academy |
   | of Sciences.                                                           |
   |                                                                        |
   | Contact e-mail: <unicluster@ispras.ru>.                                |
   |                                                                        |
   | quix86 is free software: you can redistribute it and/or modify it      |
   | under the terms of the GNU Lesser General Public License as published  |
   | by the Free Software Foundation, either version 3 of the License, or   |
   | (at your option) any later version.                                    |
   |                                                                        |
   | quix86 is distributed in the hope that it will be useful, but WITHOUT  |
   | ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  |
   | FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public   |
   | License for more details.                                              |
   |                                                                        |
   | You should have received a copy of the GNU Lesser General Public       |
   | License along with quix86. If not, see <http://www.gnu.org/licenses/>. |
   +------------------------------------------------------------------------+ */

int
qx86_decode(qx86_insn *insn, int processorMode, QX86_CONST void *ptr, int ptrSize)
{
    qx86_ctx                            ctx;

    int                                 i;
    int                                 result;

    void *                              data;

    /* Test insn and ptr to be non-NULL.  */
    if (!insn || !ptr) return QX86_E_API;

    /* Test ptrSize to be positive.  */
    if (ptrSize <= 0)
    {
        /* Either an API error or a null call.  */
        return ptrSize ? QX86_E_API : QX86_E_INSN_INCOMPLETE;
    }

    /* Validate processorMode.  */
    if ((processorMode & QX86_SIZE_MASK) != processorMode) return QX86_E_API;
    if ((processorMode & QX86_SIZE_MASK) == QX86_SIZE_INVALID) return QX86_E_API;

    /* Clamp ptrSize.  */
    if (ptrSize > QX86_INSN_SIZE_MAX) ptrSize = QX86_INSN_SIZE_MAX;

    /* Initialize ctx.  */
    ctx.ptr                             = (qx86_uint8 *) ptr;
    ctx.ptrSize                         = ptrSize;
    ctx.pumpIndex                       = -1;

    /* Remember data stored in insn.  */
    data                                = insn->data;

    /* Initialize insn for a new decode iteration.  */
    insn->rawSize                       = 0;
    insn->processorMode                 = processorMode;
    insn->defects                       = QX86_DEFECT_NONE;
    insn->data                          = &ctx;

    /* Step 1.  Scan and decode prefixes.  */
    if (QX86_SUCCESS != (result = qx86_decode_prefixes(insn)))
    {
        /* Put back user data and bail out.  */
        return insn->data = data, result;
    }

    /* Step 2.  Decode instruction form from opcode maps.  */
    if (QX86_SUCCESS != (result = qx86_decode_opcode(insn)))
    {
        /* Put back user data and bail out.  */
        return insn->data = data, result;
    }

    /* Step 3.  Perform operand size fixup for D64 and F64 cases.  */
    if (QX86_SIZE_64 == (processorMode & QX86_SIZE_MASK))
    {
        /* See if the mnemonic has a D64 or F64 attribute.  */
        if (qx86_mtab[insn->mnemonic].attributes & (QX86_MATTRIBUTE_DEFAULT_SIZE_64 | QX86_MATTRIBUTE_FIXED_SIZE_64))
        {
            /* Fixed makes us do fixup in all cases.  */
            result = qx86_mtab[insn->mnemonic].attributes & QX86_MATTRIBUTE_FIXED_SIZE_64;

            /* Otherwise, must not be overridden.  */
            result |= !insn->attributes.operandSizeOverridden;

            /* See if we must perform fixup.  */
            if (result)
            {
                /* Yes.  */
                insn->attributes.operandSize = QX86_SIZE_64;

                /* Move up the mnemonic chain.  */
                while (QX86_MNEMONIC_NONE != qx86_mtab[insn->mnemonic].promoted) insn->mnemonic = qx86_mtab[insn->mnemonic].promoted;
            }
        }
    }

    /* Step 4.  Decode instruction operands.  */
    for (i = 0; i < insn->operandCount; ++i)
    {
        /* Decode i'th operand.  */
        if (QX86_SUCCESS != (result = qx86_decode_operand(insn, i)))
        {
            /* Put back user data and bail out.  */
            return insn->data = data, result;
        }
    }

    /* Step 5.  Process idioms.  */
    switch (insn->mnemonic)
    {
    case QX86_MNEMONIC_XCHG:
        /* XCHG rAX, rAX when encoded as 90h is interpreted as a NOP which makes
           a difference in 64-bit mode because of no implicit GPR extension.  */
        if ((QX86_OPERAND_FORM_TYPE_RTUPLE == insn->operandForms[0]->ft) && (QX86_OPERAND_FORM_TYPE_RTUPLE == insn->operandForms[1]->ft))
        {
            /* Both operands are register tuples, this indicates the 9Xh
               opcodes.  */
            if (&qx86_rtuple_r0 == insn->operandForms[0]->u.r.rtuple)
            {
                /* This is the 90h opcode.  */
                if (insn->operands[0].u.r.rindex == insn->operands[1].u.r.rindex)
                {
                    /* Not an XCHG: NOP or PAUSE.  */
                    insn->mnemonic      = 0xF3 == insn->modifiers.repeatPrefix ? QX86_MNEMONIC_PAUSE : QX86_MNEMONIC_NOP;
                    insn->operandCount  = 0;
                }
            }
        }

        /* Done.  */
        break;

    case QX86_MNEMONIC_MOV:
        /* Moves to CR0 have additional possibilities.  */
        if ((QX86_OPERAND_TYPE_REGISTER == insn->operands[0].ot) && (QX86_REGISTER_CR0 == insn->operands[0].u.r.rindex))
        {
            /* Move to CR0 is interpreted as move to CR8 when LOCK prefix is
               present.  */
            if (insn->attributes.interlocked)
            {
                /* Update to CR8.  TODO: should LOCK be reclassified instead?  */
                insn->operands[0].u.r.rindex
                                        = QX86_REGISTER_CR8;
                insn->attributes.interlocked
                                        = 0;
            }
        }
        /* Moves from CR0 have additional possibilities.  */
        if ((QX86_OPERAND_TYPE_REGISTER == insn->operands[1].ot) && (QX86_REGISTER_CR0 == insn->operands[1].u.r.rindex))
        {
            /* Move from CR0 is interpreted as move from CR8 when LOCK prefix is
               present.  */
            if (insn->attributes.interlocked)
            {
                /* Read from CR8.  TODO: should LOCK be reclassified instead?  */
                insn->operands[1].u.r.rindex
                                        = QX86_REGISTER_CR8;
                insn->attributes.interlocked
                                        = 0;
            }
        }

        /* Done.  */
        break;
    }

    /* Step 6.  Finalize instruction structure.  */
    insn->iclass                        = qx86_mtab[insn->mnemonic].iclass;

    /* Success.  */
    return insn->data = data, QX86_SUCCESS;
}
