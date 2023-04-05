/*Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);

--------------------------------------*/

#include <stdlib.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	count = 0;
	const char	*p;

	while (*s)
	{
		p = accept;
		while (*p)
		{
			if (*s == *p)
			{
				count++;
				break;
			}
			p++;
		}
		if (!*p)
			break;
		s++;
	}
	return count;
}

/*-------------------------------------

#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept);

int	main(void)
{
	const char	s[] = "Hello, world!";
	const char	accept[] = "elH";
	size_t		len;

	len = ft_strspn(s, accept);
	printf("s = \"%s\"\n", s);
	printf("accept = \"%s\"\n", accept);
	printf("Length of prefix matching accept: %zu\n", len);

	return (0);
}

-------------------------------------*/