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

#ifndef QUIX86_H
#define QUIX86_H

/**
 * Major <tt>quix86</tt> version number.
 *
 * \author                              icee
 * \since                               1.1
 */
#define QX86_MAJOR_VERSION              1

/**
 * Minor <tt>quix86</tt> version number.
 *
 * \author                              icee
 * \since                               1.1
 */
#define QX86_MINOR_VERSION              1

/* Provide definitions for INT8..INT64 and UINT8..UINT64.  */
#ifdef _MSC_VER
    /* Definitions for INT8..INT64.  */
#   define QX86_INT8                    __int8
#   define QX86_INT16                   __int16
#   define QX86_INT32                   __int32
#   define QX86_INT64                   __int64

    /* Definitions for UINT8..UINT64.  */
#   define QX86_UINT8                   unsigned __int8
#   define QX86_UINT16                  unsigned __int16
#   define QX86_UINT32                  unsigned __int32
#   define QX86_UINT64                  unsigned __int64
#else
    /* No built-in types.  See if we have one of the standard headers.  */
#   if defined(HAVE_INTTYPES_H) || defined(HAVE_STDINT_H)
        /* Prefer <stdint.h> as it's somewhat smaller.  */
#       ifdef HAVE_STDINT_H
            /* Include <stdint.h>.  */
#           include <stdint.h>
#       else
            /* Include <inttypes.h> instead.  */
#           include <inttypes.h>
#       endif

        /* Definitions for INT8..INT64.  */
#       define QX86_INT8                int8_t
#       define QX86_INT16               int16_t
#       define QX86_INT32               int32_t
#       define QX86_INT64               int64_t

        /* Definitions for UINT8..UINT64.  */
#       define QX86_UINT8               uint8_t
#       define QX86_UINT16              uint16_t
#       define QX86_UINT32              uint32_t
#       define QX86_UINT64              uint64_t
#   else
        /* Likely definitions for INT8..INT64.  */
#       define QX86_INT8                signed char
#       define QX86_INT16               short
#       define QX86_INT32               int
#       define QX86_INT64               long long

        /* Likely definitions for UINT8..UINT64.  */
#       define QX86_UINT8               unsigned char
#       define QX86_UINT16              unsigned short
#       define QX86_UINT32              unsigned int
#       define QX86_UINT64              unsigned long long
#   endif
#endif

/* Provide wrappers around const and inline for compilers that don't support
   C99.  */
#ifdef _MSC_VER
    /* Microsoft Visual C is not C99-conformant.  Use alternative keywords.  */
#   define QX86_CONST                   const
#   define QX86_INLINE                  __inline
#   define QX86_RESTRICT                /* ILB */
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
    /* C99 supported.  */
#   define QX86_CONST                   const
#   define QX86_INLINE                  inline
#   define QX86_RESTRICT                restrict
#elif defined(__GNUC__) && (__GNUC__ >= 4)
    /* GNU C supported. */
#   define QX86_CONST                   const
#   define QX86_INLINE                  inline
#   define QX86_RESTRICT                restrict
#elif defined(__cplusplus)
    /* C++ mode supports const and inline.  */
#   define QX86_CONST                   const
#   define QX86_INLINE                  inline
#   define QX86_RESTRICT                /* ILB */
#else
    /* Assume none of the qualifiers is supported.  */
#   define QX86_CONST                   /* ILB */
#   define QX86_INLINE                  /* ILB */
#   define QX86_RESTRICT                /* ILB */
#endif

/* Wrap declarations in extern "C" if needed.  */
#ifdef __cplusplus
    /* Need wrapper.  */
#   define QX86_EXTERN_C                extern "C"
#else
    /* No wrapper required.  */
#   define QX86_EXTERN_C                /* ILB */
#endif

/**
 * 8-bit signed integer type.
 *
 * \author                              icee
 * \since                               1.0
 */
typedef QX86_INT8                       qx86_int8;

/**
 * 16-bit signed integer type.
 *
 * \author                              icee
 * \since                               1.0
 */
typedef QX86_INT16                      qx86_int16;

/**
 * 32-bit signed integer type.
 *
 * \author                              icee
 * \since                               1.0
 */
typedef QX86_INT32                      qx86_int32;

/**
 * 64-bit signed integer type.
 *
 * \author                              icee
 * \since                               1.0
 */
typedef QX86_INT64                      qx86_int64;

/**
 * 8-bit unsigned integer type.
 *
 * \author                              icee
 * \since                               1.0
 */
typedef QX86_UINT8                      qx86_uint8;

/**
 * 16-bit unsigned integer type.
 *
 * \author                              icee
 * \since                               1.0
 */
typedef QX86_UINT16                     qx86_uint16;

/**
 * 32-bit unsigned integer type.
 *
 * \author                              icee
 * \since                               1.0
 */
typedef QX86_UINT32                     qx86_uint32;

/**
 * 64-bit unsigned integer type.
 *
 * \author                              icee
 * \since                               1.0
 */
typedef QX86_UINT64                     qx86_uint64;

/* Public API structure declarations.  */
typedef struct qx86_amode               qx86_amode;
typedef struct qx86_ctx                 qx86_ctx;
typedef struct qx86_insn                qx86_insn;
typedef struct qx86_insn_attributes     qx86_insn_attributes;
typedef struct qx86_insn_modifiers      qx86_insn_modifiers;
typedef struct qx86_print_options_intel qx86_print_options_intel;
typedef struct qx86_mtab_item           qx86_mtab_item;
typedef struct qx86_opcode_map          qx86_opcode_map;
typedef struct qx86_opcode_map_item     qx86_opcode_map_item;
typedef struct qx86_operand             qx86_operand;
typedef struct qx86_operand_far_pointer qx86_operand_far_pointer;
typedef struct qx86_operand_form        qx86_operand_form;
typedef struct qx86_operand_form_amode  qx86_operand_form_amode;
typedef struct qx86_operand_form_rtuple qx86_operand_form_rtuple;
typedef struct qx86_operand_immediate   qx86_operand_immediate;
typedef struct qx86_operand_jump_offset qx86_operand_jump_offset;
typedef struct qx86_operand_memory      qx86_operand_memory;
typedef struct qx86_operand_register    qx86_operand_register;
typedef struct qx86_print_item          qx86_print_item;
typedef struct qx86_rtab_item           qx86_rtab_item;
typedef struct qx86_rtuple              qx86_rtuple;
typedef struct qx86_stuple              qx86_stuple;

/* Public API union declarations.  */
typedef union qx86_operand_union        qx86_operand_union;
typedef union qx86_operand_form_union   qx86_operand_form_union;

/* Public API enumerations.  */
#include <qx86-e-defect.h>
#include <qx86-e-disp.h>
#include <qx86-e-error.h>
#include <qx86-e-iclass.h>
#include <qx86-e-limit.h>
#include <qx86-e-mnemonic.h>
#include <qx86-e-mattribute.h>
#include <qx86-e-modrm-field.h>
#include <qx86-e-opcode-escape.h>
#include <qx86-e-opcode-map-index.h>
#include <qx86-e-opcode-map-item-code.h>
#include <qx86-e-operand-attribute.h>
#include <qx86-e-operand-form-type.h>
#include <qx86-e-operand-type.h>
#include <qx86-e-rclass.h>
#include <qx86-e-register.h>
#include <qx86-e-scale.h>
#include <qx86-e-size.h>
#include <qx86-e-subreg.h>

/* Public API structures.  */
#include <qx86-t-amode.h>
#include <qx86-t-callback.h>
#include <qx86-t-ctx.h>
#include <qx86-t-insn.h>
#include <qx86-t-insn-attributes.h>
#include <qx86-t-insn-modifiers.h>
#include <qx86-t-mtab-item.h>
#include <qx86-t-opcode-map.h>
#include <qx86-t-opcode-map-item.h>
#include <qx86-t-operand-far-pointer.h>
#include <qx86-t-operand-form-amode.h>
#include <qx86-t-operand-form-rtuple.h>
#include <qx86-t-operand-form-union.h>
#include <qx86-t-operand-form.h>
#include <qx86-t-operand-immediate.h>
#include <qx86-t-operand-jump-offset.h>
#include <qx86-t-operand-memory.h>
#include <qx86-t-operand-register.h>
#include <qx86-t-operand-union.h>
#include <qx86-t-operand.h>
#include <qx86-t-print-item.h>
#include <qx86-t-print-options-intel.h>
#include <qx86-t-rtab-item.h>
#include <qx86-t-rtuple.h>
#include <qx86-t-stuple.h>

/**
 * Extract the <em>mod</em> ModRM field value.
 *
 * \param                               modrm
 *                                      ModRM octet value.
 *
 * \return                              ModRM <em>mod</em> field value.
 *
 * \author                              icee
 * \since                               1.0
 */
#define QX86_MODRM_MOD(modrm)           ((qx86_uint8) ((modrm) >> 6))

/**
 * Extract the <em>reg</em> ModRM field value.
 *
 * \param                               modrm
 *                                      ModRM octet value.
 *
 * \return                              ModRM <em>reg</em> field value.
 *
 * \author                              icee
 * \since                               1.0
 */
#define QX86_MODRM_REG(modrm)           ((qx86_uint8) (((modrm) >> 3) & 7))

/**
 * Extract the <em>r/m</em> ModRM field value.
 *
 * \param                               modrm
 *                                      ModRM octet value.
 *
 * \return                              ModRM <em>rm</em> field value.
 *
 * \author                              icee
 * \since                               1.0
 */
#define QX86_MODRM_RM(modrm)            ((qx86_uint8) ((modrm) & 7))

/**
 * Extract the <em>b</em> REX field value.
 *
 * \param                               rex
 *                                      REX octet value.
 *
 * \return                              REX <em>b</em> field value.
 *
 * \author                              icee
 * \since                               1.0
 */
#define QX86_REX_B(rex)                 ((qx86_uint8) (0 != ((rex) & 1)))

/**
 * Extract the <em>r</em> REX field value.
 *
 * \param                               rex
 *                                      REX octet value.
 *
 * \return                              REX <em>r</em> field value.
 *
 * \author                              icee
 * \since                               1.0
 */
#define QX86_REX_R(rex)                 ((qx86_uint8) (0 != ((rex) & 4)))

/**
 * Extract the <em>w</em> REX field value.
 *
 * \param                               rex
 *                                      REX octet value.
 *
 * \return                              REX <em>w</em> field value.
 *
 * \author                              icee
 * \since                               1.0
 */
#define QX86_REX_W(rex)                 ((qx86_uint8) (0 != ((rex) & 8)))

/**
 * Extract the <em>x</em> REX field value.
 *
 * \param                               rex
 *                                      REX octet value.
 *
 * \return                              REX <em>x</em> field value.
 *
 * \author                              icee
 * \since                               1.0
 */
#define QX86_REX_X(rex)                 ((qx86_uint8) (0 != ((rex) & 2)))

/**
 * Extract the <em>base</em> SIB field value.
 *
 * \param                               sib
 *                                      SIB octet value.
 *
 * \return                              SIB <em>base</em> field value.
 *
 * \author                              icee
 * \since                               1.0
 */
#define QX86_SIB_BASE(sib)              ((qx86_uint8) ((sib) & 7))

/**
 * Extract the <em>index</em> SIB field value.
 *
 * \param                               sib
 *                                      SIB octet value.
 *
 * \return                              SIB <em>index</em> field value.
 *
 * \author                              icee
 * \since                               1.0
 */
#define QX86_SIB_INDEX(sib)             ((qx86_uint8) (((sib) >> 3) & 7))

/**
 * Extract the <em>scale</em> SIB field value.
 *
 * \param                               sib
 *                                      SIB octet value.
 *
 * \return                              SIB <em>scale</em> field value.
 *
 * \author                              icee
 * \since                               1.0
 */
#define QX86_SIB_SCALE(sib)             ((qx86_uint8) ((sib) >> 6))

/**
 * Convert a #qx86_size enumerator to number of octets.  The \a size value must
 * be valid.
 *
 * \param                               size
 *                                      A #qx86_size enumerator.
 *
 * \return                              Number of octets.
 *
 * \author                              icee
 * \since                               1.0
 */
#define QX86_SIZE_OCTETS(size)          (2 << (size))

/**
 * Calculate effective address of an <em>x86</em> memory operand.
 *
 * TODO: documentation.
 *
 * \author                              icee
 * \since                               1.0
 */
QX86_EXTERN_C int
qx86_calculate_effective_address(QX86_CONST qx86_insn *insn, int operandIndex, qx86_uint64 *address);

/**
 * Calculate linear address of an <em>x86</em> memory operand.
 *
 * TODO: documentation.
 *
 * \author                              icee
 * \since                               1.0
 */
QX86_EXTERN_C int
qx86_calculate_linear_address(QX86_CONST qx86_insn *insn, int operandIndex, qx86_uint64 *address);

/**
 * Decode an <em>x86</em> instruction.
 *
 * TODO: documentation.
 *
 * \author                              icee
 * \since                               1.0
 */
QX86_EXTERN_C int
qx86_decode(qx86_insn *insn, int processorMode, QX86_CONST void *ptr, int ptrSize);

/**
 * Get <em>x86</em> mnemonic information.
 *
 * \param                               mindex
 *                                      Mnemonic index, one of #qx86_mnemonic
 *                                      enumerators.
 *
 * \return                              Pointer to mnemonic structure; \c NULL
 *                                      if \a mindex is invalid.
 *
 * \author                              icee
 * \since                               1.1
 */
QX86_EXTERN_C QX86_CONST qx86_mtab_item *
qx86_minfo(int mindex);

/**
 * Print a decoded <em>x86</em> instruction using the Intel format.
 *
 * TODO: documentation.
 *
 * \param                               insn
 *                                      Instruction to print.
 * \param                               options
 *                                      Printer options.
 * \param[out]                          buffer
 *                                      Pre-allocated buffer to print to.
 * \param[in,out]                       bufferSize
 *                                      TODO.
 *
 * \return                              TODO.
 *
 * \author                              icee
 * \since                               1.0
 */
QX86_EXTERN_C int
qx86_print_intel(QX86_CONST qx86_insn *insn, QX86_CONST qx86_print_options_intel *options, char *buffer, int *bufferSize);

/**
 * Get <em>x86</em> register information.
 *
 * \param                               rindex
 *                                      Register index, one of #qx86_register
 *                                      enumerators.
 *
 * \return                              Pointer to register structure; \c NULL
 *                                      if \a rindex is invalid.
 *
 * \author                              icee
 * \since                               1.1
 */
QX86_EXTERN_C QX86_CONST qx86_rtab_item *
qx86_rinfo(int rindex);

#endif
