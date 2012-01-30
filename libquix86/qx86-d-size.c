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

/* Reference: AMD Architecture Programmer's Manual 3: Table 1-3.  */
static int                              qx86_address_size_16[2]
                                        =
{
    QX86_SIZE_16,                       QX86_SIZE_32
};

/* Reference: AMD Architecture Programmer's Manual 3: Table 1-3.  */
static int                              qx86_address_size_32[2]
                                        =
{
    QX86_SIZE_32,                       QX86_SIZE_16
};

/* Reference: AMD Architecture Programmer's Manual 3: Table 1-3.  */
static int                              qx86_address_size_64[2]
                                        =
{
    QX86_SIZE_64,                       QX86_SIZE_32
};

/* Reference: AMD Architecture Programmer's Manual 3: Table 1-3.  */
static int *                            qx86_address_size[4]
                                        =
{
    qx86_address_size_16,               qx86_address_size_32,
    qx86_address_size_64,               0
};

/* Reference: AMD Architecture Programmer's Manual 3: Table 1-2.  */
static int                              qx86_operand_size_16[4]
                                        =
{
    QX86_SIZE_16,                       QX86_SIZE_32,
    QX86_SIZE_INVALID,                  QX86_SIZE_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table 1-2.  */
static int                              qx86_operand_size_32[4]
                                        =
{
    QX86_SIZE_32,                       QX86_SIZE_16,
    QX86_SIZE_INVALID,                  QX86_SIZE_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table 1-2.  */
static int                              qx86_operand_size_64[4]
                                        =
{
    QX86_SIZE_32,                       QX86_SIZE_16,
    QX86_SIZE_64,                       QX86_SIZE_64
};

/* Reference: AMD Architecture Programmer's Manual 3: Table 1-2.  */
static int  *                           qx86_operand_size[4]
                                        =
{
    qx86_operand_size_16,               qx86_operand_size_32,
    qx86_operand_size_64,               0
};
