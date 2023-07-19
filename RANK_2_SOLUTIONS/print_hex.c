/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:58:55 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 10:04:24 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	putnbr_hex(int n)
{
	char	tab[] = "0123456789abcdef";

	if (n >= 16)
		putnbr_hex(n / 16);
	write(1, &tab[n % 16], 1);
}

int	main(int ac, char **av)
{
	int	n;

	if (ac == 2)
	{
		n = ft_atoi(av[1]);
		if (n >= 0)
			putnbr_hex(n);
	}
	write(1, "\n", 1);
	return (0);
}