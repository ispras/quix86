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

#ifndef QX86_T_INSN_MODIFIERS_H
#define QX86_T_INSN_MODIFIERS_H

/**
 * Instruction modifiers definition structure.
 *
 * \author                              icee
 * \since                               1.0
 */
struct qx86_insn_modifiers
{
    qx86_uint8                          modrm;
    qx86_int8                           modrmIndex;

    qx86_uint8                          sib;
    qx86_int8                           sibIndex;

    qx86_uint8                          rex;
    qx86_int8                           rexIndex;

    qx86_uint8                          prefixSize;

    qx86_uint8                          escape;
    qx86_uint8                          opcodePrefix;

    /* XXX: values 0x00, 0xF2, 0xF3.  */
    qx86_uint8                          repeatPrefix;

    int                                 sriOverride;

    qx86_uint8                          extendedB;
    qx86_uint8                          extendedR;
    qx86_uint8                          extendedX;
};

#endif /* QX86_T_INSN_MODIFIERS_H */
