/*Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$

-----------------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	i = 0;
	// Vérification que le programme a été appelé avec un argument
	if (ac == 2)
	{
		// Boucle pour atteindre la fin de la chaîne d'entrée
		while (av[1][i])
			i++;
		// Boucle pour afficher chaque caractère de la chaîne à l'envers
		while (i--)
			write(1, &av[1][i], 1);
	}
	// Ajout d'un saut de ligne à la fin de la sortie
	write(1, "\n", 1);
	return (0);
}
