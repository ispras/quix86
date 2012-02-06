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

int
qx86_print_intel(QX86_CONST qx86_insn *insn, QX86_CONST qx86_print_options_intel *options, char *buffer, int *bufferSize)
{
    qx86_print_item                     items[64];
    qx86_print_item *                   item;

    QX86_CONST qx86_operand *           operand;

    int                                 i;
    int                                 printPlus;

    /* Test insn, options, buffer, and bufferSize to be non-NULL.  */
    if (!insn || !options || !buffer || !bufferSize) return QX86_E_API;

    /* Start with item pointing at items.  */
    item = items;

    /* Print lock prefix.  */
    if (insn->attributes.interlocked)
    {
        item->number                    = 0;
        item->string                    = "LOCK ";
        item                            = item + 1;
    }

    /* Print repeat prefixes.  */
    if (insn->modifiers.repeatPrefix)
    {
        /* Do print.  */
        if (qx86_mtab[insn->mnemonic].attributes & QX86_MATTRIBUTE_REP)
        {
            /* Test for REPZ/REPNZ support.  */
            if (qx86_mtab[insn->mnemonic].attributes & QX86_MATTRIBUTE_REPZ)
            {
                /* Use REPZ or REPNZ.  */
                if (0xF2 == insn->modifiers.repeatPrefix)
                {
                    /* REPNZ.  */
                    item->number        = 0;
                    item->string        = "REPNZ ";
                    item                = item + 1;
                }
                else
                {
                    /* REPZ.  */
                    item->number        = 0;
                    item->string        = "REPZ ";
                    item                = item + 1;
                }
            }
            else
            {
                /* Use plain REP.  */
                item->number            = 0;
                item->string            = "REP ";
                item                    = item + 1;
            }
        }
    }

    /* Print instruction mnemonic.  */
    item->number                        = 0;
    item->string                        = qx86_mtab[insn->mnemonic].name;
    item                                = item + 1;

    /* Print operands.  */
    for (i = 0, operand = insn->operands; i < insn->operandCount; ++i, ++operand)
    {
        /* Print a comma before the operand if needed.  */
        if (i)
        {
            /* Print it.  */
            item->number                = 0;
            item->string                = ", ";
            item                        = item + 1;
        }
        else
        {
            /* Otherwise, print whitespace before first operand.  */
            item->number                = 0;
            item->string                = " ";
            item                        = item + 1;
        }

        /* Switch operand type.  */
        switch (operand->ot)
        {
        case QX86_OPERAND_TYPE_FAR_POINTER:
            /* Print segment value.  */
            item->number                = operand->u.f.selector;
            item->numberSize            = 2;
            item->string                = 0;
            item                        = item + 1;

            /* Add colon.  */
            item->number                = 0;
            item->string                = ":";
            item                        = item + 1;

            /* Print offset value.  */
            item->number                = operand->u.f.offset;
            item->numberSize            = operand->u.f.offsetSize;
            item->string                = 0;
            item                        = item + 1;

            /* Done.  */
            break;

        case QX86_OPERAND_TYPE_IMMEDIATE:
            /* Print immediate value.  */
            item->number                = operand->u.i.value;
            item->numberSize            = operand->u.i.valueSize;
            item                        = item + 1;

            /* Done.  */
            break;

        case QX86_OPERAND_TYPE_JUMP_OFFSET:
            /* Print jump offset value.  */
            item->number                = operand->u.j.offset;
            item->numberSize            = operand->u.j.offsetSize;
            item                        = item + 1;

            /* Done.  */
            break;

        case QX86_OPERAND_TYPE_MEMORY:
            /* Print atom name.  */
            item->number                = 0;
            item->string                = insn->operandForms[i]->u.a.stuple->atoms[insn->attributes.operandSize];
            item                        = item + 1;

            /* Print "PTR." */
            item->number                = 0;
            item->string                = " PTR ";
            item                        = item + 1;

            /* Print segment register name if overridden.  */
            if (QX86_REGISTER_NONE != insn->modifiers.sriOverride)
            {
                /* Overridden.  Print name.  */
                item->number            = 0;
                item->string            = qx86_rtab[operand->u.m.sri].name;
                item                    = item + 1;

                /* Print colon.  */
                item->number            = 0;
                item->string            = ":";
                item                    = item + 1;
            }

            /* Open brackets.  */
            item->number                = 0;
            item->string                = "[";
            item                        = item + 1;

            /* Test if a base is used.  */
            if (QX86_REGISTER_NONE != operand->u.m.bri)
            {
                /* Print it.  */
                item->number            = 0;
                item->string            = qx86_rtab[operand->u.m.bri].name;
                item                    = item + 1;

                /* Need to print plus before a component to follow.  */
                printPlus               = 1;
            }
            else
            {
                /* No plus required.  */
                printPlus               = 0;
            }

            /* Test if an index is used.  */
            if (QX86_REGISTER_NONE != operand->u.m.iri)
            {
                /* Print a plus if needed.  */
                if (printPlus)
                {
                    /* Do print.  */
                    item->number        = 0;
                    item->string        = " + ";
                    item                = item + 1;
                }

                /* Print index register name.  */
                item->number            = 0;
                item->string            = qx86_rtab[operand->u.m.iri].name;
                item                    = item + 1;

                /* Test for scale different than 1.  */
                switch (operand->u.m.scale)
                {
                case QX86_SCALE_NONE:
                    /* No action.  */
                    break;

                case QX86_SCALE_X2:
                    /* Print X2 scale.  */
                    item->number        = 0;
                    item->string        = " * 2";
                    item                = item + 1;

                    /* Done.  */
                    break;

                case QX86_SCALE_X4:
                    /* Print X4 scale.  */
                    item->number        = 0;
                    item->string        = " * 4";
                    item                = item + 1;

                    /* Done.  */
                    break;

                case QX86_SCALE_X8:
                    /* Print X8 scale.  */
                    item->number        = 0;
                    item->string        = " * 8";
                    item                = item + 1;

                    /* Done.  */
                    break;

                default:
                    /* Operand had been tampered with.  */
                    return QX86_E_INTERNAL;
                }

                /* Need to print plus.  */
                printPlus               = 1;
            }

            /* Test if a displacement exists.  */
            if (QX86_DISP_NONE != operand->u.m.dispSize)
            {
                /* Print plus as needed.  */
                if (printPlus)
                {
                    /* Do print.  */
                    item->number        = 0;
                    item->string        = " + ";
                    item                = item + 1;
                }

                /* Print displacement.  */
                item->number            = operand->u.m.disp;
                item->numberSize        = operand->u.m.dispSize;
                item->string            = 0;
                item                    = item + 1;
            }

            /* Close brackets.  */
            item->number                = 0;
            item->string                = "]";
            item                        = item + 1;

            /* Done.  */
            break;

        case QX86_OPERAND_TYPE_REGISTER:
            /* Print register name.  */
            item->number                = 0;
            item->string                = qx86_rtab[operand->u.r.rindex].name;
            item                        = item + 1;

            /* Done.  */
            break;

        default:
            /* Operand had been tampered with.  */
            return QX86_E_INTERNAL;
        }
    }

    /* Terminate items.  */
    item->number                        = 0;
    item->string                        = 0;

    /* Jump to the generic print routine.  */
    return qx86_print(items, buffer, bufferSize);
}
