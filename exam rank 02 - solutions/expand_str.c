/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:49:15 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 18:50:13 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int	i = 0;
	int	space = -1;
	
	if (ac == 2)
	{
		while(av[1][i])
		{	
			if (av[1][i] != ' ' && av[1][i] != '\t')
			{
				if (space == 1)
					write(1, "   ", 3);
				space = 0;
				write(1, &av[1][i], 1);
			}
			else if (space == 0)
				space = 1;
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}