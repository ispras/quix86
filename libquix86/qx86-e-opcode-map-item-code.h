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

#ifndef QX86_E_OPCODE_MAP_ITEM_CODE_H
#define QX86_E_OPCODE_MAP_ITEM_CODE_H

/**
 * Enumeration of opcode map item codes.
 *
 * \author                              icee
 * \since                               1.0
 */
enum
{
    QX86_OPCODE_MAP_ITEM_CODE_NONE      = -0,
    QX86_OPCODE_MAP_ITEM_CODE_LINK      = -1,
    QX86_OPCODE_MAP_ITEM_CODE_PREFIX    = -2
};

#endif /* QX86_E_OPCODE_MAP_ITEM_CODE_H */
