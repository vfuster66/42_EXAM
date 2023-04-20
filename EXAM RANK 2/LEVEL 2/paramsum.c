/*Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>

---------------------------------*/

#include <unistd.h>	// pour la fonction write()

/* Cette fonction affiche le nombre d'arguments passés en ligne de commande
   en utilisant la sortie standard. */
int main(int ac, const char **av)
{
	// variable pour stocker le nombre d'arguments
	int		n;
	// variable pour stocker le caractère à afficher
	char	c;

	// on soustrait 1 à ac car le premier argument est le nom du programme
	n = ac - 1;
	// si le nombre est négatif, on affiche un signe moins
	if (n < 0)	
	{
		write(1, "-", 1);
		// on prend la valeur absolue pour la suite
		n = -n;	
	}
	if (n >= 10)	// si le nombre a deux chiffres ou plus, on appelle récursivement main()
	{
		// on affiche le premier chiffre
		main(n / 10, av);
		// on affiche le deuxième chiffre
		main(n % 10, av);
	}
	// sinon, on affiche directement le chiffre
	else	
	{
		// on convertit l'entier en caractère ASCII
		c = n + '0';
		// on écrit le caractère dans la sortie standard
		write(1, &c, 1);
	}
	// on ajoute un retour à la ligne à la fin de l'affichage
	write(1, "\n", 1);
	return (0);
}
