/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:55:55 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 18:03:50 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	start;
	int	end;
	int	space;

	if (ac > 1 && av[1][0])
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		start = i;
		while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i] != '\0')
			i++;
		end = i;
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			while ((av[1][i] == ' ' && av[1][i + 1] == ' ') 
					|| (av[1][i] == '\t' && av[1][i + 1] == '\t'))
				i++;
			if (av[1][i] == ' ' || av[1][i] == '\t')
				space = 1;
			write(1, &av[1][i], 1);
			i++;
		}
		if (space)
			write(1, " ", 1);
		while (start < end)
		{
			write(1, &av[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}