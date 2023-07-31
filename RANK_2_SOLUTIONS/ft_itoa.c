/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:13:21 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 14:17:17 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

char    *ft_itoa(int nbr)
{
	int		i = 0;
	long	temp = nbr;
	char	*str;

	if (nbr == -2147483648)
		return ("-2147483648");
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i] ='\0';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
		str[0] = '-';
	}
	while (temp)
	{
		temp /= 10;
		i++;
	}
	while (nbr)
	{
		str[--i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}



int      main(void)
{
	int d = INT_MIN;
	printf("%d = %s\n", d, ft_itoa(d));
	d = -13;
	printf("%d = %s\n", d, ft_itoa(d));
	d = 0;
	printf("%d = %s\n", d, ft_itoa(d));
	d = 5;
	printf("%d = %s\n", d, ft_itoa(d));
	d = INT_MAX;
	printf("%d = %s\n", d, ft_itoa(d));
}
