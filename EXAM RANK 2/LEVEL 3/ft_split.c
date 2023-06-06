/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);

-------------------------------*/

#include <stdlib.h>

char **ft_split(char *str)
{
    // Compteur pour itérer à travers la chaîne d'entrée
	int		i = 0;
    // Compteur pour suivre la ligne actuelle du tableau split
	int		row = 0;
    // Compteur pour suivre la colonne actuelle de chaque ligne
	int		column = 0;
    // Tableau pour stocker les sous-chaînes splittées
	char	**split;     

	// Allouer de la mémoire pour le tableau split
	split = (char **)malloc(sizeof(char *) * 256);
	if (!split)
		return (NULL);
	while (str[i])
	{
		// Ignorer les espaces, les tabulations et les retours à la ligne
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
		{
			// Allouer de la mémoire pour la ligne actuelle
			split[row] = (char *)malloc(sizeof(char) * 4096);
			if (split[row] == NULL)
			{
				// En cas d'échec d'allocation de mémoire, libérer la mémoire précédemment allouée
				while (row >= 0)
					free(split[row--]);
				free(split);
				return (NULL);
			}
			// Copier les caractères dans la ligne actuelle jusqu'à rencontrer un espace, une tabulation ou un retour à la ligne
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				split[row][column++] = str[i++];
			// Terminer la ligne actuelle par un caractère nul
			split[row][column] = '\0';
			// Passer à la ligne suivante
			row++;
			column = 0;
		}
	}
	// Définir le dernier élément du tableau split sur NULL pour marquer la fin
	split[row] = NULL;
	return (split);
}

/*-----------------------------------
#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str);

int main(void)
{
    char str[] = "Hello, World! How are you today?";
    char **words = ft_split(str);

    if (words == NULL)
    {
        printf("Erreur: la fonction ft_split a renvoyé NULL.\n");
        return 1;
    }

    for (int i = 0; words[i] != NULL; i++)
    {
        printf("%s\n", words[i]);
        free(words[i]);
    }

    free(words);

    return 0;
}

----------------------------------------*/
