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
qx86_decode_amode_i(qx86_insn *insn, int index)
{
    qx86_operand *                      operand;

    /* Initialize operand.  XXX */
    operand                             = insn->operands + index;
    operand->ot                         = QX86_OPERAND_TYPE_IMMEDIATE;
    operand->u.i.valueSize              = (qx86_uint8) operand->size;

    /* Operand size has been recorded before.  */
    switch (operand->size)
    {
    case 1:
    case 2:
    case 4:
    case 8:
        /* Good operand size.  */
        return qx86_pump(insn, operand->u.i.value, operand->size);

    default:
        /* Invalid operand size; internal error.  */
        return QX86_E_INTERNAL;
    }
}
