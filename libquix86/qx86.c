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

/* Include public headers.  */
#include "quix86.h"

/* +------------------------------------------------------------------------+
   | Functions                                                              |
   +------------------------------------------------------------------------+ */

/* Function: decode amode operand; qx86-f-decode-amode.c.  */
static int
qx86_decode_amode(qx86_insn *insn, int index);

/* Function: decode A amode operand; qx86-f-decode-amode-a.c.  */
static int
qx86_decode_amode_a(qx86_insn *insn, int index);

/* Function: decode I amode operand; qx86-f-decode-amode-i.c.  */
static int
qx86_decode_amode_i(qx86_insn *insn, int index);

/* Function: decode J amode operand; qx86-f-decode-amode-j.c.  */
static int
qx86_decode_amode_j(qx86_insn *insn, int index);

/* Function: decode M amode operand; qx86-f-decode-amode-m.c.  */
static int
qx86_decode_amode_m(qx86_insn *insn, int index);

/* Function: decode O amode operand; qx86-f-decode-amode-o.c.  */
static int
qx86_decode_amode_o(qx86_insn *insn, int index);

/* Function: decode X amode operand; qx86-f-decode-amode-x.c.  */
static int
qx86_decode_amode_x(qx86_insn *insn, int index);

/* Function: decode Y amode operand; qx86-f-decode-amode-y.c.  */
static int
qx86_decode_amode_y(qx86_insn *insn, int index);

/* Function: decode implicit-1 operand; qx86-f-decode-implicit-1.c.  */
static int
qx86_decode_implicit_1(qx86_insn *insn, int index);

/* Function: decode ModRM and SIB; qx86-f-decode-modifiers.c.  */
static int
qx86_decode_modifiers(qx86_insn *insn);

/* Function: decode opcode; qx86-f-decode-opcode.c.  */
static int
qx86_decode_opcode(qx86_insn *insn);

/* Function: decode operand; qx86-f-decode-operand.c.  */
static int
qx86_decode_operand(qx86_insn *insn, int index);

/* Function: decode prefixes; qx86-f-decode-prefixes.c.  */
static int
qx86_decode_prefixes(qx86_insn *insn);

/* Function: decode rtuple operand; qx86-f-decode-rtuple.c.  */
static int
qx86_decode_rtuple(qx86_insn *insn, int index);

/* Function: choose an opcode map item; qx86-f-opcode-map-choose.c.  */
static int
qx86_opcode_map_choose(qx86_insn *insn, qx86_opcode_map *map, qx86_opcode_map_item **item);

/* Function: print items to buffer; qx86-f-print.c.  */
static int
qx86_print(qx86_print_item *item, char *buffer, int *bufferSize);

/* +------------------------------------------------------------------------+
   | Globals                                                                |
   +------------------------------------------------------------------------+ */

/* Private data: addressing modes; qx86-d-amode.c.  */
static qx86_amode                       qx86_amode_A;
static qx86_amode                       qx86_amode_C;
static qx86_amode                       qx86_amode_D;
static qx86_amode                       qx86_amode_E;
static qx86_amode                       qx86_amode_G;
static qx86_amode                       qx86_amode_I;
static qx86_amode                       qx86_amode_J;
static qx86_amode                       qx86_amode_M;
static qx86_amode                       qx86_amode_N;
static qx86_amode                       qx86_amode_O;
static qx86_amode                       qx86_amode_P;
static qx86_amode                       qx86_amode_Q;
static qx86_amode                       qx86_amode_R;
static qx86_amode                       qx86_amode_S;
static qx86_amode                       qx86_amode_U;
static qx86_amode                       qx86_amode_V;
static qx86_amode                       qx86_amode_W;
static qx86_amode                       qx86_amode_X;
static qx86_amode                       qx86_amode_Y;

/* Private data: character case flip table; qx86-d-flip-case.c.  */
static char                             qx86_flip_case[128];

/* Private data: ModRM decode tables; qx86-d-modrm.c.  */
static int *                            qx86_modrm_base[4];
static int *                            qx86_modrm_disp[4];
static int *                            qx86_modrm_index[4];
static int *                            qx86_modrm_scale[4];

static int *                            qx86_modrm_rindex[QX86_RCLASS_COUNT];

/* Private data: mnemonic table; qx86-d-mtab.c; generated.  */
//static qx86_mtab_item                   qx86_mtab[QX86_MNEMONIC_COUNT];

/* Private data: opcode maps; qx86-d-opcode-map.c; generated.  */
static qx86_opcode_map *                qx86_opcode_maps[QX86_OPCODE_ESCAPE_COUNT];

/* Private data: register table; qx86-d-rtab.c.  */
//static qx86_rtab_item                   qx86_rtab[QX86_REGISTER_COUNT];

/* Private data: register tuples; qx86-d-rtuple.c.  */
static qx86_rtuple                      qx86_rtuple_AL;
static qx86_rtuple                      qx86_rtuple_CL;

static qx86_rtuple                      qx86_rtuple_AX;
static qx86_rtuple                      qx86_rtuple_DX;

static qx86_rtuple                      qx86_rtuple_eAX;
static qx86_rtuple                      qx86_rtuple_eCX;
static qx86_rtuple                      qx86_rtuple_eDX;
static qx86_rtuple                      qx86_rtuple_eBX;
static qx86_rtuple                      qx86_rtuple_eSI;
static qx86_rtuple                      qx86_rtuple_eDI;
static qx86_rtuple                      qx86_rtuple_eSP;
static qx86_rtuple                      qx86_rtuple_eBP;

static qx86_rtuple                      qx86_rtuple_rAX;
static qx86_rtuple                      qx86_rtuple_rSI;
static qx86_rtuple                      qx86_rtuple_rDI;

static qx86_rtuple                      qx86_rtuple_r0;
static qx86_rtuple                      qx86_rtuple_r1;
static qx86_rtuple                      qx86_rtuple_r2;
static qx86_rtuple                      qx86_rtuple_r3;
static qx86_rtuple                      qx86_rtuple_r4;
static qx86_rtuple                      qx86_rtuple_r5;
static qx86_rtuple                      qx86_rtuple_r6;
static qx86_rtuple                      qx86_rtuple_r7;

static qx86_rtuple                      qx86_rtuple_R0B;
static qx86_rtuple                      qx86_rtuple_R1B;
static qx86_rtuple                      qx86_rtuple_R2B;
static qx86_rtuple                      qx86_rtuple_R3B;
static qx86_rtuple                      qx86_rtuple_R4B;
static qx86_rtuple                      qx86_rtuple_R5B;
static qx86_rtuple                      qx86_rtuple_R6B;
static qx86_rtuple                      qx86_rtuple_R7B;

static qx86_rtuple                      qx86_rtuple_ST0;
static qx86_rtuple                      qx86_rtuple_ST1;
static qx86_rtuple                      qx86_rtuple_ST2;
static qx86_rtuple                      qx86_rtuple_ST3;
static qx86_rtuple                      qx86_rtuple_ST4;
static qx86_rtuple                      qx86_rtuple_ST5;
static qx86_rtuple                      qx86_rtuple_ST6;
static qx86_rtuple                      qx86_rtuple_ST7;

static qx86_rtuple                      qx86_rtuple_ES;
static qx86_rtuple                      qx86_rtuple_CS;
static qx86_rtuple                      qx86_rtuple_SS;
static qx86_rtuple                      qx86_rtuple_DS;
static qx86_rtuple                      qx86_rtuple_FS;
static qx86_rtuple                      qx86_rtuple_GS;

/* Private data: SIB decode tables; qx86-d-sib.c.  */
static int *                            qx86_sib_base[4];
static int *                            qx86_sib_base_special[4];
static int *                            qx86_sib_index[4];

/* Private data: address and operand size tables; qx86-d-size.c.  */
static int *                            qx86_address_size[4];
static int *                            qx86_operand_size[4];

/* Private data: size tuples; qx86-d-stuple.c.  */
static qx86_stuple                      qx86_stuple_a;
static qx86_stuple                      qx86_stuple_b;
static qx86_stuple                      qx86_stuple_d;
static qx86_stuple                      qx86_stuple_dq;
static qx86_stuple                      qx86_stuple_f;
static qx86_stuple                      qx86_stuple_fe;
static qx86_stuple                      qx86_stuple_fx;
static qx86_stuple                      qx86_stuple_i;
static qx86_stuple                      qx86_stuple_p;
static qx86_stuple                      qx86_stuple_pd;
static qx86_stuple                      qx86_stuple_ps;
static qx86_stuple                      qx86_stuple_q;
static qx86_stuple                      qx86_stuple_s;
static qx86_stuple                      qx86_stuple_sb;
static qx86_stuple                      qx86_stuple_sd;
static qx86_stuple                      qx86_stuple_se;
static qx86_stuple                      qx86_stuple_ss;
static qx86_stuple                      qx86_stuple_v;
static qx86_stuple                      qx86_stuple_w;
static qx86_stuple                      qx86_stuple_z;

/* +------------------------------------------------------------------------+
   | Inline Functions                                                       |
   +------------------------------------------------------------------------+ */

#include <qx86-f-extract-address.inl>
#include <qx86-f-pump.inl>
#include <qx86-f-unpump.inl>

/* +------------------------------------------------------------------------+
   | Function Implementations                                               |
   +------------------------------------------------------------------------+ */

#include <qx86-d-amode.c>
#include <qx86-d-flip-case.c>
#include <qx86-d-modrm.c>
#include <qx86-d-mtab.c>
#include <qx86-d-opcode-map.c>
#include <qx86-d-rtab.c>
#include <qx86-d-rtuple.c>
#include <qx86-d-sib.c>
#include <qx86-d-size.c>
#include <qx86-d-stuple.c>
#include <qx86-f-calculate-effective-address.c>
#include <qx86-f-calculate-linear-address.c>
#include <qx86-f-decode.c>
#include <qx86-f-decode-amode.c>
#include <qx86-f-decode-amode-a.c>
#include <qx86-f-decode-amode-i.c>
#include <qx86-f-decode-amode-j.c>
#include <qx86-f-decode-amode-m.c>
#include <qx86-f-decode-amode-o.c>
#include <qx86-f-decode-amode-x.c>
#include <qx86-f-decode-amode-y.c>
#include <qx86-f-decode-implicit-1.c>
#include <qx86-f-decode-modifiers.c>
#include <qx86-f-decode-opcode.c>
#include <qx86-f-decode-operand.c>
#include <qx86-f-decode-prefixes.c>
#include <qx86-f-decode-rtuple.c>
#include <qx86-f-opcode-map-choose.c>
#include <qx86-f-print.c>
#include <qx86-f-print-intel.c>
