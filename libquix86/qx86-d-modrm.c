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

/* Reference: AMD Architecture Programmer's Manual 3: Table A-12, A-14.  */
static int                              qx86_modrm_rindex_reg8[32]
                                        =
{
    QX86_REGISTER_AL,                   QX86_REGISTER_CL,
    QX86_REGISTER_DL,                   QX86_REGISTER_BL,
    QX86_REGISTER_AH,                   QX86_REGISTER_CH,
    QX86_REGISTER_DH,                   QX86_REGISTER_BH,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_AL,                   QX86_REGISTER_CL,
    QX86_REGISTER_DL,                   QX86_REGISTER_BL,
    QX86_REGISTER_SPL,                  QX86_REGISTER_BPL,
    QX86_REGISTER_SIL,                  QX86_REGISTER_DIL,

    QX86_REGISTER_R8B,                  QX86_REGISTER_R9B,
    QX86_REGISTER_R10B,                 QX86_REGISTER_R11B,
    QX86_REGISTER_R12B,                 QX86_REGISTER_R13B,
    QX86_REGISTER_R14B,                 QX86_REGISTER_R15B
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-12, A-14.  */
static int                              qx86_modrm_rindex_reg16[32]
                                        =
{
    QX86_REGISTER_AX,                   QX86_REGISTER_CX,
    QX86_REGISTER_DX,                   QX86_REGISTER_BX,
    QX86_REGISTER_SP,                   QX86_REGISTER_BP,
    QX86_REGISTER_SI,                   QX86_REGISTER_DI,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_AX,                   QX86_REGISTER_CX,
    QX86_REGISTER_DX,                   QX86_REGISTER_BX,
    QX86_REGISTER_SP,                   QX86_REGISTER_BP,
    QX86_REGISTER_SI,                   QX86_REGISTER_DI,

    QX86_REGISTER_R8W,                  QX86_REGISTER_R9W,
    QX86_REGISTER_R10W,                 QX86_REGISTER_R11W,
    QX86_REGISTER_R12W,                 QX86_REGISTER_R13W,
    QX86_REGISTER_R14W,                 QX86_REGISTER_R15W
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-12, A-14.  */
static int                              qx86_modrm_rindex_reg32[32]
                                        =
{
    QX86_REGISTER_EAX,                  QX86_REGISTER_ECX,
    QX86_REGISTER_EDX,                  QX86_REGISTER_EBX,
    QX86_REGISTER_ESP,                  QX86_REGISTER_EBP,
    QX86_REGISTER_ESI,                  QX86_REGISTER_EDI,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_EAX,                  QX86_REGISTER_ECX,
    QX86_REGISTER_EDX,                  QX86_REGISTER_EBX,
    QX86_REGISTER_ESP,                  QX86_REGISTER_EBP,
    QX86_REGISTER_ESI,                  QX86_REGISTER_EDI,

    QX86_REGISTER_R8D,                  QX86_REGISTER_R9D,
    QX86_REGISTER_R10D,                 QX86_REGISTER_R11D,
    QX86_REGISTER_R12D,                 QX86_REGISTER_R13D,
    QX86_REGISTER_R14D,                 QX86_REGISTER_R15D
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-12, A-14.  */
static int                              qx86_modrm_rindex_reg64[32]
                                        =
{
    QX86_REGISTER_RAX,                  QX86_REGISTER_RCX,
    QX86_REGISTER_RDX,                  QX86_REGISTER_RBX,
    QX86_REGISTER_RSP,                  QX86_REGISTER_RBP,
    QX86_REGISTER_RSI,                  QX86_REGISTER_RDI,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_RAX,                  QX86_REGISTER_RCX,
    QX86_REGISTER_RDX,                  QX86_REGISTER_RBX,
    QX86_REGISTER_RSP,                  QX86_REGISTER_RBP,
    QX86_REGISTER_RSI,                  QX86_REGISTER_RDI,

    QX86_REGISTER_R8,                   QX86_REGISTER_R9,
    QX86_REGISTER_R10,                  QX86_REGISTER_R11,
    QX86_REGISTER_R12,                  QX86_REGISTER_R13,
    QX86_REGISTER_R14,                  QX86_REGISTER_R15
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-12, A-14.  */
static int                              qx86_modrm_rindex_creg[32]
                                        =
{
    QX86_REGISTER_CR0,                  QX86_REGISTER_CR1,
    QX86_REGISTER_CR2,                  QX86_REGISTER_CR3,
    QX86_REGISTER_CR4,                  QX86_REGISTER_CR5,
    QX86_REGISTER_CR6,                  QX86_REGISTER_CR7,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_CR0,                  QX86_REGISTER_CR1,
    QX86_REGISTER_CR2,                  QX86_REGISTER_CR3,
    QX86_REGISTER_CR4,                  QX86_REGISTER_CR5,
    QX86_REGISTER_CR6,                  QX86_REGISTER_CR7,

    QX86_REGISTER_CR8,                  QX86_REGISTER_CR9,
    QX86_REGISTER_CR10,                 QX86_REGISTER_CR11,
    QX86_REGISTER_CR12,                 QX86_REGISTER_CR13,
    QX86_REGISTER_CR14,                 QX86_REGISTER_CR15
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-12, A-14.  */
static int                              qx86_modrm_rindex_dreg[32]
                                        =
{
    QX86_REGISTER_DR0,                  QX86_REGISTER_DR1,
    QX86_REGISTER_DR2,                  QX86_REGISTER_DR3,
    QX86_REGISTER_DR4,                  QX86_REGISTER_DR5,
    QX86_REGISTER_DR6,                  QX86_REGISTER_DR7,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_DR0,                  QX86_REGISTER_DR1,
    QX86_REGISTER_DR2,                  QX86_REGISTER_DR3,
    QX86_REGISTER_DR4,                  QX86_REGISTER_DR5,
    QX86_REGISTER_DR6,                  QX86_REGISTER_DR7,

    QX86_REGISTER_DR8,                  QX86_REGISTER_DR9,
    QX86_REGISTER_DR10,                 QX86_REGISTER_DR11,
    QX86_REGISTER_DR12,                 QX86_REGISTER_DR13,
    QX86_REGISTER_DR14,                 QX86_REGISTER_DR15
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-12, A-14.  */
static int                              qx86_modrm_rindex_sreg[32]
                                        =
{
    QX86_REGISTER_ES,                   QX86_REGISTER_CS,
    QX86_REGISTER_SS,                   QX86_REGISTER_DS,
    QX86_REGISTER_FS,                   QX86_REGISTER_GS,
    QX86_REGISTER_SR6,                  QX86_REGISTER_SR7,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_ES,                   QX86_REGISTER_CS,
    QX86_REGISTER_SS,                   QX86_REGISTER_DS,
    QX86_REGISTER_FS,                   QX86_REGISTER_GS,
    QX86_REGISTER_SR6,                  QX86_REGISTER_SR7,

    QX86_REGISTER_ES,                   QX86_REGISTER_CS,
    QX86_REGISTER_SS,                   QX86_REGISTER_DS,
    QX86_REGISTER_FS,                   QX86_REGISTER_GS,
    QX86_REGISTER_SR6,                  QX86_REGISTER_SR7
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-12, A-14.  */
static int                              qx86_modrm_rindex_mmx[32]
                                        =
{
    QX86_REGISTER_MMX0,                 QX86_REGISTER_MMX1,
    QX86_REGISTER_MMX2,                 QX86_REGISTER_MMX3,
    QX86_REGISTER_MMX4,                 QX86_REGISTER_MMX5,
    QX86_REGISTER_MMX6,                 QX86_REGISTER_MMX7,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_MMX0,                 QX86_REGISTER_MMX1,
    QX86_REGISTER_MMX2,                 QX86_REGISTER_MMX3,
    QX86_REGISTER_MMX4,                 QX86_REGISTER_MMX5,
    QX86_REGISTER_MMX6,                 QX86_REGISTER_MMX7,

    QX86_REGISTER_MMX0,                 QX86_REGISTER_MMX1,
    QX86_REGISTER_MMX2,                 QX86_REGISTER_MMX3,
    QX86_REGISTER_MMX4,                 QX86_REGISTER_MMX5,
    QX86_REGISTER_MMX6,                 QX86_REGISTER_MMX7
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-12, A-14.  */
static int                              qx86_modrm_rindex_xmm[32]
                                        =
{
    QX86_REGISTER_XMM0,                 QX86_REGISTER_XMM1,
    QX86_REGISTER_XMM2,                 QX86_REGISTER_XMM3,
    QX86_REGISTER_XMM4,                 QX86_REGISTER_XMM5,
    QX86_REGISTER_XMM6,                 QX86_REGISTER_XMM7,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_XMM0,                 QX86_REGISTER_XMM1,
    QX86_REGISTER_XMM2,                 QX86_REGISTER_XMM3,
    QX86_REGISTER_XMM4,                 QX86_REGISTER_XMM5,
    QX86_REGISTER_XMM6,                 QX86_REGISTER_XMM7,

    QX86_REGISTER_XMM8,                 QX86_REGISTER_XMM9,
    QX86_REGISTER_XMM10,                QX86_REGISTER_XMM11,
    QX86_REGISTER_XMM12,                QX86_REGISTER_XMM13,
    QX86_REGISTER_XMM14,                QX86_REGISTER_XMM15
};

/* Reference: Intel AVX Programming Reference, Section 2.4.  */
static int                              qx86_modrm_rindex_ymm[32]
                                        =
{
    QX86_REGISTER_YMM0,                 QX86_REGISTER_YMM1,
    QX86_REGISTER_YMM2,                 QX86_REGISTER_YMM3,
    QX86_REGISTER_YMM4,                 QX86_REGISTER_YMM5,
    QX86_REGISTER_YMM6,                 QX86_REGISTER_YMM7,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_YMM0,                 QX86_REGISTER_YMM1,
    QX86_REGISTER_YMM2,                 QX86_REGISTER_YMM3,
    QX86_REGISTER_YMM4,                 QX86_REGISTER_YMM5,
    QX86_REGISTER_YMM6,                 QX86_REGISTER_YMM7,

    QX86_REGISTER_YMM8,                 QX86_REGISTER_YMM9,
    QX86_REGISTER_YMM10,                QX86_REGISTER_YMM11,
    QX86_REGISTER_YMM12,                QX86_REGISTER_YMM13,
    QX86_REGISTER_YMM14,                QX86_REGISTER_YMM15
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-12, A-14.  */
static int *                            qx86_modrm_rindex[QX86_RCLASS_COUNT]
                                        =
{
    0,                                  0,
    0,                                  0,

    qx86_modrm_rindex_reg8,             qx86_modrm_rindex_reg16,
    qx86_modrm_rindex_reg32,            qx86_modrm_rindex_reg64,

    qx86_modrm_rindex_creg,             qx86_modrm_rindex_dreg,
    qx86_modrm_rindex_sreg,             0,

    0,                                  qx86_modrm_rindex_mmx,
    qx86_modrm_rindex_xmm,              qx86_modrm_rindex_ymm
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-13.  */
static int                              qx86_modrm_base_16[64]
                                        =
{
    QX86_REGISTER_BX,                   QX86_REGISTER_BX,
    QX86_REGISTER_BP,                   QX86_REGISTER_BP,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_BX,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_BX,                   QX86_REGISTER_BX,
    QX86_REGISTER_BP,                   QX86_REGISTER_BP,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_BP,                   QX86_REGISTER_BX,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_BX,                   QX86_REGISTER_BX,
    QX86_REGISTER_BP,                   QX86_REGISTER_BP,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_BP,                   QX86_REGISTER_BX,
        
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-13.  */
static int                              qx86_modrm_index_16[64]
                                        =
{
    QX86_REGISTER_SI,                   QX86_REGISTER_DI,
    QX86_REGISTER_SI,                   QX86_REGISTER_DI,
    QX86_REGISTER_SI,                   QX86_REGISTER_DI,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_SI,                   QX86_REGISTER_DI,
    QX86_REGISTER_SI,                   QX86_REGISTER_DI,
    QX86_REGISTER_SI,                   QX86_REGISTER_DI,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_SI,                   QX86_REGISTER_DI,
    QX86_REGISTER_SI,                   QX86_REGISTER_DI,
    QX86_REGISTER_SI,                   QX86_REGISTER_DI,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID
};

/* Reference: AMD Architecture Progammer's Manual 3: Table A-13.  */
static int                              qx86_modrm_scale_16[64]
                                        =
{
    QX86_SCALE_NONE,                    QX86_SCALE_NONE,
    QX86_SCALE_NONE,                    QX86_SCALE_NONE,
    QX86_SCALE_NONE,                    QX86_SCALE_NONE,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_NONE,                    QX86_SCALE_NONE,
    QX86_SCALE_NONE,                    QX86_SCALE_NONE,
    QX86_SCALE_NONE,                    QX86_SCALE_NONE,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_NONE,                    QX86_SCALE_NONE,
    QX86_SCALE_NONE,                    QX86_SCALE_NONE,
    QX86_SCALE_NONE,                    QX86_SCALE_NONE,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-13.  */
static int                              qx86_modrm_disp_16[64]
                                        =
{
    QX86_DISP_NONE,                     QX86_DISP_NONE,
    QX86_DISP_NONE,                     QX86_DISP_NONE,
    QX86_DISP_NONE,                     QX86_DISP_NONE,
    QX86_DISP_16,                       QX86_DISP_NONE,

    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,

    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,

    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,

    QX86_DISP_16,                       QX86_DISP_16,
    QX86_DISP_16,                       QX86_DISP_16,
    QX86_DISP_16,                       QX86_DISP_16,
    QX86_DISP_16,                       QX86_DISP_16,

    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,

    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,

    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-15.  */
static int                              qx86_modrm_base_32[64]
                                        =
{
    QX86_REGISTER_EAX,                  QX86_REGISTER_ECX,
    QX86_REGISTER_EDX,                  QX86_REGISTER_EBX,
    QX86_REGISTER_SPECIAL,              QX86_REGISTER_EIP,
    QX86_REGISTER_ESI,                  QX86_REGISTER_EDI,

    QX86_REGISTER_R8D,                  QX86_REGISTER_R9D,
    QX86_REGISTER_R10D,                 QX86_REGISTER_R11D,
    QX86_REGISTER_SPECIAL,              QX86_REGISTER_EIP,
    QX86_REGISTER_R14D,                 QX86_REGISTER_R15D,

    QX86_REGISTER_EAX,                  QX86_REGISTER_ECX,
    QX86_REGISTER_EDX,                  QX86_REGISTER_EBX,
    QX86_REGISTER_SPECIAL,              QX86_REGISTER_EBP,
    QX86_REGISTER_ESI,                  QX86_REGISTER_EDI,

    QX86_REGISTER_R8D,                  QX86_REGISTER_R9D,
    QX86_REGISTER_R10D,                 QX86_REGISTER_R11D,
    QX86_REGISTER_SPECIAL,              QX86_REGISTER_R13D,
    QX86_REGISTER_R14D,                 QX86_REGISTER_R15D,

    QX86_REGISTER_EAX,                  QX86_REGISTER_ECX,
    QX86_REGISTER_EDX,                  QX86_REGISTER_EBX,
    QX86_REGISTER_SPECIAL,              QX86_REGISTER_EBP,
    QX86_REGISTER_ESI,                  QX86_REGISTER_EDI,

    QX86_REGISTER_R8D,                  QX86_REGISTER_R9D,
    QX86_REGISTER_R10D,                 QX86_REGISTER_R11D,
    QX86_REGISTER_SPECIAL,              QX86_REGISTER_R13D,
    QX86_REGISTER_R14D,                 QX86_REGISTER_R15D,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-15.  */
static int                              qx86_modrm_index_32[64]
                                        =
{
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_INVALID,              QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_INVALID,              QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_INVALID,              QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_INVALID,              QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_INVALID,              QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_INVALID,              QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-15.  */
static int                              qx86_modrm_scale_32[64]
                                        =
{
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-15.  */
static int                              qx86_modrm_disp_32[64]
                                        =
{
    QX86_DISP_NONE,                     QX86_DISP_NONE,
    QX86_DISP_NONE,                     QX86_DISP_NONE,
    QX86_DISP_NONE,                     QX86_DISP_32,
    QX86_DISP_NONE,                     QX86_DISP_NONE,

    QX86_DISP_NONE,                     QX86_DISP_NONE,
    QX86_DISP_NONE,                     QX86_DISP_NONE,
    QX86_DISP_NONE,                     QX86_DISP_32,
    QX86_DISP_NONE,                     QX86_DISP_NONE,

    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,

    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,

    QX86_DISP_32,                       QX86_DISP_32,
    QX86_DISP_32,                       QX86_DISP_32,
    QX86_DISP_32,                       QX86_DISP_32,
    QX86_DISP_32,                       QX86_DISP_32,

    QX86_DISP_32,                       QX86_DISP_32,
    QX86_DISP_32,                       QX86_DISP_32,
    QX86_DISP_32,                       QX86_DISP_32,
    QX86_DISP_32,                       QX86_DISP_32,

    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,

    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-15.  */
static int                              qx86_modrm_base_64[64]
                                        =
{
    QX86_REGISTER_RAX,                  QX86_REGISTER_RCX,
    QX86_REGISTER_RDX,                  QX86_REGISTER_RBX,
    QX86_REGISTER_SPECIAL,              QX86_REGISTER_RIP,
    QX86_REGISTER_RSI,                  QX86_REGISTER_RDI,

    QX86_REGISTER_R8,                   QX86_REGISTER_R9,
    QX86_REGISTER_R10,                  QX86_REGISTER_R11,
    QX86_REGISTER_SPECIAL,              QX86_REGISTER_RIP,
    QX86_REGISTER_R14,                  QX86_REGISTER_R15,

    QX86_REGISTER_RAX,                  QX86_REGISTER_RCX,
    QX86_REGISTER_RDX,                  QX86_REGISTER_RBX,
    QX86_REGISTER_SPECIAL,              QX86_REGISTER_RBP,
    QX86_REGISTER_RSI,                  QX86_REGISTER_RDI,

    QX86_REGISTER_R8,                   QX86_REGISTER_R9,
    QX86_REGISTER_R10,                  QX86_REGISTER_R11,
    QX86_REGISTER_SPECIAL,              QX86_REGISTER_R13,
    QX86_REGISTER_R14,                  QX86_REGISTER_R15,

    QX86_REGISTER_RAX,                  QX86_REGISTER_RCX,
    QX86_REGISTER_RDX,                  QX86_REGISTER_RBX,
    QX86_REGISTER_SPECIAL,              QX86_REGISTER_RBP,
    QX86_REGISTER_RSI,                  QX86_REGISTER_RDI,

    QX86_REGISTER_R8,                   QX86_REGISTER_R9,
    QX86_REGISTER_R10,                  QX86_REGISTER_R11,
    QX86_REGISTER_SPECIAL,              QX86_REGISTER_R13,
    QX86_REGISTER_R14,                  QX86_REGISTER_R15,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-15.  */
static int                              qx86_modrm_index_64[64]
                                        =
{
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_INVALID,              QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_INVALID,              QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_INVALID,              QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_INVALID,              QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_INVALID,              QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,
    QX86_REGISTER_INVALID,              QX86_REGISTER_NONE,
    QX86_REGISTER_NONE,                 QX86_REGISTER_NONE,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,

    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID,
    QX86_REGISTER_INVALID,              QX86_REGISTER_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-15.  */
static int                              qx86_modrm_scale_64[64]
                                        =
{
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,

    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID,
    QX86_SCALE_INVALID,                 QX86_SCALE_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-15.  */
static int                              qx86_modrm_disp_64[64]
                                        =
{
    QX86_DISP_NONE,                     QX86_DISP_NONE,
    QX86_DISP_NONE,                     QX86_DISP_NONE,
    QX86_DISP_NONE,                     QX86_DISP_32,
    QX86_DISP_NONE,                     QX86_DISP_NONE,

    QX86_DISP_NONE,                     QX86_DISP_NONE,
    QX86_DISP_NONE,                     QX86_DISP_NONE,
    QX86_DISP_NONE,                     QX86_DISP_32,
    QX86_DISP_NONE,                     QX86_DISP_NONE,

    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,

    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,
    QX86_DISP_8,                        QX86_DISP_8,

    QX86_DISP_32,                       QX86_DISP_32,
    QX86_DISP_32,                       QX86_DISP_32,
    QX86_DISP_32,                       QX86_DISP_32,
    QX86_DISP_32,                       QX86_DISP_32,

    QX86_DISP_32,                       QX86_DISP_32,
    QX86_DISP_32,                       QX86_DISP_32,
    QX86_DISP_32,                       QX86_DISP_32,
    QX86_DISP_32,                       QX86_DISP_32,

    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,

    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID,
    QX86_DISP_INVALID,                  QX86_DISP_INVALID
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-13, A-15.  */
static int *                            qx86_modrm_base[4]
                                        =
{
    qx86_modrm_base_16,                 qx86_modrm_base_32,
    qx86_modrm_base_64,                 0
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-13, A-15.  */
static int *                            qx86_modrm_index[4]
                                        =
{
    qx86_modrm_index_16,                qx86_modrm_index_32,
    qx86_modrm_index_64,                0
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-13, A-15.  */
static int *                            qx86_modrm_scale[4]
                                        =
{
    qx86_modrm_scale_16,                qx86_modrm_scale_32,
    qx86_modrm_scale_64,                0
};

/* Reference: AMD Architecture Programmer's Manual 3: Table A-13, A-15.  */
static int *                            qx86_modrm_disp[4]
                                        =
{
    qx86_modrm_disp_16,                 qx86_modrm_disp_32,
    qx86_modrm_disp_64,                 0
};
