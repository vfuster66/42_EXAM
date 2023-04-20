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

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	// Boucle jusqu'à la fin de la chaîne s
	while (s[i])
	{
		// Initialisation de l'indice j à 0 pour chaque caractère de la chaîne s
		j = 0;
		// Boucle jusqu'à la fin de la chaîne reject
		while (reject[j])
		{
			// Si le caractère s[i] est présent dans reject
			if (s[i] == reject[j])
			{
				// On retourne l'indice i correspondant au caractère s[i]
				return (i);
			}
			// On passe au caractère suivant dans la chaîne reject
			j++;
		}
		// On passe au caractère suivant dans la chaîne s
		i++;
	}
	// Si aucun caractère de s n'est présent dans reject, on retourne la longueur de s
	return (i);
}

/*----------------------

#include <stdio.h>
#include <string.h>

size_t ft_strcspn(const char *s, const char *reject);

int main(void)
{
    char str1[] = "Hello world";
    char str2[] = "Hello";
    char str3[] = "world";
    char str4[] = "12345";
    char str5[] = "67890";
    char str6[] = "1234567890";
    char reject1[] = " ";
    char reject2[] = "lo";
    char reject3[] = "789";

    printf("ft_strcspn: %zu\n", ft_strcspn(str1, reject1));
    printf("strcspn: %zu\n", strcspn(str1, reject1));

    printf("ft_strcspn: %zu\n", ft_strcspn(str1, reject2));
    printf("strcspn: %zu\n", strcspn(str1, reject2));

    printf("ft_strcspn: %zu\n", ft_strcspn(str1, reject3));
    printf("strcspn: %zu\n", strcspn(str1, reject3));

    printf("ft_strcspn: %zu\n", ft_strcspn(str2, str3));
    printf("strcspn: %zu\n", strcspn(str2, str3));

    printf("ft_strcspn: %zu\n", ft_strcspn(str4, str5));
    printf("strcspn: %zu\n", strcspn(str4, str5));

    printf("ft_strcspn: %zu\n", ft_strcspn(str6, reject3));
    printf("strcspn: %zu\n", strcspn(str6, reject3));

    return 0;
}

-------------------------------------*/
