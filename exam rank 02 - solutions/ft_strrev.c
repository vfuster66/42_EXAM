/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:19:22 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 08:31:16 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strrev(char *str)
{
	char	*start;
	char	*end;
	char	temp;

	if (!str)
		return (NULL);
	start = str;
	end = str;

	while (*end)
		end++;
	end--;
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	return (str);	
}

#include <stdio.h>
#include <stdlib.h>

char	*ft_strrev(char *str);

int	main()
{
	char str[] = "Hello World";
	printf("Original string: %s\n", str);
	ft_strrev(str);
	printf("Reversed string: %s\n", str);
	return (0);
}
