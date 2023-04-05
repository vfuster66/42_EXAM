/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);

---------------------------------------------*/

#include <stdlib.h>

char    *ft_strdup(char *src)
{       
	int             i;
        char    *dest;
        
        i = 0;
        while (src[i])
                i++;
        dest = malloc(sizeof(char) * (i + 1));
        if (!dest)
                return (NULL);
        i = 0;
        while (src[i])
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = src[i];
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
