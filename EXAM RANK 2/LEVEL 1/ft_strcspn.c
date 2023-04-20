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
	while (s[i] != '\0')    
	{
		// Initialisation de l'indice j à 0 pour chaque caractère de la chaîne s
		j = 0;
		// Boucle jusqu'à la fin de la chaîne reject
		while (reject[j] != '\0')   
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
