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
	const char	*p;
	// On parcourt la chaîne s1 jusqu'à la fin
	while (*s1)
	{
		// On parcourt la chaîne s2 jusqu'à la fin
		*p = s2;
		while (*p)
		{
			// On compare chaque caractère de s2 avec celui de s1
			if (*p == *s1)
				// On retourne le pointeur sur le caractère trouvé
				return ((char *)s1); 
			p++;
		}
		s1++;
	}
	// Si aucun caractère trouvé, on retourne NULL
	return (NULL); 
}

/*----------------------------------

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
---------------------------------*/
