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
	int	i = 0;
	int	row = 0;
	int	column;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 256);
	if (!tab)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		column = 0;
		tab[row] = (char *)malloc(sizeof(char) * 4096);
		if (!tab[row])
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
			tab[row][column++] = str[i++];
		tab[row][column] = '\0';
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		row++;
	}
	tab[row] = NULL;
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
