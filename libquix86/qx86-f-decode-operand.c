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
qx86_decode_operand(qx86_insn *insn, int index)
{
    /* Copy operand attributes.  */
    insn->operands[index].attributes = insn->operandForms[index]->attributes;

    /* Call appropriate functions.  */
    switch (insn->operandForms[index]->ft)
    {
    case QX86_OPERAND_FORM_TYPE_AMODE:
        /* Decode amode operand.  */
        return qx86_decode_amode(insn, index);

    case QX86_OPERAND_FORM_TYPE_IMPLICIT_1:
        /* Decode implicit 1 operand.  */
        return qx86_decode_implicit_1(insn, index);

    case QX86_OPERAND_FORM_TYPE_RTUPLE:
        /* Decode rtuple operand.  */
        return qx86_decode_rtuple(insn, index);

    default:
        /* Invalid ft value; internal error.  */
        return QX86_E_INTERNAL;
    }
}
