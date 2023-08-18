/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:54:25 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 17:16:01 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
#include <stdio.h>
char    **ft_split(char *str)
{
	// Index pour parcourir la chaine de caracteres
	int	i = 0;
	// Variable pour stocker chaque mot dans le tableau
	int	mot = 0;
	// Variable pour stocker chaque caractere du mot dans le tableau
	int	caractere_mot;
	// Tableau de pointeurs vers des chaines de caracteres
	char	**tab;

	// Allouer dynamiquement de la memoire  pour le tableau
	tab = (char **)malloc(sizeof(char *) * 256);
	if (!tab)
		return (NULL);
	// Boucle pour ignorer les espaces, tab ou saut de ligne
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	// Boucle pour parcourir la chaine de caracteres jusqu'a la fin
	while (str[i])
	{
		caractere_mot = 0;
		// Allouer dynamiquement de la memoire pour stocker un nouveau mot
		tab[mot] = (char *)malloc(sizeof(char) * 4096);
		if (!tab[mot])
			return (NULL);
		// Boucle pour parcourir les caracteres du mot
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
			// Copie de chaque caractere dans le tableau
			tab[mot][caractere_mot++] = str[i++];
		// Ajouter le caractere nul a la fin de la chaine de caracteres
		tab[mot][caractere_mot] = '\0';
		// Ignorer les espaces, tab, retour a la ligne de fin de chaine
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		// Passer au mot suivant
		mot++;
	}
	// Assigner NULL a la derniere case du tableau = plus de mot a stocker
	tab[mot] = NULL;
	return (tab);
}

/*---------------------------------------------
#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str);

int main(int ac, char **av)
{
	int	i = 0;
	char	**tab;

	if (ac == 2)
	{
		tab = ft_split(av[1]);
		while (tab[i] != NULL)
		{
			printf("%s\n", tab[i]);
			free(tab[i]);
			i++;
		}
    }
    free(tab);
    return 0;
}
-----------------------------------------------*/
