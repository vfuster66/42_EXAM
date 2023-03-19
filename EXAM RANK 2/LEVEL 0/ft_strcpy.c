Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

/* Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2); */


#include <stdio.h>

char	*ft_strcpy(char *dst, const char *src)
{
	size_t i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	main(void)
{
	char src[] = "Hello World!";
	char dst[13];

	ft_strcpy(dst, src);
	printf("Source : %s\n", src);
	printf("Destination : %s\n", dst);
	return (0);
}
