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

#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str)
{
	int		i = 0;
	int		row = 0;
	int		column;
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
        if (!tab)
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			tab[row][column++] = str[i++];
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		tab[row][column] = '\0';
		row++;
	}
	tab[row] = NULL;
	return (tab);
}

int	main(void)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split("The prophecy is true");
	while (i < 4)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
