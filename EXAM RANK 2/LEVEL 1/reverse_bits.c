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

// fonction pour inverser les bits d'un octet
unsigned char reverse_bits(unsigned char octet)
{
	// octet inversé
	unsigned char	reversed;
	// compteur
	int				i; 

	reversed = 0;
	i = 0;
	// pour chaque bit de l'octet
	while (i < 8) 
	{
		// on décale l'octet inversé d'un bit vers la gauche et on y ajoute le bit courant
		reversed = (reversed << 1) | (octet & 1);
		// on décale l'octet original d'un bit vers la droite pour passer au bit suivant
		octet >>= 1;
		// on incrémente le compteur pour passer au bit suivant
		i++; 
	}
	// on retourne l'octet inversé
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
