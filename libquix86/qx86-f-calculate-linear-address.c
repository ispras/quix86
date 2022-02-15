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
qx86_calculate_linear_address(QX86_CONST qx86_insn *insn, int operandIndex, qx86_uint64 *address)
{
    int                                 result;

    QX86_CONST qx86_operand *           operand;

    qx86_uint8                          value[32];

    qx86_uint64                         base;
    qx86_uint64                         offset;

    /* Get effective address.  */
    result = qx86_calculate_effective_address(insn, operandIndex, &offset);

    /* Test outcome.  */
    if (QX86_SUCCESS != result) return result;

    /* Get operand pointer.  */
    operand = insn->operands + operandIndex;

    /* Find out whether we need to ask for base.  */
    switch (operand->u.m.sri)
    {
    default:
        /* Bases different from FS or GS are fixed at 0 in 64-bit mode.  */
        if (QX86_SIZE_64 == (insn->processorMode & QX86_SIZE_MASK))
        {
            /* Null base.  */
            base = 0ULL;
            break;
        }

        /* Fallthrough.  */

    case QX86_REGISTER_FS:
    case QX86_REGISTER_GS:
        /* Clear value before callback.  */
        value[0] = value[1] = value[2] = value[3] = 0;
        value[4] = value[5] = value[6] = value[7] = 0;

        /* Ask for base value.  */
        if (!insn->callback(insn->data, operand->u.m.sri, QX86_SUBREG_BASE, value)) return QX86_E_CALLBACK;

        /* Convert to address.  */
        qx86_extract_address(value, &base);
        break;
    }

    /* Combine base and offset in address.  */
    *address = base + offset;

    /* Success.  */
    return QX86_SUCCESS;
}
