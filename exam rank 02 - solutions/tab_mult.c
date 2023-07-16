/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:08:08 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 11:19:06 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int	result = 0;

	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int	main(int ac, char **av)
{
	int	nb1;
	int	nb2;
	
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		nb1 = 1;
		nb2 = ft_atoi(av[1]);
		while (nb1 <= 9)
		{
			ft_putnbr(nb1);
			write(1, " x ", 3);
			ft_putnbr(nb2);
			write(1, " = ", 3);
			ft_putnbr(nb1 * nb2);
			write(1, "\n", 1);
			nb1++;
		}
	}
	return (0);
}