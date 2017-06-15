#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <quix86.h>

int
callback(void *data, int rindex, int subreg, unsigned char *value)
{
    (void) data;
    (void) subreg;

    if (rindex == QX86_REGISTER_EBP) *(unsigned *)value = 0x10002000;
    if( rindex == QX86_REGISTER_SS) *(unsigned long long*)value = 0;
    if( rindex == QX86_REGISTER_RIP) *(unsigned long long*)value = 0xA00000000;
    
    return 1;
}

int
main(void)
{
    unsigned char                       raw[]
//                                      = "\x44\x0F\x22\x00";
//                                      = "\xDF\xC0";
//                                      = "\x66\x0f\xba\x64\x24\x6c\x00";
//                                      = "\x41\x89\x3c\x24\x00\x00\x00";
//                                      = "\x0F\x01\x15\x11\x11\x11\x11";
//                                      = "\x0f\xb9";
//                                      = "\xf3\x0f\xae\xc3";
//                                      = "\x0F\x01\xC4";
//                                      = "\x8b\x4d\xf4";
//                                      = "\xB4\x42";
//                                      = "\x42\xB4\x42";
//                                      = "\xF0\x30\x3C\x12\x34";
//                                      = "\x67\x65\x0F\x38\x1C\x40\x42";
//                                      = "\xf7\x45\x70\x00\x00\x02\x00";
//                                      = "\xF2\xAE";
//                                      = "\xF3\x0F\xBD\x00";
//                                      = "\x49\x8B\x94\xC5\xF0\x02\x00\x00";
//                                      = "\x83\xCA\xFF";
//                                      = "\x6A\xFF";
//                                      = "\x8D\x74\x26\x00";
//                                      = "\x41\x57";
//                                      = "\x41\xB0\x20";
//                                      = "\x48\xC7\xC7\xF9\x79\x33\x80";
//                                      = "\x48\x05\x12\x34\x56\x87";
//                                      = "\xF3\x0F\x10\x8B\xBC\xC0\x00\x00\x00";
                                        = "\x8D\xCC";

    qx86_insn                           insn;
    qx86_print_options_intel            opt;

    char                                buffer[1024];
    int                                 bufferSize = sizeof(buffer);

    int                                 i;

    memset(&insn, 0, sizeof(insn)); insn.callback = &callback;

    opt.flipCase                        = 0;

    printf("qx86_instruction_decode         : returned %d.\n", qx86_decode(&insn, QX86_SIZE_32, raw, sizeof(raw)));
    printf("qx86_print_intel                : returned %d.\n", qx86_print_intel(&insn, &opt, buffer, &bufferSize));
    printf("                                > %s\n", buffer);

    for (i = 0; i < insn.operandCount; ++i)
    {
        printf("operand %d size                  > %d\n", i + 1, insn.operands[i].size);
    }

    return 0;
}
