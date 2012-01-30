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
qx86_decode_opcode(qx86_insn *insn)
{
    qx86_opcode_map *                   map;
    qx86_opcode_map_item *              item;

    int                                 result;

    /* Initialize instruction operand count.  */
    insn->operandCount = -1;

    /* Loop around maps.  */
    for (map = qx86_opcode_maps[insn->modifiers.escape]; /* ILB */; map = item->link)
    {
        /* Choose item.  */
        result = qx86_opcode_map_choose(insn, map, &item);

        /* Bail out on error.  */
        if (QX86_SUCCESS != result) return result;

        /* Move in operand forms.  */
        if (item->operandCount >= 0)
        {
            /* No operand must have been defined before.  */
            if (insn->operandCount < 0)
            {
                /* Move loop.  */
                while (++insn->operandCount < item->operandCount)
                {
                    /* Move one operand form pointer.  */
                    insn->operandForms[insn->operandCount] = item->operandForms + insn->operandCount;
                }
            }
            else
            {
                /* Internal error.  Maps are messed up.  */
                return QX86_E_INTERNAL;
            }
        }

        /* Perform required action.  */
        switch (item->code)
        {
        case QX86_OPCODE_MAP_ITEM_CODE_NONE:
            /* Undefined opcode.  Decode process stops.  */
            return QX86_E_INSN_UNDEFINED;

        case QX86_OPCODE_MAP_ITEM_CODE_LINK:
            /* Proceed to next map.  */
            continue;

        case QX86_OPCODE_MAP_ITEM_CODE_PREFIX:
            /* Prefixes must have been parsed before.  */
            return QX86_E_INTERNAL;

        default:
            /* Be paranoid.  */
            if (item->code <= 0) return QX86_E_INTERNAL;
            if (item->code >= QX86_MNEMONIC_COUNT) return QX86_E_INTERNAL;

            /* Store the mnemonic.  */
            insn->mnemonic = item->code;

            /* Done.  */
            break;
        }

        /* Exit the loop.  */
        break;
    }

    /* Test that we have defined the operands.  */
    if (insn->operandCount < 0) return QX86_E_INTERNAL;

    /* Success.  */
    return QX86_SUCCESS;
}
