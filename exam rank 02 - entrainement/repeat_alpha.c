/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:25:06 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 18:12:58 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	if (ac == 2)
	{
		i = 0;
		k = 1;
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				k = av[1][i] - 64;
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
				k = av[1][i] - 96;
			j = 0;
			while (j < k)
			{
				write(1, &av[1][i], 1);
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
