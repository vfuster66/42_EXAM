/*Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
-------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);

---------------------------------*/

#include <unistd.h>

int	ft_strlen(char *str)
{
	// Déclaration de la variable i qui va compter le nombre de caractères dans la chaîne
	int	i; 

	i = 0;
	// Boucle tant que la chaîne n'est pas terminée
	while (str[i])
		// On incrémente i pour passer à la case suivante de la chaîne
		i++;
	// On renvoie i, qui contient le nombre de caractères dans la chaîne
	return (i); 
}

/*----------------------------

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

int	main(void)
{
	char	str[] = "Hello, World!";
	int		len;

	len = ft_strlen(str);
	printf("Length of \"%s\" = %d\n", str, len);
	return (0);
}

-------------------------*/
