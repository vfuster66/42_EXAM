/*Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);

--------------------------*/

#include <stdlib.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (ft_strchr(reject, s[i]))
			return (i);
		i++;
	}
	return (i);
}

/*----------------------

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_strcspn(const char *s, const char *reject);

int	main(void)
{
	char	s[] = "Hello, World!";
	char	*found;
	size_t	index;

	found = ft_strchr(s, 'W');
	if (found)
		printf("Found character 'W' at position %ld in \"%s\"\n", found - s, s);
	else
		printf("Character 'W' not found in \"%s\"\n", s);

	index = ft_strcspn(s, "o");
	printf("Index of first occurrence of 'o' in \"%s\" is %ld\n", s, index);

	return (0);
}

-----------------------------*/
