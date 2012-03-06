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

#ifndef QX86_E_CC_H
#define QX86_E_CC_H

/**
 * Enumeration of <em>x86</em> condition codes.
 *
 * \author                              icee
 * \since                               1.0
 */
enum
{
    QX86_CC_O                           = 0,
    QX86_CC_NO                          = 1,
    QX86_CC_B                           = 2,
    QX86_CC_AE                          = 3,
    QX86_CC_Z                           = 4,
    QX86_CC_NZ                          = 5,
    QX86_CC_BE                          = 6,
    QX86_CC_A                           = 7,
    QX86_CC_S                           = 8,
    QX86_CC_NS                          = 9,
    QX86_CC_P                           = 10,
    QX86_CC_NP                          = 11,
    QX86_CC_L                           = 12,
    QX86_CC_GE                          = 13,
    QX86_CC_LE                          = 14,
    QX86_CC_G                           = 15,
    
    QX86_CC_NONE                        = 16,

    QX86_CC_CXZ                         = 17,
    QX86_CC_ECXZ                        = 18,
    QX86_CC_RCXZ                        = 19,
    QX86_CC_CXO                         = 20,
    QX86_CC_ECXO                        = 21,
    QX86_CC_RCXO                        = 22
};

#endif /* QX86_E_CC_H */
