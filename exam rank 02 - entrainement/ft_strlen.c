/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:41:29 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 18:09:04 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
