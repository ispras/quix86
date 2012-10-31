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

#ifndef QX86_E_REGISTER_H
#define QX86_E_REGISTER_H

/**
 * Enumeration of <em>x86</em> registers.
 *
 * \author                              icee
 * \since                               1.0
 */
enum
{
    QX86_REGISTER_NONE                  = 0,
    QX86_REGISTER_INVALID               = 1,
    QX86_REGISTER_SPECIAL               = 2,
    QX86_REGISTER_RESERVED_3            = 3,

    QX86_REGISTER_RESERVED_4            = 4,
    QX86_REGISTER_IP                    = 5,
    QX86_REGISTER_EIP                   = 6,
    QX86_REGISTER_RIP                   = 7,

    QX86_REGISTER_RESERVED_8            = 8,
    QX86_REGISTER_FLAGS                 = 9,
    QX86_REGISTER_EFLAGS                = 10,
    QX86_REGISTER_RFLAGS                = 11,

    QX86_REGISTER_AH                    = 12,
    QX86_REGISTER_CH                    = 13,
    QX86_REGISTER_DH                    = 14,
    QX86_REGISTER_BH                    = 15,

    QX86_REGISTER_AL                    = 16,
    QX86_REGISTER_CL                    = 17,
    QX86_REGISTER_DL                    = 18,
    QX86_REGISTER_BL                    = 19,
    QX86_REGISTER_SPL                   = 20,
    QX86_REGISTER_BPL                   = 21,
    QX86_REGISTER_SIL                   = 22,
    QX86_REGISTER_DIL                   = 23,
    QX86_REGISTER_R8B                   = 24,
    QX86_REGISTER_R9B                   = 25,
    QX86_REGISTER_R10B                  = 26,
    QX86_REGISTER_R11B                  = 27,
    QX86_REGISTER_R12B                  = 28,
    QX86_REGISTER_R13B                  = 29,
    QX86_REGISTER_R14B                  = 30,
    QX86_REGISTER_R15B                  = 31,

    QX86_REGISTER_AX                    = 32,
    QX86_REGISTER_CX                    = 33,
    QX86_REGISTER_DX                    = 34,
    QX86_REGISTER_BX                    = 35,
    QX86_REGISTER_SP                    = 36,
    QX86_REGISTER_BP                    = 37,
    QX86_REGISTER_SI                    = 38,
    QX86_REGISTER_DI                    = 39,
    QX86_REGISTER_R8W                   = 40,
    QX86_REGISTER_R9W                   = 41,
    QX86_REGISTER_R10W                  = 42,
    QX86_REGISTER_R11W                  = 43,
    QX86_REGISTER_R12W                  = 44,
    QX86_REGISTER_R13W                  = 45,
    QX86_REGISTER_R14W                  = 46,
    QX86_REGISTER_R15W                  = 47,

    QX86_REGISTER_EAX                   = 48,
    QX86_REGISTER_ECX                   = 49,
    QX86_REGISTER_EDX                   = 50,
    QX86_REGISTER_EBX                   = 51,
    QX86_REGISTER_ESP                   = 52,
    QX86_REGISTER_EBP                   = 53,
    QX86_REGISTER_ESI                   = 54,
    QX86_REGISTER_EDI                   = 55,
    QX86_REGISTER_R8D                   = 56,
    QX86_REGISTER_R9D                   = 57,
    QX86_REGISTER_R10D                  = 58,
    QX86_REGISTER_R11D                  = 59,
    QX86_REGISTER_R12D                  = 60,
    QX86_REGISTER_R13D                  = 61,
    QX86_REGISTER_R14D                  = 62,
    QX86_REGISTER_R15D                  = 63,

    QX86_REGISTER_RAX                   = 64,
    QX86_REGISTER_RCX                   = 65,
    QX86_REGISTER_RDX                   = 66,
    QX86_REGISTER_RBX                   = 67,
    QX86_REGISTER_RSP                   = 68,
    QX86_REGISTER_RBP                   = 69,
    QX86_REGISTER_RSI                   = 70,
    QX86_REGISTER_RDI                   = 71,
    QX86_REGISTER_R8                    = 72,
    QX86_REGISTER_R9                    = 73,
    QX86_REGISTER_R10                   = 74,
    QX86_REGISTER_R11                   = 75,
    QX86_REGISTER_R12                   = 76,
    QX86_REGISTER_R13                   = 77,
    QX86_REGISTER_R14                   = 78,
    QX86_REGISTER_R15                   = 79,

    QX86_REGISTER_CR0                   = 80,
    QX86_REGISTER_CR1                   = 81,
    QX86_REGISTER_CR2                   = 82,
    QX86_REGISTER_CR3                   = 83,
    QX86_REGISTER_CR4                   = 84,
    QX86_REGISTER_CR5                   = 85,
    QX86_REGISTER_CR6                   = 86,
    QX86_REGISTER_CR7                   = 87,
    QX86_REGISTER_CR8                   = 88,
    QX86_REGISTER_CR9                   = 89,
    QX86_REGISTER_CR10                  = 90,
    QX86_REGISTER_CR11                  = 91,
    QX86_REGISTER_CR12                  = 92,
    QX86_REGISTER_CR13                  = 93,
    QX86_REGISTER_CR14                  = 94,
    QX86_REGISTER_CR15                  = 95,

    QX86_REGISTER_DR0                   = 96,
    QX86_REGISTER_DR1                   = 97,
    QX86_REGISTER_DR2                   = 98,
    QX86_REGISTER_DR3                   = 99,
    QX86_REGISTER_DR4                   = 100,
    QX86_REGISTER_DR5                   = 101,
    QX86_REGISTER_DR6                   = 102,
    QX86_REGISTER_DR7                   = 103,
    QX86_REGISTER_DR8                   = 104,
    QX86_REGISTER_DR9                   = 105,
    QX86_REGISTER_DR10                  = 106,
    QX86_REGISTER_DR11                  = 107,
    QX86_REGISTER_DR12                  = 108,
    QX86_REGISTER_DR13                  = 109,
    QX86_REGISTER_DR14                  = 110,
    QX86_REGISTER_DR15                  = 111,

    QX86_REGISTER_ES                    = 112,
    QX86_REGISTER_CS                    = 113,
    QX86_REGISTER_SS                    = 114,
    QX86_REGISTER_DS                    = 115,
    QX86_REGISTER_FS                    = 116,
    QX86_REGISTER_GS                    = 117,
    QX86_REGISTER_SR6                   = 118,
    QX86_REGISTER_SR7                   = 119,

    QX86_REGISTER_ST0                   = 120,
    QX86_REGISTER_ST1                   = 121,
    QX86_REGISTER_ST2                   = 122,
    QX86_REGISTER_ST3                   = 123,
    QX86_REGISTER_ST4                   = 124,
    QX86_REGISTER_ST5                   = 125,
    QX86_REGISTER_ST6                   = 126,
    QX86_REGISTER_ST7                   = 127,

    QX86_REGISTER_FPR0                  = 128,
    QX86_REGISTER_FPR1                  = 129,
    QX86_REGISTER_FPR2                  = 130,
    QX86_REGISTER_FPR3                  = 131,
    QX86_REGISTER_FPR4                  = 132,
    QX86_REGISTER_FPR5                  = 133,
    QX86_REGISTER_FPR6                  = 134,
    QX86_REGISTER_FPR7                  = 135,

    QX86_REGISTER_MMX0                  = 136,
    QX86_REGISTER_MMX1                  = 137,
    QX86_REGISTER_MMX2                  = 138,
    QX86_REGISTER_MMX3                  = 139,
    QX86_REGISTER_MMX4                  = 140,
    QX86_REGISTER_MMX5                  = 141,
    QX86_REGISTER_MMX6                  = 142,
    QX86_REGISTER_MMX7                  = 143,

    QX86_REGISTER_XMM0                  = 144,
    QX86_REGISTER_XMM1                  = 145,
    QX86_REGISTER_XMM2                  = 146,
    QX86_REGISTER_XMM3                  = 147,
    QX86_REGISTER_XMM4                  = 148,
    QX86_REGISTER_XMM5                  = 149,
    QX86_REGISTER_XMM6                  = 150,
    QX86_REGISTER_XMM7                  = 151,
    QX86_REGISTER_XMM8                  = 152,
    QX86_REGISTER_XMM9                  = 153,
    QX86_REGISTER_XMM10                 = 154,
    QX86_REGISTER_XMM11                 = 155,
    QX86_REGISTER_XMM12                 = 156,
    QX86_REGISTER_XMM13                 = 157,
    QX86_REGISTER_XMM14                 = 158,
    QX86_REGISTER_XMM15                 = 159,

    QX86_REGISTER_YMM0                  = 160,
    QX86_REGISTER_YMM1                  = 161,
    QX86_REGISTER_YMM2                  = 162,
    QX86_REGISTER_YMM3                  = 163,
    QX86_REGISTER_YMM4                  = 164,
    QX86_REGISTER_YMM5                  = 165,
    QX86_REGISTER_YMM6                  = 166,
    QX86_REGISTER_YMM7                  = 167,
    QX86_REGISTER_YMM8                  = 168,
    QX86_REGISTER_YMM9                  = 169,
    QX86_REGISTER_YMM10                 = 170,
    QX86_REGISTER_YMM11                 = 171,
    QX86_REGISTER_YMM12                 = 172,
    QX86_REGISTER_YMM13                 = 173,
    QX86_REGISTER_YMM14                 = 174,
    QX86_REGISTER_YMM15                 = 175,

    QX86_REGISTER_GDTR                  = 176,
    QX86_REGISTER_IDTR                  = 177,
    QX86_REGISTER_LDTR                  = 178,
    QX86_REGISTER_TR                    = 179,

    QX86_REGISTER_COUNT                 = 180
};

#endif /* QX86_E_REGISTER_H */
