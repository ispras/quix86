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

    int                                 i;
    int                                 result;

    /* Initialize operand.  */
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
        /* Good operand size.  Fetch immediate.  */
        if (QX86_SUCCESS != (result = qx86_pump(insn, operand->u.i.value, operand->size)))
        {
            /* Bail out.  */
            return result;
        }

        /* See if sign extension is in effect.  */
        if (&qx86_amode_F == insn->operandForms[index]->u.a.amode)
        {
            /* Extended size is taken from operand size attribute.  */
            operand->u.i.extendedSize = (qx86_uint8) (2 << insn->attributes.operandSize);
        }
        else
        {
            /* Extended size is same as normal encoded size.  */
            operand->u.i.extendedSize = operand->u.i.valueSize;
        }

        /* Iterate octets.  */
        for (i = 0; i < operand->u.i.extendedSize; ++i)
        {
            /* See if we have that actual octet.  */
            if (i < operand->u.i.valueSize)
            {
                /* Yes.  Copy.  */
                operand->u.i.extended[i] = operand->u.i.value[i]; 
            }
            else
            {
                /* No.  Sign-extend previous octet.  */
                operand->u.i.extended[i] = (operand->u.i.value[i - 1] & 0x80) ? 0xFF : 0x00;
            }
        }

        /* Done.  */
        return QX86_SUCCESS;

    default:
        /* Invalid operand size; internal error.  */
        return QX86_E_INTERNAL;
    }
}
