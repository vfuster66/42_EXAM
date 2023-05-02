/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
-----------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>

--------------------------------*/

#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	// Vérifier que l'argument est bien présent
    	if (ac < 2) 
    	{
		// Si l'argument est absent, écrire une ligne vide et terminer le programme
        	write(1, "\n", 1);
        	return 0;
    	}
    	// Trouver le début du premier mot
    	int	i;
	
	i = 0;
	// Chercher les espaces ou les tabulations au début de la chaîne
    	while (av[1][i] == ' ' || av[1][i] == '\t') 
        i++;
    	// Trouver la fin du premier mot
    	int	j;
	
	j = i;
	// Chercher la fin du premier mot (la première espace ou tabulation)
    	while (av[1][j] && av[1][j] != ' ' && av[1][j] != '\t') 
        	j++;
    	// Sauvegarder le premier mot dans un tampon temporaire
    	int	len;
	
	// Calculer la longueur du premier mot
	len = j - i;
	// Allouer de la mémoire pour stocker le premier mot (plus un caractère pour le terminateur de chaîne)
    	char *tmp = malloc(len + 1);
	// Vérifier que l'allocation a réussi
    	if (!tmp)
        	return 1;
    	int	k;
	
	k = -1;
	// Copier le premier mot dans le tampon temporaire
    	while (++k < len)
		tmp[k] = av[1][i + k];
	// Terminer la chaîne avec le caractère nul
    	tmp[k] = '\0';
    	// Imprimer le reste de la chaîne avec des mots séparés par des espaces
	// Ignorer les espaces ou les tabulations qui suivent le premier mot
    	while (av[1][j] && (av[1][j] == ' ' || av[1][j] == '\t'))
        	j++;
	// Parcourir le reste de la chaîne
    	while (av[1][j])
	{ 
		// Début d'un nouveau mot
        	i = j; 
		// Chercher la fin du mot
        	while (av[1][j] && av[1][j] != ' ' && av[1][j] != '\t') 
            		j++;
		// Si un mot a été trouvé, l'écrire
        	if (i < j)
		{ 
			// Écrire un espace avant le mot
            		write(1, " ", 1);
			// Écrire le mot
            		write(1, av[1] + i, j - i); 
        	}
		// Ignorer les espaces ou les tabulations qui suivent le mot
        	while (av[1][j] && (av[1][j] == ' ' || av[1][j] == '\t')) 
            		j++;
    	}
    	// Imprimer le premier mot à la fin, avec un espace
    	write(1, " ", 1);
    	write(1, tmp, len);
    	// Libérer le tampon temporaire
    	free(tmp);
    	// Écrire une ligne vide pour terminer la sortie
    	write(1, "\n", 1);
    	return 0;
}
``


	
