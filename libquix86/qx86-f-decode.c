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

    /* Step 5.  Finalize instruction structure.  */
    insn->iclass                        = qx86_mtab[insn->mnemonic].iclass;

    /* Success.  */
    return insn->data = data, QX86_SUCCESS;
}
