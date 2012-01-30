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

function preprocess(fileName, t_fileName, t_guard, t_line)
{
    ## Put the file into list of preprocessed files.
    g_preprocessedFiles[fileName] = 1

    ## Calculate guard #define name for this file.
    t_guard = toupper(fileName); gsub(/^.*\//, "", t_guard); gsub(/[.-]/, "_", t_guard)

    ## Scan the file line by line.
    while (1 == getline < fileName)
    {
        ## Match #include lines.
        if (/^[ \t\v]*#[ \t\v]*include[ \t\v]+<([a-z0-9.-]*)>[ \t\v]*$/)
        {
            ## Get included file name.
            t_fileName = $0
            
            ## Chop off extra stuff.
            gsub(/^.*</, "", t_fileName); gsub(/>.*$/, "", t_fileName)

            ## Test if we have included this file.
            if (t_fileName in g_stdFiles)
            {
                ## Print the line.
                print
            }
            else if (t_fileName in g_preprocessedFiles)
            {
                ## Already included.
            }
            else
            {
                ## Do include file.
                preprocess(g_prefix t_fileName)
            }
        }
        else if ("#ifndef " t_guard == $0)
        {
            ## Ignore this line.
        }
        else if ("#define " t_guard == $0)
        {
            ## Ignore this line.
        }
        else if ("#endif /* " t_guard " */" == $0)
        {
            ## Ignore this line.
        }
        else if (/^\/\* \+/)
        {
            ## Make an exception for the first box comment.
            if (!g_boxCommentSeen)
            {
                ## Store flag and continue.
                g_boxCommentSeen = 1; print; continue
            }

            ## Ignore this whole comment.
            while (1)
            {
                ## Fetch line.
                if (1 != getline < fileName) return

                ## Terminate on comment end.
                if (/\+ \*\/$/) break
            }
        }
        else
        {
            ## Normal code line.  Print it.
            print
        }
    }
}

BEGIN {
    ## Make sure one command-line argument is present.
    if (ARGC != 2)
    {
        ## Error.
        print "Usage: awk -f amalgamate.awk INPUT-FILE-NAME" > "/dev/stderr"
        exit 1
    }

    ## Extract prefix.
    g_prefix = ARGV[1]; gsub(/[^/]*$/, "", g_prefix)

    ## Make sure standard includes don't get cut out.
    g_stdFiles["inttypes.h"] = 1
    g_stdFiles["stdint.h"] = 1

    ## Begin the recursive fun.
    preprocess(ARGV[1])
    exit 0
}
