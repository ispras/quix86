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

#ifndef QX86_T_INSN_H
#define QX86_T_INSN_H

#include <qx86-t-callback.h>
#include <qx86-t-insn-attributes.h>
#include <qx86-t-insn-modifiers.h>
#include <qx86-t-operand.h>

/**
 * Instruction definition structure.
 *
 * \author                              icee
 * \since                               1.0
 */
struct qx86_insn
{
    qx86_uint8                          rawSize;
    qx86_uint8                          raw[QX86_INSN_SIZE_MAX];

    int                                 processorMode;

    int                                 mnemonic;
    qx86_int8                           operandCount;

    qx86_operand                        operands[QX86_OPERAND_NMAX];
    qx86_operand_form *                 operandForms[QX86_OPERAND_NMAX];

    qx86_insn_attributes                attributes;
    qx86_insn_modifiers                 modifiers;

    qx86_uint8                          iclass;
    qx86_uint8                          defects;

    qx86_callback                       callback;
    void *                              data;
};

#endif /* QX86_T_INSN_H */
