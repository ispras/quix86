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

/* Reference: AMD Architecture Programmer's Manual 3: Table A-16.  */
static int                              qx86_sib_base_32[16]
                                        =
{
    QX86_REGISTER_EAX,                  QX86_REGISTER_ECX,
    QX86_REGISTER_EDX,                  QX86_REGISTER_EBX,
    QX86_REGISTER_ESP,                  QX86_REGISTER_SPECIAL,
    QX86_REGISTER_ESI,                  QX86_REGISTER_EDI,

    QX86_REGISTER_R8D,                  QX86_REGISTER_R9D,
    QX86_REGISTER_R10D,                 QX86_REGISTER_R11D,
    QX86_REGISTER_R12D,                 QX86_REGISTER_SPECIAL,
    QX86_REGISTER_R14D,                 QX86_REGISTER_R15D
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-16.  */
static int                              qx86_sib_base_64[16]
                                        =
{
    QX86_REGISTER_RAX,                  QX86_REGISTER_RCX,
    QX86_REGISTER_RDX,                  QX86_REGISTER_RBX,
    QX86_REGISTER_RSP,                  QX86_REGISTER_SPECIAL,
    QX86_REGISTER_RSI,                  QX86_REGISTER_RDI,

    QX86_REGISTER_R8,                   QX86_REGISTER_R9,
    QX86_REGISTER_R10,                  QX86_REGISTER_R11,
    QX86_REGISTER_R12,                  QX86_REGISTER_SPECIAL,
    QX86_REGISTER_R14,                  QX86_REGISTER_R15
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-16.  */
static int *                            qx86_sib_base[4]
                                        =
{
    0,                                  qx86_sib_base_32,
    qx86_sib_base_64,                   0
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-16.  */
static int                              qx86_sib_base_special_32[8]
                                        =
{
    QX86_REGISTER_NONE,                 QX86_REGISTER_EBP,
    QX86_REGISTER_EBP,                  QX86_REGISTER_INVALID,

    QX86_REGISTER_NONE,                 QX86_REGISTER_R13D,
    QX86_REGISTER_R13D,                 QX86_REGISTER_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-16.  */
static int                              qx86_sib_base_special_64[8]
                                        =
{
    QX86_REGISTER_NONE,                 QX86_REGISTER_RBP,
    QX86_REGISTER_RBP,                  QX86_REGISTER_INVALID,

    QX86_REGISTER_NONE,                 QX86_REGISTER_R13,
    QX86_REGISTER_R13,                  QX86_REGISTER_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-16.  */
static int *                            qx86_sib_base_special[4]
                                        =
{
    0,                                  qx86_sib_base_special_32,
    qx86_sib_base_special_64,           0
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-17.  */
static int                              qx86_sib_index_32[16]
                                        =
{
    QX86_REGISTER_EAX,                  QX86_REGISTER_ECX,
    QX86_REGISTER_EDX,                  QX86_REGISTER_EBX,
    QX86_REGISTER_NONE,                 QX86_REGISTER_EBP,
    QX86_REGISTER_ESI,                  QX86_REGISTER_EDI,

    QX86_REGISTER_R8D,                  QX86_REGISTER_R9D,
    QX86_REGISTER_R10D,                 QX86_REGISTER_R11D,
    QX86_REGISTER_R12D,                 QX86_REGISTER_R13D,
    QX86_REGISTER_R14D,                 QX86_REGISTER_R15D
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-17.  */
static int                              qx86_sib_index_64[16]
                                        =
{
    QX86_REGISTER_RAX,                  QX86_REGISTER_RCX,
    QX86_REGISTER_RDX,                  QX86_REGISTER_RBX,
    QX86_REGISTER_NONE,                 QX86_REGISTER_EBP,
    QX86_REGISTER_RSI,                  QX86_REGISTER_RDI,

    QX86_REGISTER_R8,                   QX86_REGISTER_R9,
    QX86_REGISTER_R10,                  QX86_REGISTER_R11,
    QX86_REGISTER_R12,                  QX86_REGISTER_R13,
    QX86_REGISTER_R14,                  QX86_REGISTER_R15
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-17.  */
static int *                            qx86_sib_index[4]
                                        =
{
    0,                                  qx86_sib_index_32,
    qx86_sib_index_64,                  0
};
