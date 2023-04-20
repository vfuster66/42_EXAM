/*Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union 
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>

-------------------------------*/

#include <unistd.h>

int main(int ac, char **av)
{	
	int	i;
	int	ascii[256];
	
	// Initialisation de toutes les valeurs du tableau ascii à 0
	i = 0;
	while (i < 256)
	{
		ascii[i] = 0;
		i++;
	}
	
	// Vérification du nombre d'arguments
	if (ac != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	
	// Parcours de la première chaîne de caractères
	i = 0;
	while(av[1][i])
	{
		// Si le caractère n'a pas encore été rencontré, on le marque comme rencontré
		//(on change sa valeur dans le tableau ascii à 1) et on l'affiche
		if (!ascii [(unsigned char)av[1][i]])
		{
			ascii[(unsigned char)av[1][i]] = 1;
			write(1, &av[1][i], 1);
		}
		i++;
	}
	
	// Parcours de la deuxième chaîne de caractères
	i = 0;
	while (av[2][i])
	{
		// Si le caractère n'a pas encore été rencontré, on le marque comme rencontré 
		//(on change sa valeur dans le tableau ascii à 1) et on l'affiche
		if (!ascii[(unsigned char)av[2][i]])
		{
			ascii[(unsigned char)av[2][i]] = 1;
			write(1, &av[2][i], 1);
		}
		i++;
	}
	
	write(1, "\n", 1);
	return 0;
}
