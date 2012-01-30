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

#ifndef QX86_T_OPERAND_UNION_H
#define QX86_T_OPERAND_UNION_H

#include <qx86-t-operand-far-pointer.h>
#include <qx86-t-operand-immediate.h>
#include <qx86-t-operand-jump-offset.h>
#include <qx86-t-operand-memory.h>
#include <qx86-t-operand-register.h>

/**
 * Instruction operand definition union.
 *
 * \author                              icee
 * \since                               1.0
 */
union qx86_operand_union
{
    qx86_operand_far_pointer            f;
    qx86_operand_immediate              i;
    qx86_operand_jump_offset            j;
    qx86_operand_memory                 m;
    qx86_operand_register               r;
};

#endif /* QX86_T_OPERAND_UNION_H */
