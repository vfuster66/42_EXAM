/*Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100  0001
     ||
     \/
 1000  0010

-----------------------------------------------*/

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	reversed;
	int				i;

	reversed = 0;
	i = 0;
	while (i < 8)
	{
		reversed <<= 1;
		reversed |= (octet >> 1) & 1;
		i++;
	}
	return (reversed);
}

/*--------------------------------

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet);

int	main(void)
{
	unsigned char	octet = 0x41;
	unsigned char	reversed;

	reversed = reverse_bits(octet);
	printf("Octet original : 0x%x\n", octet);
	printf("Octet inverse : 0x%x\n", reversed);
	return (0);
}
----------------------------------*/