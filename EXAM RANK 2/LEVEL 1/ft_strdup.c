/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);

---------------------------------------------*/

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	// Déclaration de l'index i
	int		i;
	// Déclaration du pointeur de destination
	char	*dest;
	
	i = 0;
	// Boucle jusqu'à la fin de la chaîne src
	while (src[i])
		i++;
	// Allocation dynamique de la mémoire pour la chaîne de destination
	dest = malloc(sizeof(char) * (i + 1));
	// Si l'allocation échoue, on retourne NULL
	if (!dest)
		return (NULL);
	i = 0;
	// Boucle jusqu'à la fin de la chaîne src
	while (src[i])
	{
		// Copie du caractère src[i] dans dest[i]
		dest[i] = src[i];
		i++;
	}
	// Copie du caractère de fin de chaîne '\0' dans dest[i]
	dest[i] = src[i];
	// Retourne le pointeur de la chaîne de destination
	return (dest);
}

/*---------------------------------------------

#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *src);

int main(void)
{
    char *src = "Hello world!";
    char *dup = ft_strdup(src);

    if (dup == NULL)
    {
        printf("Erreur : échec de l'allocation mémoire.\n");
        return 1;
    }

    printf("La chaîne originale est : %s\n", src);
    printf("La chaîne dupliquée est : %s\n", dup);

    free(dup);
    return 0;
}

-----------------------------------------*/
