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
	while (*s1)
	{
		const char *p = s2;
		while (*p)
		{
			if (*p == *s1)
				return (char *)s1;
			p++;
		}
		s1++;
	}
	return NULL;
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