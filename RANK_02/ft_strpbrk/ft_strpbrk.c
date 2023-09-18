#include <stdlib.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	const char *debut_s2 = s2;

	while (*s1)
	{
		s2 = debut_s2;
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

