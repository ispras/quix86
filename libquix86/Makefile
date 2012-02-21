## +------------------------------------------------------------------------+
## | quix86                                                                 |
## +------------------------------------------------------------------------+
## | This file is part of quix86, an x86-64 instruction decoder.            |
## |                                                                        |
## | Copyright (C) 2011 Institute for System Programming of Russian Academy |
## | of Sciences.                                                           |
## |                                                                        |
## | Contact e-mail: <unicluster@ispras.ru>.                                |
## |                                                                        |
## | quix86 is free software: you can redistribute it and/or modify it      |
## | under the terms of the GNU Lesser General Public License as published  |
## | by the Free Software Foundation, either version 3 of the License, or   |
## | (at your option) any later version.                                    |
## |                                                                        |
## | quix86 is distributed in the hope that it will be useful, but WITHOUT  |
## | ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  |
## | FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public   |
## | License for more details.                                              |
## |                                                                        |
## | You should have received a copy of the GNU Lesser General Public       |
## | License along with quix86. If not, see <http://www.gnu.org/licenses/>. |
## +------------------------------------------------------------------------+

AR										= ar
AWK										= awk
CC										= cc
RANLIB									= ranlib

PREFIX_O								=
PREFIX_SHARED							= lib
PREFIX_STATIC							= lib

SUFFIX_O								= .o
SUFFIX_SHARED							= .so
SUFFIX_STATIC							= .a

CFLAGS									= -std=c99 -W -Wall -Wextra -Werror -pedantic -g
CFLAGS_SHARED							= $(CFLAGS) $(CPPFLAGS_SHARED) -shared -fPIC
CFLAGS_STATIC							= $(CFLAGS) $(CPPFLAGS_STATIC)

CPPFLAGS								= -DQUIX86_BUILD -I.
CPPFLAGS_SHARED							= $(CPPFLAGS) -DQUIX86_SHARED
CPPFLAGS_STATIC							= $(CPPFLAGS) -DQUIX86_STATIC

quix86_h_FILES							= qx86-e-cc.h						\
										  qx86-e-defect.h					\
										  qx86-e-disp.h						\
										  qx86-e-error.h					\
										  qx86-e-iclass.h					\
										  qx86-e-limit.h					\
										  qx86-e-mattribute.h				\
										  qx86-e-mnemonic.h					\
										  qx86-e-modrm-field.h				\
										  qx86-e-opcode-escape.h			\
										  qx86-e-opcode-prefix.h			\
										  qx86-e-operand-attribute.h		\
										  qx86-e-operand-form-type.h		\
										  qx86-e-operand-type.h				\
										  qx86-e-rclass.h					\
										  qx86-e-register.h					\
										  qx86-e-scale.h					\
										  qx86-e-size.h						\
										  qx86-e-subreg.h					\
										  qx86-t-amode.h					\
										  qx86-t-callback.h					\
										  qx86-t-insn.h						\
										  qx86-t-insn-attributes.h			\
										  qx86-t-insn-modifiers.h			\
										  qx86-t-operand.h					\
										  qx86-t-operand-far-pointer.h		\
										  qx86-t-operand-form.h				\
										  qx86-t-operand-form-amode.h		\
										  qx86-t-operand-form-rtuple.h		\
										  qx86-t-operand-form-union.h		\
										  qx86-t-operand-immediate.h		\
										  qx86-t-operand-jump-offset.h		\
										  qx86-t-operand-memory.h			\
										  qx86-t-operand-register.h			\
										  qx86-t-operand-union.h			\
										  qx86-t-print-options-intel.h		\
										  qx86-t-rtuple.h					\
										  qx86-t-stuple.h

quix86_c_FILES							= qx86-d-amode.c					\
										  qx86-d-flip-case.c				\
										  qx86-d-modrm.c					\
										  qx86-d-mtab.c						\
										  qx86-d-opcode-map.c				\
										  qx86-d-rtab.c						\
										  qx86-d-rtuple.c					\
										  qx86-d-sib.c						\
										  qx86-d-size.c						\
										  qx86-d-stuple.c					\
										  qx86-e-opcode-map-index.h			\
										  qx86-e-opcode-map-item-code.h		\
										  qx86-f-calculate-effective-address.c \
										  qx86-f-calculate-linear-address.c	\
										  qx86-f-decode.c					\
										  qx86-f-decode-amode.c				\
										  qx86-f-decode-amode-a.c			\
										  qx86-f-decode-amode-i.c			\
										  qx86-f-decode-amode-j.c			\
										  qx86-f-decode-amode-m.c			\
										  qx86-f-decode-amode-o.c			\
										  qx86-f-decode-amode-x.c			\
										  qx86-f-decode-amode-y.c			\
										  qx86-f-decode-implicit-1.c		\
										  qx86-f-decode-modifiers.c			\
										  qx86-f-decode-opcode.c			\
										  qx86-f-decode-operand.c			\
										  qx86-f-decode-prefixes.c			\
										  qx86-f-decode-rtuple.c			\
										  qx86-f-extract-address.inl		\
										  qx86-f-opcode-map-choose.c		\
										  qx86-f-minfo.c					\
										  qx86-f-minfo-rename.c				\
										  qx86-f-print.c  					\
										  qx86-f-print-intel.c				\
										  qx86-f-pump.inl					\
										  qx86-f-rinfo.c					\
										  qx86-f-rinfo-rename.c				\
										  qx86-f-unpump.inl					\
										  qx86-t-ctx.h						\
										  qx86-t-mtab-item.h				\
										  qx86-t-rtab-item.h

mtab_FILES								= qx86-d-mtab/3dnow.mtab			\
										  qx86-d-mtab/aes.mtab				\
										  qx86-d-mtab/base.mtab				\
										  qx86-d-mtab/clmul.mtab			\
										  qx86-d-mtab/mmx.mtab				\
										  qx86-d-mtab/smx.mtab				\
										  qx86-d-mtab/sse.mtab				\
										  qx86-d-mtab/sse2.mtab				\
										  qx86-d-mtab/sse3.mtab				\
										  qx86-d-mtab/sse4.1.mtab			\
										  qx86-d-mtab/sse4.2.mtab			\
										  qx86-d-mtab/sse4a.mtab			\
										  qx86-d-mtab/ssse3.mtab			\
										  qx86-d-mtab/svm.mtab				\
										  qx86-d-mtab/system.mtab			\
										  qx86-d-mtab/vtx.mtab				\
										  qx86-d-mtab/x87.mtab

.PHONY:									default
default:								all qx86test

qx86test:								quix86.h $(PREFIX_STATIC)quix86$(SUFFIX_STATIC) qx86test.c
	@echo "Building qx86test (XXX: remove this before release)"
	@$(CC) $(CFLAGS_STATIC) -o $@ qx86test.c $(PREFIX_STATIC)quix86$(SUFFIX_STATIC)

.PHONY:									all
all:									amalgamation shared static

.PHONY:									clean
clean:
	@echo "CLEAN   qx86-e-mnemonic.h qx86-d-mtab.c"
	@-rm -f qx86-e-mnemonic.h qx86-d-mtab.c
	@echo "CLEAN   quix86.h quix86.c"
	@-rm -f quix86.h quix86.c
	@echo "CLEAN   $(PREFIX_O)quix86$(SUFFIX_O)"
	@-rm -f $(PREFIX_O)quix86$(SUFFIX_O)
	@echo "CLEAN   $(PREFIX_SHARED)quix86$(SUFFIX_SHARED)"
	@-rm -f $(PREFIX_SHARED)quix86$(SUFFIX_SHARED)
	@echo "CLEAN   $(PREFIX_STATIC)quix86$(SUFFIX_STATIC)"
	@-rm -f $(PREFIX_STATIC)quix86$(SUFFIX_STATIC)
	@echo "Cleaning up our XXX qx86test"
	@-rm -f qx86test

.PHONY:									amalgamation
amalgamation:							quix86.h quix86.c

.PHONY:									shared
shared:									$(PREFIX_SHARED)quix86$(SUFFIX_SHARED)

.PHONY:									static
static:									$(PREFIX_STATIC)quix86$(SUFFIX_STATIC)

$(PREFIX_SHARED)quix86$(SUFFIX_SHARED):	quix86.h quix86.c
	@echo "CCLD    $@"
	@$(CC) $(CFLAGS_SHARED) -o $@ quix86.c

$(PREFIX_STATIC)quix86$(SUFFIX_STATIC):	quix86$(SUFFIX_O)
	@echo "AR      $@"
	@$(AR) rcs $@ $<
	@echo "RANLIB  $@"
	@$(RANLIB) $@

$(PREFIX_O)quix86$(SUFFIX_O):			quix86.h quix86.c
	@echo "CC      $@"
	@$(CC) $(CFLAGS_STATIC) -c -o $@ quix86.c

quix86.h:								../scripts/amalgamate.awk qx86.h $(quix86_h_FILES)
	@echo "GEN     quix86.h"
	@$(AWK) -f ../scripts/amalgamate.awk qx86.h > quix86.h

quix86.c:								../scripts/amalgamate.awk qx86.c $(quix86_c_FILES)
	@echo "GEN     quix86.c"
	@$(AWK) -f ../scripts/amalgamate.awk qx86.c > quix86.c

qx86-e-mnemonic.h qx86-d-mtab.c:		../scripts/make-mtab.awk $(mtab_FILES)
	@echo "GEN     qx86-e-mnemonic.h qx86-d-mtab.c"
	@$(AWK) -f ../scripts/make-mtab.awk $(mtab_FILES)
