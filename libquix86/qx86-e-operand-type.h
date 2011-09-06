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

#ifndef QX86_E_OPERAND_TYPE_H
#define QX86_E_OPERAND_TYPE_H

/**
 * Enumeration of <em>x86</em> operand types.
 *
 * \author                              icee
 * \since                               1.0
 */
enum
{
    QX86_OPERAND_TYPE_NONE              = 0,

    QX86_OPERAND_TYPE_FAR_POINTER       = 1,
    QX86_OPERAND_TYPE_IMMEDIATE         = 2,
    QX86_OPERAND_TYPE_JUMP_OFFSET       = 3,
    QX86_OPERAND_TYPE_MEMORY            = 4,
    QX86_OPERAND_TYPE_REGISTER          = 5,

    QX86_OPERAND_TYPE_COUNT             = 6
};

#endif /* QX86_E_OPERAND_TYPE_H */
