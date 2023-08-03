/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:43:12 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/11 14:49:17 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
---------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);

------------------------------*/

int	ft_atoi(char *str)
{
	int	i = 0;
	int	result = 0;
	int	sign = 1;
	
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		str++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);	
}

#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *str);

int	main()
{	char str1[] = "123";
	char str2[] = "-456";
	char str3[] = "0";
	char str4[] = "999999999";
	char str5[] = "-2147483648";
	char str6[] = "2147483647";

	printf("'%s' converti en int : %d\n", str1, ft_atoi(str1));
	printf("'%s' converti en int : %d\n", str2, ft_atoi(str2));
	printf("'%s' converti en int : %d\n", str3, ft_atoi(str3));
	printf("'%s' converti en int : %d\n", str4, ft_atoi(str4));
	printf("'%s' converti en int : %d\n", str5, ft_atoi(str5));
	printf("'%s' converti en int : %d\n", str6, ft_atoi(str6));
	return 0;
}
