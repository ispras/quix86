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

#ifndef QX86_E_OPCODE_MAP_INDEX_H
#define QX86_E_OPCODE_MAP_INDEX_H

/**
 * Enumeration of opcode map indexes.
 *
 * \author                              icee
 * \since                               1.0
 */
enum
{
    QX86_OPCODE_MAP_INDEX_NONE          = 0,

    QX86_OPCODE_MAP_INDEX_NB            = 1,
    QX86_OPCODE_MAP_INDEX_PB            = 2,

    QX86_OPCODE_MAP_INDEX_AS            = 3,
    QX86_OPCODE_MAP_INDEX_CS            = 4,
    QX86_OPCODE_MAP_INDEX_OS            = 5,

    QX86_OPCODE_MAP_INDEX_SP            = 6,

    QX86_OPCODE_MAP_INDEX_MOD           = 7,
    QX86_OPCODE_MAP_INDEX_REG           = 8,
    QX86_OPCODE_MAP_INDEX_RM            = 9,

    QX86_OPCODE_MAP_INDEX_COUNT         = 10
};

#endif /* QX86_E_OPCODE_MAP_INDEX_H */
