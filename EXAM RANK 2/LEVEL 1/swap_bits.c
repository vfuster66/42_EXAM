/*Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
---------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
 
 ----------------------------------*/
 
 #include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

/*-----------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned char	swap_bits(unsigned char octet);

int main(void)
{
	unsigned char octet = 0x41;
	unsigned char swapped_octet = swap_bits(octet);

	printf("Octet original : 0x%02x\n", octet);
	printf("Octet échangé  : 0x%02x\n", swapped_octet);

	return (0);
}

----------------------------------*/