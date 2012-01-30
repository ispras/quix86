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

static int
qx86_decode_prefixes(qx86_insn *insn)
{
    /* TODO: I will rewrite this all.  */

    qx86_uint8                          nb;

    int                                 aso;
    int                                 oso;
    
    int                                 result;

    /* Initialize modifiers: indexes.  */
    insn->modifiers.modrmIndex          = -1;
    insn->modifiers.sibIndex            = -1;
    insn->modifiers.rexIndex            = -1;

    /* Initialize modifiers: defaults.  */
    insn->modifiers.escape              = QX86_OPCODE_ESCAPE_NONE;
    insn->modifiers.opcodePrefix        = 0; /* XXX enum needed */
    insn->modifiers.sriOverride         = QX86_REGISTER_NONE;
    insn->modifiers.repeatPrefix        = 0; /* XXX enum needed.  */

    /* Initialize attributes.  */
    insn->attributes.interlocked        = 0;

    /* Initialize locals.  */
    aso                                 = 0;
    oso                                 = 0;

    /* Loop fetching octets.  */
    for (insn->modifiers.prefixSize = 0; /* ILB */; ++insn->modifiers.prefixSize)
    {
        /* Pump an octet.  */
        result = qx86_pump(insn, &nb, 1);

        /* Test result.  */
        if (QX86_SUCCESS != result) return result;

        /* Look for prefixes.  */
        switch (nb)
        {
        case 0x26:
            /* ES override.  */
            insn->modifiers.sriOverride = QX86_REGISTER_ES;
            continue;

        case 0x2E:
            /* CS override.  */
            insn->modifiers.sriOverride = QX86_REGISTER_CS;
            continue;

        case 0x36:
            /* SS override.  */
            insn->modifiers.sriOverride = QX86_REGISTER_SS;
            continue;

        case 0x3E:
            /* DS override.  */
            insn->modifiers.sriOverride = QX86_REGISTER_DS;
            continue;

        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4A:
        case 0x4B:
        case 0x4C:
        case 0x4D:
        case 0x4E:
        case 0x4F:
            /* REX.  Only in 64-bit mode.  */
            if (QX86_SIZE_64 == (insn->processorMode & QX86_SIZE_MASK))
            {
                /* A prefix.  */
                insn->modifiers.rexIndex = insn->modifiers.prefixSize;
                insn->modifiers.rex = nb;

                /* Continue.  */
                continue;
            }
            else
            {
                /* Not a prefix.  */
                break;
            }

        case 0x64:
            /* FS override.  */
            insn->modifiers.sriOverride = QX86_REGISTER_FS;
            continue;

        case 0x65:
            /* GS override.  */
            insn->modifiers.sriOverride = QX86_REGISTER_GS;
            continue;

        case 0x66:
            /* Operand size override and opcode extension.  */
            oso = 1; insn->modifiers.opcodePrefix = 1;
            continue;

        case 0x67:
            /* Address size override.  */
            aso = 1;
            continue;

        case 0xF0:
            /* LOCK.  Ignored for now.  XXX.  */
            insn->attributes.interlocked = 1;
            continue;

        case 0xF2:
            /* REPNZ.  Ignored for now.  XXX.  */
            insn->modifiers.opcodePrefix = 2;
            insn->modifiers.repeatPrefix = 0xF2;
            continue;

        case 0xF3:
            /* REP/REPZ.  Ignored for now.  XXX.  */
            insn->modifiers.opcodePrefix = 3;
            insn->modifiers.repeatPrefix = 0xF3;
            continue;

        default:
            /* No other prefixes.  */
            break;
        }

        /* We have eaten an extra octet.  */
        result = qx86_unpump(insn);

        /* Test outcome.  */
        if (QX86_SUCCESS != result) return result;

        /* Done.  */
        break;
    }

    /* oso can also get a value of 2.  */
    if (insn->modifiers.rexIndex >= 0)
    {
        /* Get the w field.  */
        if (QX86_REX_W(insn->modifiers.rex)) oso = 2;
    }

    /* Define effective address and operand sizes.  XXX.  */
    insn->attributes.addressSize        = (qx86_uint8) qx86_address_size[insn->processorMode & QX86_SIZE_MASK][aso];
    insn->attributes.addressSizeOverridden
                                        = 0 != aso;
    insn->attributes.operandSize        = (qx86_uint8) qx86_operand_size[insn->processorMode & QX86_SIZE_MASK][oso];
    insn->attributes.operandSizeOverridden
                                        = 0 != oso;

    /* Define REX stuff.  XXX.  */
    if (insn->modifiers.rexIndex >= 0)
    {
        /* Yes extensions.  */
        insn->modifiers.extendedB       = 2 | QX86_REX_B(insn->modifiers.rex);
        insn->modifiers.extendedR       = 2 | QX86_REX_R(insn->modifiers.rex);
        insn->modifiers.extendedX       = 2 | QX86_REX_X(insn->modifiers.rex);
    }
    else
    {
        /* No extensions.  */
        insn->modifiers.extendedB       = 0;
        insn->modifiers.extendedR       = 0;
        insn->modifiers.extendedX       = 0;
    }

    /* Success.  */
    return QX86_SUCCESS;
}
