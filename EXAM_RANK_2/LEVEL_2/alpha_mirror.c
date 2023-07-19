/*Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
-----------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>

--------------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	
	i = 0;
	// Vérification que le programme est appelé avec exactement un argument
	if (ac == 2) 
	{
		// Boucle sur tous les caractères de l'argument
		while (av[1][i])
		{
			// Si le caractère est une minuscule
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				// Conversion du caractère en "complément à 219"
				av[1][i] = 219 - av[1][i];
			// Si le caractère est une majuscule
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				// Conversion du caractère en "complément à 155"
				av[1][i] = 155 - av[1][i];
			// Écriture du caractère dans la sortie standard
			write(1, &av[1][i], 1);
			// Incrémentation de i pour passer au caractère suivant
			i++;
		}
	}
	// Écriture d'un retour à la ligne à la fin de la sortie standard
	write(1, "\n", 1);
	// Retourne 0 pour indiquer que le programme s'est exécuté correctement
	return (0);
}
