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
	char	temp;

	// si la chaîne de caractères est nulle
	if (!str)
		return (NULL);
	// on pointe sur le début de la chaîne de caractères
	start = str;
	// on pointe sur le début de la chaîne de caractères
	end = str;
	// tant qu'on n'a pas atteint la fin de la chaîne de caractères
	while (*end != '\0')
		// on avance jusqu'à la fin de la chaîne de caractères
		end++;
	// on se place sur le dernier caractère de la chaîne de caractères
	end--;
	// tant que le pointeur de début est avant le pointeur de fin
	while (start < end) 
	{
		// on stocke le caractère pointé par le pointeur de début dans la variable temp
		temp = *start;
		// on remplace le caractère pointé par le pointeur de début par le caractère pointé par le pointeur de fin
		*start = *end;
		// on remplace le caractère pointé par le pointeur de fin par le caractère stocké dans la variable temp
		*end = temp;
		// on avance le pointeur de début
		start++;
		// on recule le pointeur de fin
		end--;
	}
	// on retourne la chaîne de caractères inversée
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
