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

## Define a mnemonic.
function defineMnemonic(list, n, i, t_attribute, t_attributeString, t_attributeNo, t_demoted, t_iclassString, t_mnemonic, t_oldFS, t_promoted)
{
    ## Cut off mnemonic.
    gsub(/^[^ \t\v]+[ \t\v]+/, "")

    ## Initialize demoted and promoted.
    t_demoted = "NONE"; t_promoted = "NONE"

    ## Iterate attributes.
    for (t_attributeNo = 1; t_attributeNo <= NF; ++t_attributeNo)
    {
        ## Get attribute.
        t_attribute = $t_attributeNo

        ## Clean up.
        gsub(/,[ \t\v]*$/, "", t_attribute)

        ## Dot is not an attribute.
        if ("." == t_attribute)
        {
            ## Must be the only one.
            if (1 != NF)
            {
                ## Syntax error.
                printf "%s:%d: '.' combined with other attributes.", g_fileName, g_lineNo > "/dev/null"
                exit 1
            }

            ## Pass.
            break
        }

        ## Parse out demotion.
        if (t_attribute ~ /^>/)
        {
            ## Remove prefix.
            gsub(/^>/, "", t_attribute)

            ## Store.
            t_demoted = t_attribute
            continue
        }

        ## Parse out promotion.
        if (t_attribute ~ /^</)
        {
            ## Remove prefix.
            gsub(/^</, "", t_attribute)

            ## Store.
            t_promoted = t_attribute
            continue
        }

        ## Parse out iclass.
        if (t_attribute ~ /^\$/)
        {
            ## Remove prefix.
            gsub(/^\$/, "", t_attribute)

            ## Convert to enumeration member.
            t_attribute = "QX86_ICLASS_" t_attribute

            ## Add to string.
            if (t_iclassString)
            {
                ## Need an OR operation.
                t_iclassString = t_iclassString " | " t_attribute
            }
            else
            {
                ## First one.
                t_iclassString = t_attribute
            }
        }
        else
        {
            ## Convert to a member of the enumeration.
            t_attribute = "QX86_MATTRIBUTE_" t_attribute

            ## Add to string.
            if (t_attributeString)
            {
                ## Need an OR operation.
                t_attributeString = t_attributeString " | " t_attribute
            }
            else
            {
                ## First one.
                t_attributeString = t_attribute
            }
        }
    }

    ## Watch out for null attribute strings.
    if (!t_attributeString) t_attributeString = "QX86_MATTRIBUTE_NONE"

    ## Watch out for null iclass strings.
    if (!t_iclassString) t_iclassString = "QX86_ICLASS_NONE"

    ## Iterate list.
    for (i = 0; i < n; ++i)
    {
        ## Get t_mnemonic.
        t_mnemonic = list[i]

        ## If t_mnemonic contains an asterisk, this is the new defaults.
        if ("*" == t_mnemonic)
        {
            ## TODO: update defaults.
            return
        }

        ## Store mnemonic data.
        g_mtab_name[g_mtabSize]             = t_mnemonic
        g_mtab_attributes[g_mtabSize]       = t_attributeString
        g_mtab_iclass[g_mtabSize]           = t_iclassString
        g_mtab_demoted[g_mtabSize]          = t_demoted
        g_mtab_promoted[g_mtabSize]         = t_promoted

        ## Advance.
        g_mtabSize                          = g_mtabSize + 1
    }
}

## Process one input file.
function process(t_list, t_prefix)
{
    ## Scan file.
    for (g_lineNo = 1; 1 == getline < g_fileName; ++g_lineNo)
    {
        ## Remove comments.
        gsub(/#.*$/, "")

        ## Remove leading and trailing whitespace.
        gsub(/^[ \t\v]+/, "")
        gsub(/[ \t\v]+$/, "")

        ## Ignore empty lines.
        if ("" == $0) continue

        ## Must have at least two fields.
        if (NF < 2)
        {
            ## Syntax error.
            printf "%s:%d: insufficient number of line fields.", g_fileName, g_lineNo > "/dev/stderr"
            exit 1
        }

        ## If the second field is a plus, this is essentially a comment.
        if ($2 == "+") continue

        ## Expand mnemonic into list if needed.
        if ($1 ~ /cc$/)
        {
            ## Get prefix.
            t_prefix = $1; gsub(/cc$/, "", t_prefix)

            ## Make list.
            t_list[ 0] = t_prefix "A"
            t_list[ 1] = t_prefix "AE"
            t_list[ 2] = t_prefix "B"
            t_list[ 3] = t_prefix "BE"
            t_list[ 4] = t_prefix "G"
            t_list[ 5] = t_prefix "GE"
            t_list[ 6] = t_prefix "L"
            t_list[ 7] = t_prefix "LE"
            t_list[ 8] = t_prefix "O"
            t_list[ 9] = t_prefix "NO"
            t_list[10] = t_prefix "P"
            t_list[11] = t_prefix "NP"
            t_list[12] = t_prefix "S"
            t_list[13] = t_prefix "NS"
            t_list[14] = t_prefix "Z"
            t_list[15] = t_prefix "NZ"

            ## Process.
            defineMnemonic(t_list, 16)
        }
        else
        {
            ## Process one mnemonic.
            t_list[0] = $1; defineMnemonic(t_list, 1)
        }
    }
}

## Sort mtab.
function sort(i, j, x)
{
    ## Bubble sort.
    for (i = 0; i < g_mtabSize; ++i)
    {
        ## Inner loop.
        for (j = i + 1; j < g_mtabSize; ++j)
        {
            ## Compare.
            if (g_mtab_name[i] > g_mtab_name[j])
            {
                ## Swap names.
                x                       = g_mtab_name[i]
                g_mtab_name[i]          = g_mtab_name[j]
                g_mtab_name[j]          = x

                ## Swap attributes.
                x                       = g_mtab_attributes[i]
                g_mtab_attributes[i]    = g_mtab_attributes[j]
                g_mtab_attributes[j]    = x

                ## Swap iclass.
                x                       = g_mtab_iclass[i]
                g_mtab_iclass[i]        = g_mtab_iclass[j]
                g_mtab_iclass[j]        = x

                ## Swap demoted.
                x                       = g_mtab_demoted[i]
                g_mtab_demoted[i]       = g_mtab_demoted[j]
                g_mtab_demoted[j]       = x

                ## Swap promoted.
                x                       = g_mtab_promoted[i]
                g_mtab_promoted[i]      = g_mtab_promoted[j]
                g_mtab_promoted[j]      = x
            }
        }
    }
}

## Generate qx86-e-mnemonic.h.
function printHeader(fileName, i, x)
{
    ## Print boilerplate.
    print "/* +------------------------------------------------------------------------+"       > fileName
    print "   | quix86                                                                 |"       > fileName
    print "   +------------------------------------------------------------------------+"       > fileName
    print "   | This file is part of quix86, an x86-64 instruction decoder.            |"       > fileName
    print "   |                                                                        |"       > fileName
    print "   | Copyright (C) 2011 Institute for System Programming of Russian Academy |"       > fileName
    print "   | of Sciences.                                                           |"       > fileName
    print "   |                                                                        |"       > fileName
    print "   | Contact e-mail: <unicluster@ispras.ru>.                                |"       > fileName
    print "   |                                                                        |"       > fileName
    print "   | quix86 is free software: you can redistribute it and/or modify it      |"       > fileName
    print "   | under the terms of the GNU Lesser General Public License as published  |"       > fileName
    print "   | by the Free Software Foundation, either version 3 of the License, or   |"       > fileName
    print "   | (at your option) any later version.                                    |"       > fileName
    print "   |                                                                        |"       > fileName
    print "   | quix86 is distributed in the hope that it will be useful, but WITHOUT  |"       > fileName
    print "   | ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  |"       > fileName
    print "   | FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public   |"       > fileName
    print "   | License for more details.                                              |"       > fileName
    print "   |                                                                        |"       > fileName
    print "   | You should have received a copy of the GNU Lesser General Public       |"       > fileName
    print "   | License along with quix86. If not, see <http://www.gnu.org/licenses/>. |"       > fileName
    print "   +------------------------------------------------------------------------+ */"    > fileName
    print ""                                                                                    > fileName

    ## Print enumeration header.
    print "/**"                                                                                 > fileName
    print " * Enumeration of <em>x86</em> instruction mnemonics."                               > fileName
    print " *"                                                                                  > fileName
    print " * \\author                              icee"                                       > fileName
    print " * \\since                               1.0"                                        > fileName
    print " */"                                                                                 > fileName
    print "enum qx86_mnemonic"                                                                  > fileName
    print "{"                                                                                   > fileName
    print "    QX86_MNEMONIC_NONE                  = 0,"                                        > fileName
    print ""                                                                                    > fileName
    print "    /* Enumerators are sorted based on their names.  */"                             > fileName

    ## Iterate mtab.
    for (i = 0; i < g_mtabSize; ++i)
    {
        ## Print.
        printf "    QX86_MNEMONIC_%-21s = %d,\n", g_mtab_name[i], i + 1                         > fileName
    }

    ## Print enumeration footer.
    print ""                                                                                    > fileName
    print "    QX86_MNEMONIC_COUNT                 = " g_mtabSize + 1                           > fileName
    print "};"                                                                                  > fileName

    ## Close file.
    close(fileName)
}

## Generate qx86-d-mtab.c
function printSource(fileName, i, x)
{
    ## Print boilerplate.
    print "/* +------------------------------------------------------------------------+"       > fileName
    print "   | quix86                                                                 |"       > fileName
    print "   +------------------------------------------------------------------------+"       > fileName
    print "   | This file is part of quix86, an x86-64 instruction decoder.            |"       > fileName
    print "   |                                                                        |"       > fileName
    print "   | Copyright (C) 2011 Institute for System Programming of Russian Academy |"       > fileName
    print "   | of Sciences.                                                           |"       > fileName
    print "   |                                                                        |"       > fileName
    print "   | Contact e-mail: <unicluster@ispras.ru>.                                |"       > fileName
    print "   |                                                                        |"       > fileName
    print "   | quix86 is free software: you can redistribute it and/or modify it      |"       > fileName
    print "   | under the terms of the GNU General Public License as published by the  |"       > fileName
    print "   | Free Software Foundation, either version 3 of the License, or (at your |"       > fileName
    print "   | option) any later version.                                             |"       > fileName
    print "   |                                                                        |"       > fileName
    print "   | quix86 is distributed in the hope that it will be useful, but WITHOUT  |"       > fileName
    print "   | ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  |"       > fileName
    print "   | FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License  |"       > fileName
    print "   | for more details.                                                      |"       > fileName
    print "   |                                                                        |"       > fileName
    print "   | You should have received a copy of the GNU General Public License      |"       > fileName
    print "   | along with quix86.  If not, see <http://www.gnu.org/licenses/>.        |"       > fileName
    print "   +------------------------------------------------------------------------+ */"    > fileName
    print ""                                                                                    > fileName

    ## Print definition header.
    print "/* Reference: AMD and Intel manuals.  */"                                            > fileName
    print "QX86_CONST qx86_mtab_item               qx86_mtab[QX86_MNEMONIC_COUNT]"              > fileName
    print "                                        ="                                           > fileName
    print "{"                                                                                   > fileName
    print "    {"                                                                               > fileName
    print "        0,                              0,"                                          > fileName
    print "        QX86_MATTRIBUTE_NONE,           QX86_ICLASS_NONE,"                           > fileName
    print "        QX86_MNEMONIC_NONE,             QX86_MNEMONIC_NONE"                          > fileName
    print "    },"                                                                              > fileName

    ## Iterate mtab.
    for (i = 0; i < g_mtabSize; ++i)
    {
        ## Get name in quotes.
        x = "\"" g_mtab_name[i] "\","

        ## Print item.
        printf "    {\n"                                                                        > fileName
        printf "        %-31s %s\n", x, x                                                       > fileName
        printf "        %-31s %s\n", g_mtab_attributes[i] ",", g_mtab_iclass[i] ","             > fileName
        printf "        %-31s %s\n", "QX86_MNEMONIC_" g_mtab_demoted[i] ",", "QX86_MNEMONIC_" g_mtab_promoted[i] \
                                                                                                > fileName

        ## Print either with or without comma.
        if (i < g_mtabSize - 1)
        {
            ## With comma.
            print "    },"                                                                      > fileName
        }
        else
        {
            print "    }"                                                                       > fileName
        }
    }

    ## Print definition footer.
    print "};"                                                                                  > fileName

    ## Close file.
    close(fileName)
}

BEGIN {
    ## Make sure at least one command-line argument is present.
    if (ARGC < 2)
    {
        ## Error.
        print "Usage: awk -f make-mtab.awk INPUT-FILE-NAMES..." > "/dev/stderr"
        exit 1
    }

    ## Begin with a null mtab.
    g_mtabSize = 0

    ## Process each file.
    for (g_fileNo = 1; g_fileNo < ARGC; ++g_fileNo)
    {
        ## Read file.
        g_fileName = ARGV[g_fileNo]; process()
    }

    ## Sort items.
    sort()

    ## Print header and source files.
    printHeader("qx86-e-mnemonic.h")
    printSource("qx86-d-mtab.c")
}
