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
qx86_decode_amode_m(qx86_insn *insn, int index)
{
    qx86_operand *                      operand;

    qx86_uint8                          modrm;
    qx86_uint8                          sib;

    int                                 b;
    int                                 bmask;

    int                                 x;
    int                                 xmask;

    int                                 p;
    int                                 q;

    int                                 result;

    /* Decode ModRM and, if present, SIB.  */
    result = qx86_decode_modifiers(insn);

    /* Bail out on error.  */
    if (QX86_SUCCESS != result) return result;

    /* Get modrm and sib.  */
    modrm                               = insn->modifiers.modrm;
    sib                                 = insn->modifiers.sib;

    /* Check mod field not to contain 11b.  */
    if (3 == QX86_MODRM_MOD(modrm))
    {
        /* Detected a defect.  */
        insn->defects |= QX86_DEFECT_MODRM_MOD_3;

        /* Return a special value.  */
        return QX86_E_API;
    }

    /* Calculate b, x, bmask and xmask.  */
    b                                   = 1 & insn->modifiers.extendedB;
    bmask                               = b << 3;
    x                                   = 1 & insn->modifiers.extendedX;
    xmask                               = x << 3;

    /* Calculate p and q.  */
    p                                   = insn->attributes.addressSize;
    q                                   = (QX86_MODRM_MOD(modrm) << 4) | QX86_MODRM_RM(modrm);

    /* Initialize operand.  */
    operand                             = insn->operands + index;
    operand->ot                         = QX86_OPERAND_TYPE_MEMORY;
    operand->u.m.dispSize               = (qx86_uint8) qx86_modrm_disp[p][q | bmask];

    /* All other attributes can come from either ModRM or SIB.  */
    if (insn->modifiers.sibIndex >= 0)
    {
        /* Use SIB.  */
        operand->u.m.bri                = qx86_sib_base[p][QX86_SIB_BASE(sib) | bmask];
        operand->u.m.iri                = qx86_sib_index[p][QX86_SIB_INDEX(sib) | xmask];
        operand->u.m.scale              = QX86_SIB_SCALE(sib);

        /* Handle the special /5 case.  */
        if (QX86_REGISTER_SPECIAL == operand->u.m.bri)
        {
            /* Load new base.  */
            operand->u.m.bri = qx86_sib_base_special[p][QX86_MODRM_MOD(modrm) | bmask];

            /* Add displacement for zero mod case.  */
            if (!QX86_MODRM_MOD(modrm)) operand->u.m.dispSize = QX86_DISP_32;
        }
    }
    else
    {
        /* Use ModRM.  */
        operand->u.m.bri                = qx86_modrm_base[p][q | bmask];
        operand->u.m.iri                = qx86_modrm_index[p][q | bmask];
        operand->u.m.scale              = qx86_modrm_scale[p][q | bmask];
        
        /* Handle rIP case.  */
        if (QX86_RCLASS_IP == qx86_rtab[operand->u.m.bri].rclass)
        {
            /* Downgrade to no base in 16-bit and 32-bit modes.  */
            if (QX86_SIZE_64 != (insn->processorMode & QX86_SIZE_MASK))
            {
                /* No base.  */
                operand->u.m.bri = QX86_REGISTER_NONE;
            }
        }
    }

    /* Handle bases that default to stack addressing.  */
    switch (operand->u.m.bri)
    {
    case QX86_REGISTER_SP:
    case QX86_REGISTER_BP:
    case QX86_REGISTER_ESP:
    case QX86_REGISTER_EBP:
    case QX86_REGISTER_RSP:
    case QX86_REGISTER_RBP:
        /* Use SS.  */
        operand->u.m.sri                = QX86_REGISTER_SS;
        break;

    default:
        /* Use DS.  */
        operand->u.m.sri                = QX86_REGISTER_DS;
        break;
    
    case QX86_REGISTER_INVALID:
    case QX86_REGISTER_SPECIAL:
        /* Internal error.  */
        return QX86_E_INTERNAL;
    }

    /* Handle DS/SS override.  */
    if (QX86_REGISTER_NONE != insn->modifiers.sriOverride) operand->u.m.sri = insn->modifiers.sriOverride;

    /* Pump displacement.  */
    return qx86_pump(insn, operand->u.m.disp, operand->u.m.dispSize);
}
