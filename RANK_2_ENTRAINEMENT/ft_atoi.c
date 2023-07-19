/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:43:12 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/19 13:05:07 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{

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
