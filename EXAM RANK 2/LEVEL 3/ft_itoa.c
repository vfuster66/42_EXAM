/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
-----------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);

------------------------------*/
#include <stdlib.h>

char	*ft_itoa(int n)
{
    // pointeur vers le début de la chaîne de caractères
    char	*str;
    // longueur de la chaîne de caractères
    int	len;
    // indicateur pour savoir si le nombre est négatif
    int	sign;
    // variable temporaire pour stocker la valeur de n
    int	temp;

    // retourne la chaîne de caractères "0" si n est égal à 0
    if (n == 0)
        return ("0");   
    len = 0;
    sign = 0;
    if (n < 0)
    {
        // indique que le nombre est négatif
        sign = 1;
        // change la valeur de n en positive
        n = -n;         
    }
    temp = n;
    while (temp > 0)
    {
        // divise temp par 10 pour obtenir le nombre de chiffres dans n
        temp /= 10;     
        len++;
    }
    if (sign)
        // ajoute 1 à la longueur de la chaîne de caractères si le nombre est négatif
        len++;
    // alloue de la mémoire pour la chaîne de caractères
    str = (char *)malloc(sizeof(char) * (len + 1));
    // ajoute un caractère nul à la fin de la chaîne de caractères
    str[len] = '\0';    
    while (len > 0)
    {
        len--;
        // ajoute le chiffre correspondant à la fin de la chaîne de caractères
        str[len] = (n % 10) + '0';  
        n /= 10;
    }
    if (sign)
        // ajoute le signe "-" au début de la chaîne de caractères si le nombre est négatif
        str[0] = '-';
    // retourne la chaîne de caractères représentant n
    return (str);       
}

/*---------------------------------------

 #include <stdio.h>
 #include <limits.h>

 int		main(void)
 {
 	int d = INT_MIN;
 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = -13;
 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = 0;
 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = 5;
 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = INT_MAX;
 	printf("%d =? %s\n", d, ft_itoa(d));
 }
 
 ----------------------------------------*/
 
