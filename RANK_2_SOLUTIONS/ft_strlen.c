/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:41:29 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/11 09:13:48 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
-------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);

---------------------------------*/

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

int	main(void)
{
	char	str[] = "Hello, World!";
	int		len;

	len = ft_strlen(str);
	printf("Length of \"%s\" = %d\n", str, len);
	return (0);
}
