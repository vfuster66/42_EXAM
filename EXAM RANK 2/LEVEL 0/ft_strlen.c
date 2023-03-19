
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);

int     ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

#include <stdio.h>

int ft_strlen(char *str);

int main()
{
    char str1[] = "Bonjour";
    char str2[] = "";
    char str3[] = "Ceci est une phrase assez longue pour tester la fonction ft_strlen";
    printf("La longueur de la chaîne \"%s\" est %d\n", str1, ft_strlen(str1));
    printf("La longueur de la chaîne \"%s\" est %d\n", str2, ft_strlen(str2));
    printf("La longueur de la chaîne \"%s\" est %d\n", str3, ft_strlen(str3));
    return (0);
}
