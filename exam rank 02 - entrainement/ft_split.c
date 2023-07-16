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
