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
   | under the terms of the GNU General Public License as published by the  |
   | Free Software Foundation, either version 3 of the License, or (at your |
   | option) any later version.                                             |
   |                                                                        |
   | quix86 is distributed in the hope that it will be useful, but WITHOUT  |
   | ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  |
   | FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License  |
   | for more details.                                                      |
   |                                                                        |
   | You should have received a copy of the GNU General Public License      |
   | along with quix86.  If not, see <http://www.gnu.org/licenses/>.        |
   +------------------------------------------------------------------------+ */

static int
qx86_decode_amode_a(qx86_insn *insn, int index)
{
    qx86_operand *                      operand;

    int                                 result;

    /* Initialize operand.  */
    operand                             = insn->operands + index;
    operand->ot                         = QX86_OPERAND_TYPE_FAR_POINTER;

    /* Operand size determines whether 16-bit or 32-bit offset is used.  */
    switch (insn->attributes.operandSize)
    {
    case QX86_SIZE_16:
        /* 16-bit offset and 16-bit selector.  */
        operand->size                   = 4;
        operand->u.f.offsetSize         = 2;

        /* Continued below.  */
        break;

    case QX86_SIZE_32:
        /* 32-bit offset and 16-bit selector.  */
        operand->size                   = 6;
        operand->u.f.offsetSize         = 4;

        /* Continued below.  */
        break;

    default:
        /* Invalid in 64-bit mode; unreachable.  */
        return QX86_E_INTERNAL;
    }

    /* Pump offset octets.  */
    if (QX86_SUCCESS != (result = qx86_pump(insn, operand->u.f.offset, operand->u.f.offsetSize)))
    {
        /* Bail out.  */
        return result;
    }

    /* Pump selector octets.  */
    return qx86_pump(insn, operand->u.f.selector, sizeof(operand->u.f.selector));
}
