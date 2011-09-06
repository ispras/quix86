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

static int
qx86_decode_modifiers(qx86_insn *insn)
{
    int                                 result;

    /* We could have decoded modifiers earlier, in which case we are done.  */
    if (insn->modifiers.modrmIndex >= 0) return QX86_SUCCESS;

    /* Fetch ModRM.  */
    result = qx86_pump(insn, &insn->modifiers.modrm, 1);

    /* Test if successful.  */
    if (QX86_SUCCESS != result) return result;

    /* Store ModRM index.  */
    insn->modifiers.modrmIndex = insn->rawSize - 1;

    /* 16-bit addresses don't allow SIB.  */
    if (QX86_SIZE_16 != insn->attributes.addressSize)
    {
        /* ModRM r/m field must contain 4 for SIB to be present.  */
        if (4 == QX86_MODRM_RM(insn->modifiers.modrm))
        {
            /* ModRM mod field must not contain 3 for SIB to be present.  */
            if (3 != QX86_MODRM_MOD(insn->modifiers.modrm))
            {
                /* SIB is present.  */
                result = qx86_pump(insn, &insn->modifiers.sib, 1);

                /* Test if successful.  */
                if (QX86_SUCCESS != result) return result;

                /* Store SIB index.  */
                insn->modifiers.sibIndex = insn->rawSize - 1;
            }
        }
    }

    /* Success.  */
    return QX86_SUCCESS;
}
