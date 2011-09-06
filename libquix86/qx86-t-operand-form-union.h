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

#ifndef QX86_T_OPERAND_FORM_UNION_H
#define QX86_T_OPERAND_FORM_UNION_H

#include <qx86-t-operand-form-amode.h>
#include <qx86-t-operand-form-rtuple.h>

/**
 * Instruction operand form definition union.
 *
 * \author                              icee
 * \since                               1.0
 */
union qx86_operand_form_union
{
    const void *                        initializer[2];

    qx86_operand_form_amode             a;
    qx86_operand_form_rtuple            r;
};

#endif /* QX86_T_OPERAND_FORM_UNION_H */
