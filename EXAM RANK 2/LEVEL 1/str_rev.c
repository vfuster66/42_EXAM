/*Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions: 
--------------------------------------------------------------------------------

Écrire une fonction qui inverse (en place) une chaîne de caractères.

Elle devra renvoyer son paramètre.

Votre fonction devra être prototypée de la façon suivante :

char    *ft_strrev(char *str);

----------------------------------------*/

#include <stdlib.h>

char	*str_rev(char *str)
{
	char	*start;
	char	*end;

	if (!str)
		return (NULL);
	start = str;
	end = str;
	while (*end != '\0')
		end++;
	end--;
	char	temp;
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	return (str);
}

/*-------------------------------

#include <stdio.h>
#include <stdlib.h>

char	*str_rev(char *str);

int	main()
{
	char str[] = "Hello World";
	printf("Original string: %s\n", str);
	str_rev(str);
	printf("Reversed string: %s\n", str);
	return (0);
}
----------------------------------*/