/*Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>

------------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	
	i = 0;
	if (ac == 2)
	{
		// Boucle pour parcourir la chaine de caractères
		while (av[1][i])
		{
			char c = av[1][i];
			// On vérifie si le caractère est compris entre 'a' et 'm' ou 'A' et 'M'
			if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
				// On ajoute 13 pour le décaler de 13 positions dans l'alphabet
				c += 13;
			// On vérifie si le caractère est compris entre 'n' et 'z' ou 'N' et 'Z'
			else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
				// On soustrait 13 pour le décaler de 13 positions dans l'alphabet
				c -= 13;
			// On affiche le caractère modifié
			write(1, &c, 1);
			i++;
		}
	}
	// On affiche un retour à la ligne pour finir
	write(1, "\n", 1);
	return (0);
}
