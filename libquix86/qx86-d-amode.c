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

/* Reference: see JMPF.  */
static qx86_amode                       qx86_amode_A
                                        =
{
    "A",                                "A",
    QX86_MODRM_FIELD_NONE,              QX86_RCLASS_NONE,
    qx86_decode_amode_a
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_C
                                        =
{
    "C",                                "C",
    QX86_MODRM_FIELD_REG,               QX86_RCLASS_CREG,
    0
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_D
                                        =
{
    "D",                                "D",
    QX86_MODRM_FIELD_REG,               QX86_RCLASS_DREG,
    0
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_E
                                        =
{
    "E",                                "E",
    QX86_MODRM_FIELD_MOD,               QX86_RCLASS_RESERVED_3,
    0
};

/* Reference: none.  This is not the rFLAGS amode!  Instead, we use this amode
   for sign-extended immediate operands in PUSH, IMUL and group M1.  */
static qx86_amode                       qx86_amode_F
                                        =
{
    "F",                                "F",
    QX86_MODRM_FIELD_NONE,              QX86_RCLASS_NONE,
    qx86_decode_amode_i
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_G
                                        =
{
    "G",                                "G",
    QX86_MODRM_FIELD_REG,               QX86_RCLASS_RESERVED_3,
    0
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_I
                                        =
{
    "I",                                "I",
    QX86_MODRM_FIELD_NONE,              QX86_RCLASS_NONE,
    qx86_decode_amode_i
};

/* Reference: see JMP.  */
static qx86_amode                       qx86_amode_J
                                        =
{
    "J",                                "J",
    QX86_MODRM_FIELD_NONE,              QX86_RCLASS_NONE,
    qx86_decode_amode_j
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_M
                                        =
{
    "M",                                "M",
    QX86_MODRM_FIELD_MOD,               QX86_RCLASS_RESERVED_3,
    qx86_decode_amode_m
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_N
                                        =
{
    "N",                                "N",
    QX86_MODRM_FIELD_RM,                QX86_RCLASS_MMX,
    0
};

/* Reference: see MOV.  */
static qx86_amode                       qx86_amode_O
                                        =
{
    "O",                                "O",
    QX86_MODRM_FIELD_NONE,              QX86_RCLASS_NONE,
    qx86_decode_amode_o
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_P
                                        =
{
    "P",                                "P",
    QX86_MODRM_FIELD_REG,               QX86_RCLASS_MMX,
    0
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_Q
                                        =
{
    "Q",                                "Q",
    QX86_MODRM_FIELD_MOD,               QX86_RCLASS_MMX,
    0
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_R
                                        =
{
    "R",                                "R",
    QX86_MODRM_FIELD_RM,                QX86_RCLASS_RESERVED_3,
    0
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_S
                                        =
{
    "S",                                "S",
    QX86_MODRM_FIELD_REG,               QX86_RCLASS_SREG,
    0
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_U
                                        =
{
    "U",                                "U",
    QX86_MODRM_FIELD_RM,                QX86_RCLASS_XMM,
    0
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_V
                                        =
{
    "V",                                "V",
    QX86_MODRM_FIELD_REG,               QX86_RCLASS_XMM,
    0
};

/* Reference: none.  */
static qx86_amode                       qx86_amode_W
                                        =
{
    "W",                                "W",
    QX86_MODRM_FIELD_MOD,               QX86_RCLASS_XMM,
    0
};

/* Reference: see MOVSB.  */
static qx86_amode                       qx86_amode_X
                                        =
{
    "X",                                "X",
    QX86_MODRM_FIELD_NONE,              QX86_RCLASS_NONE,
    qx86_decode_amode_x
};

/* Reference: see MOVSB.  */
static qx86_amode                       qx86_amode_Y
                                        =
{
    "Y",                                "Y",
    QX86_MODRM_FIELD_NONE,              QX86_RCLASS_NONE,
    qx86_decode_amode_y
};
