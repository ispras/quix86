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

static int
qx86_print(qx86_print_item *items, char *buffer, int *bufferSize)
{
    qx86_print_item *                   item;
    int                                 size;

    QX86_CONST char *                   p;
    QX86_CONST qx86_uint8 *             x;

    /* XXX */
    static const char                   hexDigits[16]
                                        =
    {
        '0', '1', '2', '3',             '4', '5', '6', '7',
        '8', '9', 'A', 'B',             'C', 'D', 'E', 'F'
    };

    /* XXX */
    (void) qx86_flip_case;

    /* Scan items.  */
    for (size = 0, item = items; /* ILB */; ++item)
    {
        /* See if this item contains a number or a string.  */
        if (item->number)
        {
            /* Format number.  */
            for (x = item->number + item->numberSize - 1; x >= item->number; --x)
            {
                /* See if there is space left for 2 characters.  */
                if (size + 1 < *bufferSize)
                {
                    /* Print nibbles.  */
                    buffer[size + 0] = hexDigits[*x / 16];
                    buffer[size + 1] = hexDigits[*x % 16];
                }
                
                /* Increase size.  */
                size += 2;
            }
        }
        else if (item->string)
        {
            /* While we still have room for characters, copy them.  */
            for (p = item->string; *p; ++p)
            {
                /* See if there is space left.  */
                if (size < *bufferSize)
                {
                    /* Yes.  Copy character.  */
                    buffer[size] = *p;
                }

                /* In all cases, increment the size.  */
                ++size;
            }
        }
        else
        {
            /* No data in this item.  This is the terminator.  */
            break;
        }
    }

    /* Attempt to terminate with a NUL.  */
    if (size++ < *bufferSize) buffer[size - 1] = '\0';

    /* Now size contains the actual buffer size.  */
    if (size <= *bufferSize)
    {
        /* Had enough space to print all characters.  */
        *bufferSize = size; return QX86_SUCCESS;
    }
    else
    {
        /* Could not print all characaters.  */
        *bufferSize = size; return QX86_E_INSUFFICIENT_BUFFER;
    }
}
