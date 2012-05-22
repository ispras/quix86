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

#ifndef QX86_F_EXTRACT_ADDRESS_INL
#define QX86_F_EXTRACT_ADDRESS_INL

QX86_INLINE static int
qx86_extract_address(qx86_uint8 *octets, qx86_uint64 *address)
{
#   ifdef QUIX86_BIG_ENDIAN
    {
        /* Big endian.  Compiler will optimize this, I believe.  */
        ((qx86_octet *) address)[0] = octets[7];
        ((qx86_octet *) address)[1] = octets[6];
        ((qx86_octet *) address)[2] = octets[5];
        ((qx86_octet *) address)[3] = octets[4];
        ((qx86_octet *) address)[4] = octets[3];
        ((qx86_octet *) address)[5] = octets[2];
        ((qx86_octet *) address)[6] = octets[1];
        ((qx86_octet *) address)[7] = octets[0];
    }
#   else
    {
        /* Little endian.  Use one move.  */
        *address = *((qx86_uint64 *) octets);
    }
#   endif

    /* Success.  */
    return QX86_SUCCESS;
}

#endif /* QX86_F_EXTRACT_ADDRESS_INL */
