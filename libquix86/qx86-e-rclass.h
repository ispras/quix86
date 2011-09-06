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

#ifndef QX86_E_RCLASS_H
#define QX86_E_RCLASS_H

/**
 * Enumeration of <em>x86</em> register classes.
 *
 * \author                              icee
 * \since                               1.0
 */
enum
{
    QX86_RCLASS_NONE                    = 0,
    QX86_RCLASS_IP                      = 1,
    QX86_RCLASS_FLAGS                   = 2,
    QX86_RCLASS_RESERVED_3              = 3,

    QX86_RCLASS_REG8                    = 4,
    QX86_RCLASS_REG16                   = 5,
    QX86_RCLASS_REG32                   = 6,
    QX86_RCLASS_REG64                   = 7,

    QX86_RCLASS_CREG                    = 8,
    QX86_RCLASS_DREG                    = 9,
    QX86_RCLASS_SREG                    = 10,
    QX86_RCLASS_RESERVED_11             = 11,

    QX86_RCLASS_X87                     = 12,
    QX86_RCLASS_MMX                     = 13,
    QX86_RCLASS_XMM                     = 14,
    QX86_RCLASS_YMM                     = 15,

    QX86_RCLASS_COUNT                   = 16
};

#endif /* QX86_E_RCLASS_H */
