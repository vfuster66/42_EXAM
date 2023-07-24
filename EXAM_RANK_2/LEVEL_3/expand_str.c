/*Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str 
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>

-----------------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	// Variable booléenne pour savoir si le caractère précédent était un espace ou une tabulation
	int	flag; 

	// Vérifie si un seul argument est donné
	if (ac == 2) 
	{
		i = 0;
		// Ignore les espaces et les tabulations au début de la chaîne
		while (av[1][i] == ' ' || av[1][i] == '\t') 
			i++;
		// Parcourt tous les caractères de la chaîne
		while (av[1][i]) 
		{
			// Si le caractère est un espace ou une tabulation
			if (av[1][i] == ' ' || av[1][i] == '\t') 
				// Met la variable flag à vrai
				flag = 1;
			// Si le caractère n'est pas un espace ou une tabulation
			if (!(av[1][i] == ' ' || av[1][i] == '\t')) 
			{
				// Si le caractère précédent était un espace ou une tabulation
				if (flag)
					// Écrit trois espaces pour remplacer l'espace ou la tabulation
					write(1, "   ", 3);
				// Met la variable flag à faux
				flag = 0;
				// Écrit le caractère
				write(1, &av[1][i], 1); 
			}
			// Passe au caractère suivant
			i++;
		}
	}
	// Écrit un saut de ligne
	write(1, "\n", 1);
	return (0);
}
