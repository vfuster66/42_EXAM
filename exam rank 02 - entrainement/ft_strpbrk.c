/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:08:39 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 18:42:11 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	const char	*s2_start = s2;

	while (*s1)
	{
		s2 = s2_start;
		while (*s2)
		{
			if (*s1 == *s2)
				return ((char *)s1);
			s2++;
		}
		s1++;
	}
	return (NULL);
}

#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2);

int	main(void)
{
	const char	s1[] = "Hello, world!";
	const char	s2[] = "oe";
	char		*p;

	printf("s1 = %s\ns2 = %s\n", s1, s2);
	p = ft_strpbrk(s1, s2);
	if (p)
		printf("First matching character: %c\n", *p);
	else
		printf("No matching character found.\n");

	return (0);
}
