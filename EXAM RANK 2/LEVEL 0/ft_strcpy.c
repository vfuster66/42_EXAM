/*Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
-------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);

-------------------------------*/

#include <unistd.h>

char	*ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while ((s1[i] = s2[i]))
        i++;
    return (s1);
}

/*----------------------------------

#include <unistd.h>

char	*ft_strcpy(char *s1, char *s2);

int main()
{
    char s1[13];
    char s2[] = "Hello, World!";
    
    ft_strcpy(s1, s2);
    write(1, s1, sizeof(s1));
    return 0;
}

-----------------------------------*/
