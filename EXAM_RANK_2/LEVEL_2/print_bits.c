/*Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"

-------------------------------*/
#include <unistd.h>

// fonction pour afficher la représentation binaire d'un octet
void	print_bits(unsigned char octet)
{
	int	i;

	// on commence à partir de l'indice le plus élevé (7) car on veut afficher les bits de gauche à droite
	i = 7; 
	while (i >= 0)
	{
		// si le i-ème bit est à 1
		if ((octet >> i) & 1)
			// on affiche 1
			write(1, "1", 1); 
		else
			// sinon, on affiche 0
			write(1, "0", 1);
		// on passe au bit suivant
		i--; 
	}
}

/*--------------------------------
#include <unistd.h>

void	print_bits(unsigned char octet);

int	main(void)
{
	print_bits(27);
	return (0);
}

-------------------------------/*
