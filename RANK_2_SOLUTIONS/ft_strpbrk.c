/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:08:39 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 08:22:29 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);

--------------------------------------*/

#include <stdlib.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	// Variable debut_s2 pour conserver le pointeur de debut de chaine s2
	const char *debut_s2 = s2;

	// Boucle pour parcourir s1 jusqu'a la fin
	while (*s1)
	{
		// Reinitialiser le pointeur s2 vers le debut de la chaine
		s2 = debut_s2;
		// Boucle pour parcourir s2
		while (*s2)
		{
			// Si une correspondance est trouvee
			if (*s1 == *s2)
				// Renvoyer le caractere actuel de s1
				return ((char *)s1);
			// Passer au caractere suivant de s2
			s2++;
		}
		// Passer au caractere suivant de s1
		s1++;
	}
	// Renvoyer NULL si aucun caractere en commun n'est trouve
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
