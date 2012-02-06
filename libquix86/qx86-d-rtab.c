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

/* Reference: AMD Architecture Programmer's Manual 1: Sections 3.1, 4.3, 5.4,
   6.2.  */
static qx86_rtab_item                   qx86_rtab[QX86_REGISTER_COUNT]
                                        =
{
    {
        0,                              0,
        QX86_RCLASS_NONE,               0
    },
    {
        0,                              0,
        QX86_RCLASS_NONE,               0
    },
    {
        0,                              0,
        QX86_RCLASS_NONE,               0
    },
    {
        0,                              0,
        QX86_RCLASS_NONE,               0
    },

    {
        0,                              0,
        QX86_RCLASS_NONE,               0
    },
    {
        "IP",                           "IP",
        QX86_RCLASS_IP,                 2
    },
    {
        "EIP",                          "EIP",
        QX86_RCLASS_IP,                 4
    },
    {
        "RIP",                          "RIP",
        QX86_RCLASS_IP,                 8
    },

    {
        0,                              0,
        QX86_RCLASS_NONE,               0
    },
    {
        "FLAGS",                        "FLAGS",
        QX86_RCLASS_FLAGS,              2
    },
    {
        "EFLAGS",                       "EFLAGS",
        QX86_RCLASS_FLAGS,              4
    },
    {
        "RFLAGS",                       "RFLAGS",
        QX86_RCLASS_FLAGS,              8
    },

    {
        "AH",                           "AH",
        QX86_RCLASS_REG8,               1
    },
    {
        "CH",                           "CH",
        QX86_RCLASS_REG8,               1
    },
    {
        "DH",                           "DH",
        QX86_RCLASS_REG8,               1
    },
    {
        "BH",                           "BH",
        QX86_RCLASS_REG8,               1
    },

    {
        "AL",                           "AL",
        QX86_RCLASS_REG8,               1
    },
    {
        "CL",                           "CL",
        QX86_RCLASS_REG8,               1
    },
    {
        "DL",                           "DL",
        QX86_RCLASS_REG8,               1
    },
    {
        "BL",                           "BL",
        QX86_RCLASS_REG8,               1
    },
    {
        "SPL",                          "SPL",
        QX86_RCLASS_REG8,               1
    },
    {
        "BPL",                          "BPL",
        QX86_RCLASS_REG8,               1
    },
    {
        "SIL",                          "SIL",
        QX86_RCLASS_REG8,               1
    },
    {
        "DIL",                          "DIL",
        QX86_RCLASS_REG8,               1
    },
    {
        "R8B",                          "R8B",
        QX86_RCLASS_REG8,               1
    },
    {
        "R9B",                          "R9B",
        QX86_RCLASS_REG8,               1
    },
    {
        "R10B",                         "R10B",
        QX86_RCLASS_REG8,               1
    },
    {
        "R11B",                         "R11B",
        QX86_RCLASS_REG8,               1
    },
    {
        "R12B",                         "R12B",
        QX86_RCLASS_REG8,               1
    },
    {
        "R13B",                         "R13B",
        QX86_RCLASS_REG8,               1
    },
    {
        "R14B",                         "R14B",
        QX86_RCLASS_REG8,               1
    },
    {
        "R15B",                         "R15B",
        QX86_RCLASS_REG8,               1
    },

    {
        "AX",                           "AX",
        QX86_RCLASS_REG16,              2
    },
    {
        "CX",                           "CX",
        QX86_RCLASS_REG16,              2
    },
    {
        "DX",                           "DX",
        QX86_RCLASS_REG16,              2
    },
    {
        "BX",                           "BX",
        QX86_RCLASS_REG16,              2
    },
    {
        "SP",                           "SP",
        QX86_RCLASS_REG16,              2
    },
    {
        "BP",                           "BP",
        QX86_RCLASS_REG16,              2
    },
    {
        "SI",                           "SI",
        QX86_RCLASS_REG16,              2
    },
    {
        "DI",                           "DI",
        QX86_RCLASS_REG16,              2
    },
    {
        "R8W",                          "R8W",
        QX86_RCLASS_REG16,              2
    },
    {
        "R9W",                          "R9W",
        QX86_RCLASS_REG16,              2
    },
    {
        "R10W",                         "R10W",
        QX86_RCLASS_REG16,              2
    },
    {
        "R11W",                         "R11W",
        QX86_RCLASS_REG16,              2
    },
    {
        "R12W",                         "R12W",
        QX86_RCLASS_REG16,              2
    },
    {
        "R13W",                         "R13W",
        QX86_RCLASS_REG16,              2
    },
    {
        "R14W",                         "R14W",
        QX86_RCLASS_REG16,              2
    },
    {
        "R15W",                         "R15W",
        QX86_RCLASS_REG16,              2
    },

    {
        "EAX",                          "EAX",
        QX86_RCLASS_REG32,              4
    },
    {
        "ECX",                          "ECX",
        QX86_RCLASS_REG32,              4
    },
    {
        "EDX",                          "EDX",
        QX86_RCLASS_REG32,              4
    },
    {
        "EBX",                          "EBX",
        QX86_RCLASS_REG32,              4
    },
    {
        "ESP",                          "ESP",
        QX86_RCLASS_REG32,              4
    },
    {
        "EBP",                          "EBP",
        QX86_RCLASS_REG32,              4
    },
    {
        "ESI",                          "ESI",
        QX86_RCLASS_REG32,              4
    },
    {
        "EDI",                          "EDI",
        QX86_RCLASS_REG32,              4
    },
    {
        "R8D",                          "R8D",
        QX86_RCLASS_REG32,              4
    },
    {
        "R9D",                          "R9D",
        QX86_RCLASS_REG32,              4
    },
    {
        "R10D",                         "R10D",
        QX86_RCLASS_REG32,              4
    },
    {
        "R11D",                         "R11D",
        QX86_RCLASS_REG32,              4
    },
    {
        "R12D",                         "R12D",
        QX86_RCLASS_REG32,              4
    },
    {
        "R13D",                         "R13D",
        QX86_RCLASS_REG32,              4
    },
    {
        "R14D",                         "R14D",
        QX86_RCLASS_REG32,              4
    },
    {
        "R15D",                         "R15D",
        QX86_RCLASS_REG32,              4
    },

    {
        "RAX",                          "RAX",
        QX86_RCLASS_REG64,              8
    },
    {
        "RCX",                          "RCX",
        QX86_RCLASS_REG64,              8
    },
    {
        "RDX",                          "RDX",
        QX86_RCLASS_REG64,              8
    },
    {
        "RBX",                          "RBX",
        QX86_RCLASS_REG64,              8
    },
    {
        "RSP",                          "RSP",
        QX86_RCLASS_REG64,              8
    },
    {
        "RBP",                          "RBP",
        QX86_RCLASS_REG64,              8
    },
    {
        "RSI",                          "RSI",
        QX86_RCLASS_REG64,              8
    },
    {
        "RDI",                          "RDI",
        QX86_RCLASS_REG64,              8
    },
    {
        "R8",                           "R8",
        QX86_RCLASS_REG64,              8
    },
    {
        "R9",                           "R9",
        QX86_RCLASS_REG64,              8
    },
    {
        "R10",                          "R10",
        QX86_RCLASS_REG64,              8
    },
    {
        "R11",                          "R11",
        QX86_RCLASS_REG64,              8
    },
    {
        "R12",                          "R12",
        QX86_RCLASS_REG64,              8
    },
    {
        "R13",                          "R13",
        QX86_RCLASS_REG64,              8
    },
    {
        "R14",                          "R14",
        QX86_RCLASS_REG64,              8
    },
    {
        "R15",                          "R15",
        QX86_RCLASS_REG64,              8
    },

    {
        "CR0",                          "CR0",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR1",                          "CR1",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR2",                          "CR2",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR3",                          "CR3",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR4",                          "CR4",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR5",                          "CR5",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR6",                          "CR6",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR7",                          "CR7",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR8",                          "CR8",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR9",                          "CR9",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR10",                         "CR10",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR11",                         "CR11",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR12",                         "CR12",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR13",                         "CR13",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR14",                         "CR14",
        QX86_RCLASS_CREG,               8
    },
    {
        "CR15",                         "CR15",
        QX86_RCLASS_CREG,               8
    },

    {
        "DR0",                          "DR0",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR1",                          "DR1",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR2",                          "DR2",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR3",                          "DR3",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR4",                          "DR4",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR5",                          "DR5",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR6",                          "DR6",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR7",                          "DR7",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR8",                          "DR8",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR9",                          "DR9",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR10",                         "DR10",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR11",                         "DR11",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR12",                         "DR12",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR13",                         "DR13",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR14",                         "DR14",
        QX86_RCLASS_DREG,               8
    },
    {
        "DR15",                         "DR15",
        QX86_RCLASS_DREG,               8
    },

    {
        "ES",                           "ES",
        QX86_RCLASS_SREG,               2
    },
    {
        "CS",                           "CS",
        QX86_RCLASS_SREG,               2
    },
    {
        "SS",                           "SS",
        QX86_RCLASS_SREG,               2
    },
    {
        "DS",                           "DS",
        QX86_RCLASS_SREG,               2
    },
    {
        "FS",                           "FS",
        QX86_RCLASS_SREG,               2
    },
    {
        "GS",                           "GS",
        QX86_RCLASS_SREG,               2
    },
    {
        "SR6",                          "SR6",
        QX86_RCLASS_SREG,               2
    },
    {
        "SR7",                          "SR7",
        QX86_RCLASS_SREG,               2
    },

    {
        "ST0",                          "ST0",
        QX86_RCLASS_X87,                10
    },
    {
        "ST1",                          "ST1",
        QX86_RCLASS_X87,                10
    },
    {
        "ST2",                          "ST2",
        QX86_RCLASS_X87,                10
    },
    {
        "ST3",                          "ST3",
        QX86_RCLASS_X87,                10
    },
    {
        "ST4",                          "ST4",
        QX86_RCLASS_X87,                10
    },
    {
        "ST5",                          "ST5",
        QX86_RCLASS_X87,                10
    },
    {
        "ST6",                          "ST6",
        QX86_RCLASS_X87,                10
    },
    {
        "ST7",                          "ST7",
        QX86_RCLASS_X87,                10
    },

    {
        "FPR0",                         "FPR0",
        QX86_RCLASS_X87,                10
    },
    {
        "FPR1",                         "FPR1",
        QX86_RCLASS_X87,                10
    },
    {
        "FPR2",                         "FPR2",
        QX86_RCLASS_X87,                10
    },
    {
        "FPR3",                         "FPR3",
        QX86_RCLASS_X87,                10
    },
    {
        "FPR4",                         "FPR4",
        QX86_RCLASS_X87,                10
    },
    {
        "FPR5",                         "FPR5",
        QX86_RCLASS_X87,                10
    },
    {
        "FPR6",                         "FPR6",
        QX86_RCLASS_X87,                10
    },
    {
        "FPR7",                         "FPR7",
        QX86_RCLASS_X87,                10
    },

    {
        "MMX0",                         "MMX0",
        QX86_RCLASS_MMX,                8
    },
    {
        "MMX1",                         "MMX1",
        QX86_RCLASS_MMX,                8
    },
    {
        "MMX2",                         "MMX2",
        QX86_RCLASS_MMX,                8
    },
    {
        "MMX3",                         "MMX3",
        QX86_RCLASS_MMX,                8
    },
    {
        "MMX4",                         "MMX4",
        QX86_RCLASS_MMX,                8
    },
    {
        "MMX5",                         "MMX5",
        QX86_RCLASS_MMX,                8
    },
    {
        "MMX6",                         "MMX6",
        QX86_RCLASS_MMX,                8
    },
    {
        "MMX7",                         "MMX7",
        QX86_RCLASS_MMX,                8
    },

    {
        "XMM0",                         "XMM0",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM1",                         "XMM1",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM2",                         "XMM2",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM3",                         "XMM3",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM4",                         "XMM4",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM5",                         "XMM5",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM6",                         "XMM6",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM7",                         "XMM7",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM8",                         "XMM8",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM9",                         "XMM9",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM10",                        "XMM10",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM11",                        "XMM11",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM12",                        "XMM12",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM13",                        "XMM13",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM14",                        "XMM14",
        QX86_RCLASS_XMM,                16
    },
    {
        "XMM15",                        "XMM15",
        QX86_RCLASS_XMM,                16
    },

    {
        "YMM0",                         "YMM0",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM1",                         "YMM1",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM2",                         "YMM2",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM3",                         "YMM3",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM4",                         "YMM4",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM5",                         "YMM5",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM6",                         "YMM6",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM7",                         "YMM7",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM8",                         "YMM8",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM9",                         "YMM9",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM10",                        "YMM10",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM11",                        "YMM11",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM12",                        "YMM12",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM13",                        "YMM13",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM14",                        "YMM14",
        QX86_RCLASS_YMM,                16
    },
    {
        "YMM15",                        "YMM15",
        QX86_RCLASS_YMM,                16
    }
};
