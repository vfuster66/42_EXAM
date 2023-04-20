/*Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);

--------------------------------------*/
#include <string.h>

char	*ft_strpbrk(const char *str1, const char *str2) 
{
	// pointeur sur le début de str1
	const char	*s1 = str1;
	// pointeur sur le début de str2
	const char	*s2;
	// boucle sur chaque caractère de str1
	while (*s1)
	{
		// réinitialisation du pointeur sur le début de str2
        	s2 = str2;
		// boucle sur chaque caractère de str2
		while (*s2)
		{
			if (*s1 == *s2)
			{
				// retourne le pointeur sur le caractère correspondant
				return (char *)s1;
			}
			// passe au caractère suivant dans str2
			s2++;
		}
		// passe au caractère suivant dans str1
		s1++;
	}
	// aucun caractère correspondant n'a été trouvé
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
