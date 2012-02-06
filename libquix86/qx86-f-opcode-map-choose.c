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
qx86_opcode_map_choose(qx86_insn *insn, qx86_opcode_map *map, qx86_opcode_map_item **item)
{
    qx86_uint8                          index;

    int                                 result;

    /* Switch index.  */
    switch (map->index)
    {
    case QX86_OPCODE_MAP_INDEX_NB:
        /* Pump an octet.  */
        result = qx86_pump(insn, &index, 1);

        /* Bail out on error.  */
        if (QX86_SUCCESS != result) return result;

        /* Store pumpIndex.  */
        ((qx86_ctx *) insn->data)->pumpIndex = insn->rawSize - 1;

        /* Done.  */
        break;

    case QX86_OPCODE_MAP_INDEX_PB:
        /* See if we have decoded an opcode octet before.  */
        if (((qx86_ctx *) insn->data)->pumpIndex >= 0)
        {
            /* Yes.  Get it.  */
            index = insn->raw[((qx86_ctx *) insn->data)->pumpIndex];
        }
        else
        {
            /* No.  Internal error.  */
            return QX86_E_INTERNAL;
        }

        /* Done.  */
        break;

    case QX86_OPCODE_MAP_INDEX_AS:
        /* Effective address size, an attribute.  */
        index = insn->attributes.addressSize;
        break;

    case QX86_OPCODE_MAP_INDEX_CS:
        /* Code size.  */
        index = insn->processorMode & QX86_SIZE_MASK;
        break;

    case QX86_OPCODE_MAP_INDEX_OS:
        /* Effective operand size, an attribute.  */
        index = insn->attributes.operandSize;
        break;

    case QX86_OPCODE_MAP_INDEX_SP:
        /* Opcode extension (SIMD) prefix, a modifier.  */
        index = insn->modifiers.opcodePrefix;
        break;

    case QX86_OPCODE_MAP_INDEX_MOD:
    case QX86_OPCODE_MAP_INDEX_REG:
    case QX86_OPCODE_MAP_INDEX_RM:
        /* Decode ModRM.  */
        result = qx86_decode_modifiers(insn);

        /* Bail out on error.  */
        if (QX86_SUCCESS != result) return result;

        /* Switch once more.  */
        switch (map->index)
        {
        case QX86_OPCODE_MAP_INDEX_MOD:
            /* Get mod field value.  */
            index = QX86_MODRM_MOD(insn->modifiers.modrm);
            break;

        case QX86_OPCODE_MAP_INDEX_REG:
            /* Get reg field value.  */
            index = QX86_MODRM_REG(insn->modifiers.modrm);
            break;

        case QX86_OPCODE_MAP_INDEX_RM:
            /* Get r/m field value.  */
            index = QX86_MODRM_RM(insn->modifiers.modrm);
            break;

        default:
            /* Silence compiler complaints.  */
            index = 0;
            break;
        }

        /* Done.  */
        break;

    default:
        /* Bad index value; internal error.  */
        return QX86_E_INTERNAL;
    }

    /* Validate chosen index.  */
    if (index > map->limit) return QX86_E_INTERNAL;

    /* Pick item.  */
    *item = map->items + index;

    /* Success.  */
    return QX86_SUCCESS;
}
