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
qx86_calculate_effective_address(QX86_CONST qx86_insn *insn, int operandIndex, qx86_uint64 *address)
{
    QX86_CONST qx86_operand *           operand;

    qx86_uint8                          value[32];

    qx86_uint64                         offset;
    int                                 addressSize;

    /* Test insn and address to be non-NULL.  */
    if (!insn || !address) return QX86_E_API;

    /* Test operandIndex to be a valid index.  */
    if (operandIndex < -insn->implicitOperandCount) return QX86_E_API;
    if (operandIndex >= insn->operandCount) return QX86_E_API;

    /* Get operand pointer.  */
    operand = insn->operands + operandIndex;

    /* The operand must be a memory operand.  */
    if (QX86_OPERAND_TYPE_MEMORY != operand->ot) return QX86_E_API;

    /* In case the callback function is NULL, assume it fails.  */
    if (!insn->callback) return QX86_E_CALLBACK;

    /* Load displacement, part 1.  */
    if (operand->u.m.disp[operand->u.m.dispSize - 1] & 0x80)
    {
        /* MSB is set, extend 1 into upper bits.  */
        switch (operand->u.m.dispSize)
        {
        case QX86_DISP_64:
            /* Use zero instead because thus we can use XOR.  */
            offset = 0ULL; break;

        case QX86_DISP_32:
            /* Leave 32 bits intact.  */
            offset = 0xFFFFFFFF00000000ULL; break;

        case QX86_DISP_16:
            /* Leave 16 bits intact.  */
            offset = 0xFFFFFFFFFFFF0000ULL; break;

        case QX86_DISP_8:
            /* Leave 8 bits intact.  */
            offset = 0xFFFFFFFFFFFFFF00ULL; break;

        default:
            /* No action.  */
            break;
        }
    }
    else
    {
        /* MSB is not set, extend 0 into upper bits.  */
        offset = 0ULL;
    }

    /* Load displacement, part 2.  */
    switch (operand->u.m.dispSize)
    {
    case QX86_DISP_64:
        /* Move bits 32..63.  */
        offset                          |= ((qx86_uint64) operand->u.m.disp[7]) << 56;
        offset                          |= ((qx86_uint64) operand->u.m.disp[6]) << 48;
        offset                          |= ((qx86_uint64) operand->u.m.disp[5]) << 40;
        offset                          |= ((qx86_uint64) operand->u.m.disp[4]) << 32;

        /* FTI.  */

    case QX86_DISP_32:
        /* Move bits 16..31.  */
        offset                          |= ((qx86_uint64) operand->u.m.disp[3]) << 24;
        offset                          |= ((qx86_uint64) operand->u.m.disp[2]) << 16;

        /* FTI.  */

    case QX86_DISP_16:
        /* Move bits 8..15.  */
        offset                          |= ((qx86_uint64) operand->u.m.disp[1]) << 8;

        /* FTI.  */

    case QX86_DISP_8:
        /* Move bits 0..7.  */
        offset                          |= (qx86_uint64) operand->u.m.disp[0];

        /* FTI.  */

    case QX86_DISP_NONE:
        /* Done.  */
        break;

    default:
        /* Invalid value.  */
        return QX86_E_INTERNAL;
    }

    /* Calculate offset: base.  */
    if (QX86_REGISTER_NONE != operand->u.m.bri)
    {
        /* Clear value before callback.  */
        value[0] = value[1] = value[2] = value[3] = 0;
        value[4] = value[5] = value[6] = value[7] = 0;

        /* Ask for base value.  */
        if (!insn->callback(insn->data, operand->u.m.bri, QX86_SUBREG_NONE, value)) return QX86_E_CALLBACK;

        /* Convert to an address.  */
        qx86_extract_address(value, address);

        /* RIP-relative addressing uses incremented RIP.  */
        if (QX86_REGISTER_RIP == operand->u.m.bri) *address += insn->rawSize;

        /* Add to offset.  */
        offset += *address;
    }

    /* Calculate offset: index.  Special case for AL register used as index in
       XLAT implicit operand.  */
    switch (operand->u.m.iri)
    {
    case QX86_REGISTER_NONE:
        /* Ignore.  */
        break;

    case QX86_REGISTER_AL:
        /* Ask for index value.  Don't clear value here because only the LSB
           is used.  */
        if (!insn->callback(insn->data, operand->u.m.iri, QX86_SUBREG_NONE, value)) return QX86_E_CALLBACK;

        /* Value is one unsigned octet.  Cannot be scaled.  */
        offset += value[0];

        /* Done.  */
        break;

    default:
        /* Clear value before callback.  */
        value[0] = value[1] = value[2] = value[3] = 0;
        value[4] = value[5] = value[6] = value[7] = 0;

        /* Ask for index value.  */
        if (!insn->callback(insn->data, operand->u.m.iri, QX86_SUBREG_NONE, value)) return QX86_E_CALLBACK;

        /* Convert to an address.  */
        qx86_extract_address(value, address);

        /* Scale and add to offset.  */
        offset += *address << operand->u.m.scale;

        /* Done.  */
        break;
    }

    /* Fetch address size, either from the instruction attributes or an override
       for implicit stack operands.  */
    if (operand->u.m.addressSizeOverride == QX86_SIZE_INVALID)
    {
        /* No override, use instruction attributes.  */
        addressSize = insn->attributes.addressSize;
    }
    else
    {
        /* Use provided override.  This path is only followed when constructing
           implicit (negative offset) operands from outside of quix86.  */
        addressSize = operand->u.m.addressSizeOverride;
    }

    /* Truncate to address size.  */
    switch (addressSize)
    {
    case QX86_SIZE_16:
        /* Truncate to 16 bits.  */
        offset &= 0xFFFFULL;
        
        /* Done.  */
        break;

    case QX86_SIZE_32:
        /* Truncate to 32 bits.  */
        offset &= 0xFFFFFFFFULL;

        /* Done.  */
        break;

    case QX86_SIZE_64:
        /* No truncation necessary.  */
        break;

    default:
        /* Invalid value.  */
        return QX86_E_INTERNAL;
    }

    /* Put offset into address.  */
    *address = offset;

    /* Success.  */
    return QX86_SUCCESS;
}
