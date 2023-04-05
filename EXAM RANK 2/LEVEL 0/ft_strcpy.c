/*Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
-------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);

-------------------------------*/

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
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
