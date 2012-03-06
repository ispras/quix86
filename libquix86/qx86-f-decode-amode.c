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
qx86_decode_amode(qx86_insn *insn, int index)
{
    qx86_operand *                      operand;

    qx86_amode *                        amode;
    qx86_stuple *                       stuple;

    int                                 rclass;
    int                                 rindex;

    int                                 result;

    /* Get amode and stuple.  */
    amode                               = insn->operandForms[index]->u.a.amode;
    stuple                              = insn->operandForms[index]->u.a.stuple;

    /* Store effective operand size.  */
    operand                             = insn->operands + index;
    operand->size                       = stuple->sizes[insn->attributes.operandSize];

    /* Call decode function if present.  */
    if (amode->decodeFunc)
    {
        /* Test for special value.  */
        if (QX86_E_API != (result = amode->decodeFunc(insn, index))) return result;
    }

    /* Otherwise, default ModRM-based decode process.  */
    if (QX86_MODRM_FIELD_NONE == amode->modrmField) return QX86_E_INTERNAL;

    /* Get rclass.  */
    if (QX86_RCLASS_RESERVED_3 == amode->rclass)
    {
        /* Handle a special defect case.  */
        if (!operand->size)
        {
            /* Convert "i" to "v".  */
            stuple                  = &qx86_stuple_v;
            operand->size           = stuple->sizes[insn->attributes.operandSize];
        }

        /* This pseudo-class needs further evaluation via operand->size.  */
        switch (operand->size)
        {
        case 1:
            /* Map to REG8.  */
            rclass = QX86_RCLASS_REG8;
            break;

        case 2:
            /* Map to REG16.  */
            rclass = QX86_RCLASS_REG16;
            break;

        case 4:
            /* Map to REG32.  */
            rclass = QX86_RCLASS_REG32;
            break;

        case 8:
            /* Map to REG64.  */
            rclass = QX86_RCLASS_REG64;
            break;

        default:
            /* Invalid size; internal error.  */
            return QX86_E_INTERNAL;
        }

        /* Could have returned an invalid class.  */
        if (!rclass) return QX86_E_INTERNAL;
    }
    else
    {
        /* All other rclasses map to themself.  */
        rclass = amode->rclass;
    }

    /* Validate rclass.  */
    if (!qx86_modrm_rindex[rclass]) return QX86_E_INTERNAL;

    /* Decode ModRM.  */
    if (QX86_SUCCESS != (result = qx86_decode_modifiers(insn))) return result;

    /* A value of QX86_MODRM_FIELD_MOD requires special processing.  */
    if (QX86_MODRM_FIELD_MOD == amode->modrmField)
    {
        /* Have a look at mod field value.  */
        if (3 != QX86_MODRM_MOD(insn->modifiers.modrm))
        {
            /* Values other than 3 are for memory operands.  */
            if (QX86_E_API != (result = qx86_decode_amode_m(insn, index))) return result;
        }
    }

    /* Build rindex.  */
    switch (amode->modrmField)
    {
    case QX86_MODRM_FIELD_RM:
        /* Check that mod field contains 3.  */
        if (3 != QX86_MODRM_MOD(insn->modifiers.modrm))
        {
            /* A defect.  */
            insn->defects |= QX86_DEFECT_MODRM_MOD_NOT_3;
        }

        /* No break intended.  */

    case QX86_MODRM_FIELD_MOD:
        /* Use r/m and extendedB.  */
        rindex = insn->modifiers.extendedB << 3 | QX86_MODRM_RM(insn->modifiers.modrm);
        break;
    
    case QX86_MODRM_FIELD_REG:
        /* Use reg and extendedR.  */
        rindex = insn->modifiers.extendedR << 3 | QX86_MODRM_REG(insn->modifiers.modrm);
        break;

    default:
        /* Unexpected value; internal error.  */
        return QX86_E_INTERNAL;
    }

    /* Fetch rindex.  */
    rindex = qx86_modrm_rindex[rclass][rindex];

    /* Validate rindex.  */
    if (QX86_REGISTER_INVALID == rindex) return QX86_E_INTERNAL;

    /* Initialize operand.  */
    operand->ot                         = QX86_OPERAND_TYPE_REGISTER;
    operand->u.r.rindex                 = rindex;

    /* Success.  */
    return QX86_SUCCESS;
}
