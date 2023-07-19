/*Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
-------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);

-------------------------------*/

char	*ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    // Boucle tant que la chaîne n'est pas terminée
    while (src[i])
    {
        // On copie la valeur de la case src[i] dans la case correspondante de dest[i]
        dest[i] = src[i];
        // On incrémente i pour passer à la case suivante de la chaîne
        i++;
    }
    // On place le caractère nul ('\0') à la fin de la chaîne copiée dans dest
    dest[i] = '\0';
    // On renvoie le pointeur vers la chaîne de destination
    return (dest); 
}


/*----------------------------------

#include <unistd.h>

char	*ft_strcpy(char *s1, char *s2);

int main()
{
    char src[] = "Hello World!";
    char dest[20];
    
    printf("Source : %s\n", src);
    ft_strcpy(dest, src);
    printf("Destination : %s\n", dest);
    return (0);
}

-----------------------------------*/
