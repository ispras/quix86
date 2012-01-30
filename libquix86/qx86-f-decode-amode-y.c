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
qx86_decode_amode_y(qx86_insn *insn, int index)
{
    qx86_operand *                      operand;

    /* Initialize operand.  */
    operand                             = insn->operands + index;
    operand->ot                         = QX86_OPERAND_TYPE_MEMORY;
    operand->u.m.sri                    = QX86_REGISTER_ES;
    operand->u.m.bri                    = 0;
    operand->u.m.iri                    = qx86_rtuple_rDI.rindexes[insn->attributes.addressSize << 2];
    operand->u.m.scale                  = 0;
    operand->u.m.dispSize               = 0;

    /* Success.  */
    return QX86_SUCCESS;
}
