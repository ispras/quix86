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

#ifndef QX86_F_PUMP_INL
#define QX86_F_PUMP_INL

QX86_INLINE static int
qx86_pump(qx86_insn *insn, qx86_uint8 *octets, int size)
{
    /* Make sure we have at least size octets left.  */
    if (((qx86_ctx *) insn->data)->ptrSize >= size)
    {
        /* Copy octets.  Can't use memcpy() here because some compilers would
           emit an actual call instead of an intrinsic.  */
        for (((qx86_ctx *) insn->data)->ptrSize -= size; size; --size)
        {
            /* Copy one octet.  */
            insn->raw[insn->rawSize++] = *octets++ = *(((qx86_ctx *) insn->data)->ptr++);
        }

        /* Success.  */
        return QX86_SUCCESS;
    }
    else
    {
        /* Incomplete instruction.  */
        return QX86_E_INSN_INCOMPLETE;
    }
}

#endif /* QX86_F_PUMP_INL */
