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

/* Reference: none.  Example: 04 = ADD AL, Ib.  */
static qx86_rtuple                      qx86_rtuple_AL
                                        =
{
    "AL",                               "AL",

    {
        QX86_REGISTER_AL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_AL,               QX86_REGISTER_AL,

        QX86_REGISTER_AL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_AL,               QX86_REGISTER_AL,
    
        QX86_REGISTER_AL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_AL,               QX86_REGISTER_AL
    }
};

/* Reference: none.  Example: D2 = <M2> Eb, CL.  */
static qx86_rtuple                      qx86_rtuple_CL
                                        =
{
    "CL",                               "CL",

    {
        QX86_REGISTER_CL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_CL,               QX86_REGISTER_CL,

        QX86_REGISTER_CL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_CL,               QX86_REGISTER_CL,

        QX86_REGISTER_CL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_CL,               QX86_REGISTER_CL
    }
};

/* Reference: none.  Example: DF E0 = FNSTSW AX.  */
static qx86_rtuple                      qx86_rtuple_AX
                                        =
{
    "AX",                               "AX",

    {
        QX86_REGISTER_AX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_AX,               QX86_REGISTER_AX,

        QX86_REGISTER_AX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_AX,               QX86_REGISTER_AX,

        QX86_REGISTER_AX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_AX,               QX86_REGISTER_AX
    }
};

/* Reference: none.  Example: EC = IN AL, DX.  */
static qx86_rtuple                      qx86_rtuple_DX
                                        =
{
    "DX",                               "DX",

    {
        QX86_REGISTER_DX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DX,               QX86_REGISTER_DX,

        QX86_REGISTER_DX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DX,               QX86_REGISTER_DX,

        QX86_REGISTER_DX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DX,               QX86_REGISTER_DX
    }
};

/* Reference: none.  Example: 06 = PUSH ES.  */
static qx86_rtuple                      qx86_rtuple_ES
                                        =
{
    "ES",                               "ES",

    {
        QX86_REGISTER_ES,               QX86_REGISTER_INVALID,
        QX86_REGISTER_ES,               QX86_REGISTER_ES,

        QX86_REGISTER_ES,               QX86_REGISTER_INVALID,
        QX86_REGISTER_ES,               QX86_REGISTER_ES,

        QX86_REGISTER_ES,               QX86_REGISTER_INVALID,
        QX86_REGISTER_ES,               QX86_REGISTER_ES
    }
};

/* Reference: none.  Example: 0E = PUSH CS.  */
static qx86_rtuple                      qx86_rtuple_CS
                                        =
{
    "CS",                               "CS",

    {
        QX86_REGISTER_CS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_CS,               QX86_REGISTER_CS,
 
        QX86_REGISTER_CS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_CS,               QX86_REGISTER_CS,

        QX86_REGISTER_CS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_CS,               QX86_REGISTER_CS
    }
};

/* Reference: none.  Example: 16 = PUSH SS.  */
static qx86_rtuple                      qx86_rtuple_SS
                                        =
{
    "SS",                               "SS",

    {
        QX86_REGISTER_SS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SS,               QX86_REGISTER_SS,

        QX86_REGISTER_SS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SS,               QX86_REGISTER_SS,

        QX86_REGISTER_SS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SS,               QX86_REGISTER_SS
    }
};

/* Reference: none.  Example: 1E = PUSH DS.  */
static qx86_rtuple                      qx86_rtuple_DS
                                        =
{
    "DS",                               "DS",

    {
        QX86_REGISTER_DS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DS,               QX86_REGISTER_DS,

        QX86_REGISTER_DS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DS,               QX86_REGISTER_DS,

        QX86_REGISTER_DS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DS,               QX86_REGISTER_DS
    }
};

/* Reference: none.  Example: 0F A0 = PUSH FS.  */
static qx86_rtuple                      qx86_rtuple_FS
                                        =
{
    "FS",                               "FS",

    {
        QX86_REGISTER_FS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_FS,               QX86_REGISTER_FS,

        QX86_REGISTER_FS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_FS,               QX86_REGISTER_FS,

        QX86_REGISTER_FS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_FS,               QX86_REGISTER_FS
    }
};

/* Reference: none.  Example: 0F A8 = PUSH GS.  */
static qx86_rtuple                      qx86_rtuple_GS
                                        =
{
    "GS",                               "GS",

    {
        QX86_REGISTER_GS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_GS,               QX86_REGISTER_GS,

        QX86_REGISTER_GS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_GS,               QX86_REGISTER_GS,

        QX86_REGISTER_GS,               QX86_REGISTER_INVALID,
        QX86_REGISTER_GS,               QX86_REGISTER_GS
    }
};

/* Reference: none.  Example: 40 = INC eAX.  */
static qx86_rtuple                      qx86_rtuple_eAX
                                        =
{
    "eAX",                              "eAX",

    {
        QX86_REGISTER_AX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_AX,               QX86_REGISTER_AX,

        QX86_REGISTER_EAX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EAX,              QX86_REGISTER_EAX,

        QX86_REGISTER_EAX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EAX,              QX86_REGISTER_EAX
    }
};

/* Reference: none.  Example: 41 = INC eCX.  */
static qx86_rtuple                      qx86_rtuple_eCX
                                        =
{
    "eCX",                              "eCX",

    {
        QX86_REGISTER_CX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_CX,               QX86_REGISTER_CX,

        QX86_REGISTER_ECX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ECX,              QX86_REGISTER_ECX,

        QX86_REGISTER_ECX,              QX86_REGISTER_ECX,
        QX86_REGISTER_ECX,              QX86_REGISTER_ECX
    }
};

/* Reference: none.  Example: 42 = INC eDX.  */
static qx86_rtuple                      qx86_rtuple_eDX
                                        =
{
    "eDX",                              "eDX",

    {
        QX86_REGISTER_DX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DX,               QX86_REGISTER_DX,

        QX86_REGISTER_EDX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EDX,              QX86_REGISTER_EDX,

        QX86_REGISTER_EDX,              QX86_REGISTER_EDX,
        QX86_REGISTER_EDX,              QX86_REGISTER_EDX
    }
};

/* Reference: none.  Example: 43 = INC eBX.  */
static qx86_rtuple                      qx86_rtuple_eBX
                                        =
{
    "eBX",                              "eBX",

    {
        QX86_REGISTER_BX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_BX,               QX86_REGISTER_BX,

        QX86_REGISTER_EBX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EBX,              QX86_REGISTER_EBX,

        QX86_REGISTER_EBX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EBX,              QX86_REGISTER_EBX
    }
};

/* Reference: none.  Example: 44 = INC eSP.  */
static qx86_rtuple                      qx86_rtuple_eSP
                                        =
{
    "eSP",                              "eSP",

    {
        QX86_REGISTER_SP,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SP,               QX86_REGISTER_SP,

        QX86_REGISTER_ESP,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ESP,              QX86_REGISTER_ESP,

        QX86_REGISTER_ESP,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ESP,              QX86_REGISTER_ESP
    }
};

/* Reference: none.  Example: 45 = INC eBP.  */
static qx86_rtuple                      qx86_rtuple_eBP
                                        =
{
    "eBP",                              "eBP",

    {
        QX86_REGISTER_BP,               QX86_REGISTER_INVALID,
        QX86_REGISTER_BP,               QX86_REGISTER_BP,

        QX86_REGISTER_EBP,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EBP,              QX86_REGISTER_EBP,

        QX86_REGISTER_EBP,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EBP,              QX86_REGISTER_EBP
    }
};

/* Reference: none.  Example: 46 = INC eSI.  */
static qx86_rtuple                      qx86_rtuple_eSI
                                        =
{
    "eSI",                              "eSI",

    {
        QX86_REGISTER_SI,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SI,               QX86_REGISTER_SI,

        QX86_REGISTER_ESI,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ESI,              QX86_REGISTER_ESI,

        QX86_REGISTER_ESI,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ESI,              QX86_REGISTER_ESI
    }
};

/* Reference: none.  Example: 47 = INC eDI.  */
static qx86_rtuple                      qx86_rtuple_eDI
                                        =
{
    "eDI",                              "eDI",

    {
        QX86_REGISTER_DI,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DI,               QX86_REGISTER_DI,

        QX86_REGISTER_EDI,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EDI,              QX86_REGISTER_EDI,

        QX86_REGISTER_EDI,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EDI,              QX86_REGISTER_EDI
    }
};

/* Reference: none.  Example: 05 = ADD rAX, Iz.  */
static qx86_rtuple                      qx86_rtuple_rAX
                                        =
{
    "rAX",                              "rAX",

    {
        QX86_REGISTER_AX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_AX,               QX86_REGISTER_AX,

        QX86_REGISTER_EAX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EAX,              QX86_REGISTER_EAX,

        QX86_REGISTER_RAX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_RAX,              QX86_REGISTER_RAX
    }
};

/* Reference: none.  Needed for the X addressing mode.  */
static qx86_rtuple                      qx86_rtuple_rSI
                                        =
{
    "rSI",                              "rSI",

    {
        QX86_REGISTER_SI,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SI,               QX86_REGISTER_SI,

        QX86_REGISTER_ESI,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ESI,              QX86_REGISTER_ESI,

        QX86_REGISTER_RSI,              QX86_REGISTER_INVALID,
        QX86_REGISTER_RSI,              QX86_REGISTER_RSI
    }
};

/* Reference: none.  Needed for the Y addressing mode.  */
static qx86_rtuple                      qx86_rtuple_rDI
                                        =
{
    "rDI",                              "rDI",

    {
        QX86_REGISTER_DI,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DI,               QX86_REGISTER_DI,

        QX86_REGISTER_EDI,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EDI,              QX86_REGISTER_EDI,

        QX86_REGISTER_RDI,              QX86_REGISTER_INVALID,
        QX86_REGISTER_RDI,              QX86_REGISTER_RDI
    }
};

/* Reference: none.  Example: 50 = PUSH r0.  */
static qx86_rtuple                      qx86_rtuple_r0
                                        =
{
    "r0",                               "r0",

    {
        QX86_REGISTER_AX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_AX,               QX86_REGISTER_R8W,

        QX86_REGISTER_EAX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EAX,              QX86_REGISTER_R8D,

        QX86_REGISTER_RAX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_RAX,              QX86_REGISTER_R8
    }
};

/* Reference: none.  Example: 51 = PUSH r1.  */
static qx86_rtuple                      qx86_rtuple_r1
                                        =
{
    "r1",                               "r1",

    {
        QX86_REGISTER_CX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_CX,               QX86_REGISTER_R9W,

        QX86_REGISTER_ECX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ECX,              QX86_REGISTER_R9D,

        QX86_REGISTER_RCX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_RCX,              QX86_REGISTER_R9
    }
};

/* Reference: none.  Example: 52 = PUSH r2.  */
static qx86_rtuple                      qx86_rtuple_r2
                                        =
{
    "r2",                               "r2",

    {
        QX86_REGISTER_DX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DX,               QX86_REGISTER_R10W,

        QX86_REGISTER_EDX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EDX,              QX86_REGISTER_R10D,

        QX86_REGISTER_RDX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_RDX,              QX86_REGISTER_R10
    }
};

/* Reference: none.  Example: 53 = PUSH r3.  */
static qx86_rtuple                      qx86_rtuple_r3
                                        =
{
    "r3",                               "r3",

    {
        QX86_REGISTER_BX,               QX86_REGISTER_INVALID,
        QX86_REGISTER_BX,               QX86_REGISTER_R11W,

        QX86_REGISTER_EBX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EBX,              QX86_REGISTER_R11D,

        QX86_REGISTER_RBX,              QX86_REGISTER_INVALID,
        QX86_REGISTER_RBX,              QX86_REGISTER_R11
    }
};

/* Reference: none.  Example: 54 = PUSH r4.  */
static qx86_rtuple                      qx86_rtuple_r4
                                        =
{
    "r4",                               "r4",

    {
        QX86_REGISTER_SP,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SP,               QX86_REGISTER_R12W,

        QX86_REGISTER_ESP,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ESP,              QX86_REGISTER_R12D,

        QX86_REGISTER_RSP,              QX86_REGISTER_INVALID,
        QX86_REGISTER_RSP,              QX86_REGISTER_R12
    }
};

/* Reference: none.  Example: 55 = PUSH r5.  */
static qx86_rtuple                      qx86_rtuple_r5
                                        =
{
    "r5",                               "r5",

    {
        QX86_REGISTER_BP,               QX86_REGISTER_INVALID,
        QX86_REGISTER_BP,               QX86_REGISTER_R13W,

        QX86_REGISTER_EBP,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EBP,              QX86_REGISTER_R13D,

        QX86_REGISTER_RBP,              QX86_REGISTER_INVALID,
        QX86_REGISTER_RBP,              QX86_REGISTER_R13
    }
};

/* Reference: none.  Example: 56 = PUSH r6.  */
static qx86_rtuple                      qx86_rtuple_r6
                                        =
{
    "r6",                               "r6",

    {
        QX86_REGISTER_SI,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SI,               QX86_REGISTER_R14W,

        QX86_REGISTER_ESI,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ESI,              QX86_REGISTER_R14D,

        QX86_REGISTER_RSI,              QX86_REGISTER_INVALID,
        QX86_REGISTER_RSI,              QX86_REGISTER_R14
    }
};

/* Reference: none.  Example: 57 = PUSH r7.  */
static qx86_rtuple                      qx86_rtuple_r7
                                        =
{
    "r7",                               "r7",

    {
        QX86_REGISTER_DI,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DI,               QX86_REGISTER_R15W,

        QX86_REGISTER_EDI,              QX86_REGISTER_INVALID,
        QX86_REGISTER_EDI,              QX86_REGISTER_R15D,

        QX86_REGISTER_RDI,              QX86_REGISTER_INVALID,
        QX86_REGISTER_RDI,              QX86_REGISTER_R15
    }
};

/* Reference: none.  Example: B0 = MOV R0B, Ib.  */
static qx86_rtuple                      qx86_rtuple_R0B
                                        =
{
    "R0B",                              "R0B",
    
    {
        QX86_REGISTER_AL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_AL,               QX86_REGISTER_R8B,

        QX86_REGISTER_AL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_AL,               QX86_REGISTER_R8B,

        QX86_REGISTER_AL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_AL,               QX86_REGISTER_R8B
    }
};

/* Reference: none.  Example: B1 = MOV R1B, Ib.  */
static qx86_rtuple                      qx86_rtuple_R1B
                                        =
{
    "R1B",                              "R1B",

    {
        QX86_REGISTER_CL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_CL,               QX86_REGISTER_R9B,

        QX86_REGISTER_CL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_CL,               QX86_REGISTER_R9B,

        QX86_REGISTER_CL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_CL,               QX86_REGISTER_R9B
    }
};

/* Reference: none.  Example: B2 = MOV R2B, Ib.  */
static qx86_rtuple                      qx86_rtuple_R2B
                                        =
{
    "R2B",                              "R2B",

    {
        QX86_REGISTER_DL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DL,               QX86_REGISTER_R10B,

        QX86_REGISTER_DL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DL,               QX86_REGISTER_R10B,

        QX86_REGISTER_DL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DL,               QX86_REGISTER_R10B
    }
};

/* Reference: none.  Example: B3 = MOV R3B, Ib.  */
static qx86_rtuple                      qx86_rtuple_R3B
                                        =
{
    "R3B",                              "R3B",

    {
        QX86_REGISTER_BL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_BL,               QX86_REGISTER_R11B,

        QX86_REGISTER_BL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_BL,               QX86_REGISTER_R11B,

        QX86_REGISTER_BL,               QX86_REGISTER_INVALID,
        QX86_REGISTER_BL,               QX86_REGISTER_R11B
    }
};

/* Reference: none.  Example: B4 = MOV R4B, Ib.  */
static qx86_rtuple                      qx86_rtuple_R4B
                                        =
{
    "R4B",                              "R4B",

    {
        QX86_REGISTER_AH,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SPL,              QX86_REGISTER_R12B,

        QX86_REGISTER_AH,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SPL,              QX86_REGISTER_R12B,

        QX86_REGISTER_AH,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SPL,              QX86_REGISTER_R12B
    }
};

/* Reference: none.  Example: B5 = MOV R5B, Ib.  */
static qx86_rtuple                      qx86_rtuple_R5B
                                        =
{
    "R5B",                              "R5B",

    {
        QX86_REGISTER_CH,               QX86_REGISTER_INVALID,
        QX86_REGISTER_BPL,              QX86_REGISTER_R13B,

        QX86_REGISTER_CH,               QX86_REGISTER_INVALID,
        QX86_REGISTER_BPL,              QX86_REGISTER_R13B,

        QX86_REGISTER_CH,               QX86_REGISTER_INVALID,
        QX86_REGISTER_BPL,              QX86_REGISTER_R13B
    }
};

/* Reference: none.  Example: B6 = MOV R6B, Ib.  */
static qx86_rtuple                      qx86_rtuple_R6B
                                        =
{
    "R6B",                              "R6B",

    {
        QX86_REGISTER_DH,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SIL,              QX86_REGISTER_R14B,

        QX86_REGISTER_DH,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SIL,              QX86_REGISTER_R14B,

        QX86_REGISTER_DH,               QX86_REGISTER_INVALID,
        QX86_REGISTER_SIL,              QX86_REGISTER_R14B
    }
};

/* Reference: none.  Example: B7 = MOV R7B, Ib.  */
static qx86_rtuple                      qx86_rtuple_R7B
                                        =
{
    "R7B",                              "R7B",

    {
        QX86_REGISTER_BH,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DIL,              QX86_REGISTER_R15B,

        QX86_REGISTER_BH,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DIL,              QX86_REGISTER_R15B,

        QX86_REGISTER_BH,               QX86_REGISTER_INVALID,
        QX86_REGISTER_DIL,              QX86_REGISTER_R15B
    }
};

/* Reference: none.  Example: D8 C0 = FADD ST0, ST0.  */
static qx86_rtuple                      qx86_rtuple_ST0
                                        =
{
    "ST0",                              "ST0",

    {
        QX86_REGISTER_ST0,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST0,              QX86_REGISTER_ST0,

        QX86_REGISTER_ST0,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST0,              QX86_REGISTER_ST0,

        QX86_REGISTER_ST0,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST0,              QX86_REGISTER_ST0
    }
};

/* Reference: none.  Example: D8 C1 = FADD ST0, ST1.  */
static qx86_rtuple                      qx86_rtuple_ST1
                                        =
{
    "ST1",                              "ST1",

    {
        QX86_REGISTER_ST1,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST1,              QX86_REGISTER_ST1,

        QX86_REGISTER_ST1,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST1,              QX86_REGISTER_ST1,

        QX86_REGISTER_ST1,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST1,              QX86_REGISTER_ST1
    }
};

/* Reference: none.  Example: D8 C2 = FADD ST0, ST2.  */
static qx86_rtuple                      qx86_rtuple_ST2
                                        =
{
    "ST2",                              "ST2",

    {
        QX86_REGISTER_ST2,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST2,              QX86_REGISTER_ST2,

        QX86_REGISTER_ST2,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST2,              QX86_REGISTER_ST2,

        QX86_REGISTER_ST2,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST2,              QX86_REGISTER_ST2
    }
};

/* Reference: none.  Example: D8 C3 = FADD ST0, ST3.  */
static qx86_rtuple                      qx86_rtuple_ST3
                                        =
{
    "ST3",                              "ST3",

    {
        QX86_REGISTER_ST3,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST3,              QX86_REGISTER_ST3,

        QX86_REGISTER_ST3,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST3,              QX86_REGISTER_ST3,

        QX86_REGISTER_ST3,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST3,              QX86_REGISTER_ST3
    }
};

/* Reference: none.  Example: D8 C4 = FADD ST0, ST4.  */
static qx86_rtuple                      qx86_rtuple_ST4
                                        =
{
    "ST4",                              "ST4",

    {
        QX86_REGISTER_ST4,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST4,              QX86_REGISTER_ST4,

        QX86_REGISTER_ST4,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST4,              QX86_REGISTER_ST4,

        QX86_REGISTER_ST4,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST4,              QX86_REGISTER_ST4
    }
};

/* Reference: none.  Example: D8 C5 = FADD ST0, ST5.  */
static qx86_rtuple                      qx86_rtuple_ST5
                                        =
{
    "ST5",                              "ST5",

    {
        QX86_REGISTER_ST5,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST5,              QX86_REGISTER_ST5,

        QX86_REGISTER_ST5,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST5,              QX86_REGISTER_ST5,

        QX86_REGISTER_ST5,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST5,              QX86_REGISTER_ST5
    }
};

/* Reference: none.  Example: D8 C6 = FADD ST0, ST6.  */
static qx86_rtuple                      qx86_rtuple_ST6
                                        =
{
    "ST6",                              "ST6",

    {
        QX86_REGISTER_ST6,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST6,              QX86_REGISTER_ST6,

        QX86_REGISTER_ST6,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST6,              QX86_REGISTER_ST6,

        QX86_REGISTER_ST6,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST6,              QX86_REGISTER_ST6
    }
};

/* Reference: none.  Example: D8 C7 = FADD ST0, ST7.  */
static qx86_rtuple                      qx86_rtuple_ST7
                                        =
{
    "ST7",                              "ST7",

    {
        QX86_REGISTER_ST7,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST7,              QX86_REGISTER_ST7,

        QX86_REGISTER_ST7,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST7,              QX86_REGISTER_ST7,

        QX86_REGISTER_ST7,              QX86_REGISTER_INVALID,
        QX86_REGISTER_ST7,              QX86_REGISTER_ST7
    }
};
