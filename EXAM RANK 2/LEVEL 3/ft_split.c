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

// Fonction pour diviser une chaîne de caractères en mots
char **ft_split(char *str)
{
	// Index pour parcourir la chaîne de caractères
	int index = 0;
	// Indice de ligne pour le tableau de mots
	int row_tab = 0;
	// Tableau pour stocker les mots
	char **tab;

	// Allouer de la mémoire pour le tableau de pointeurs de mots
	tab = (char **)malloc(sizeof(char *) * 256);
	if (!tab)
		// Retourner NULL si l'allocation de mémoire a échoué
		return (NULL);
	// Parcourir la chaîne de caractères jusqu'à la fin
	while (str[index])
	{
		// Ignorer les espaces, les tabulations et les sauts de ligne
		while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
			index++;
		// Vérifier si la fin de la chaîne n'a pas été atteinte
		if (str[index])
		{
			// Longueur du mot courant
			int word_length = 0;
			// Calculer la longueur du mot courant
			while (str[index + word_length] && str[index + word_length] != ' ' 
					&& str[index + word_length] != '\t' && str[index + word_length] != '\n')
				word_length++;
			// Allouer de la mémoire pour le mot courant
			tab[row_tab] = (char *)malloc(sizeof(char) * (word_length + 1));
			// Vérifier si l'allocation de mémoire a échoué
			if (!tab[row_tab])
			{
				// Libérer la mémoire allouée aux mots précédents
				while (row_tab >= 0)
					free(tab[row_tab--]);
				// Libérer la mémoire allouée au tableau de pointeurs de mots
				free(tab);
				// Retourner NULL si l'allocation de mémoire a échoué
				return (NULL);
			}
			int i = 0;
			// Copier le mot courant dans le tableau
			while (i < word_length)
			{
				// Copier chaque caractère du mot
				tab[row_tab][i] = str[index++];
				i++;
			}
			// Ajouter le caractère de fin de chaîne à la fin du mot
			tab[row_tab][word_length] = '\0';
			// Passer à la ligne suivante du tableau
			row_tab++;
		}
	}
	// Ajouter un pointeur NULL à la fin du tableau pour indiquer la fin des mots
	tab[row_tab] = NULL;
	// Retourner le tableau de mots
	return (tab);
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
