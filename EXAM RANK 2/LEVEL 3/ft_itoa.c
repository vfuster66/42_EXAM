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
 
/* Cette fonction calcule la valeur absolue d'un nombre entier (nbr).
   Si le nombre est négatif, elle le retourne avec le signe inversé,
   sinon elle le retourne sans modification. */

int absolute_value(int nbr)
{
    if (nbr < 0)
        return (-nbr);
    return (nbr);
}

/* Cette fonction calcule la longueur d'un nombre entier (nbr).
   Elle compte le nombre de chiffres en itérant sur le quotient de la division
   par 10 jusqu'à ce que le nombre devienne 0.
   Elle incrémente la variable len à chaque itération et gère le cas où nbr est nul ou négatif.
   La longueur du nombre est retournée. */

int get_len(int nbr)
{
    int len = 0;
    if (nbr <= 0)
        ++len;
    while (nbr != 0)
    {
        ++len;
        nbr = nbr / 10;
    }
    return (len);
}

/* Cette fonction convertit un nombre entier (nbr) en une chaîne de caractères.
   Elle commence par calculer la longueur de la chaîne nécessaire en appelant la fonction get_len(nbr).
   Ensuite, elle alloue la mémoire nécessaire pour la chaîne résultat à l'aide de malloc.
   La taille allouée est (len + 1) pour inclure le caractère nul de fin de chaîne.
   Elle initialise le dernier caractère de la chaîne à '\0'.

   Ensuite, elle traite les cas où nbr est négatif ou nul en plaçant le signe '-' ou '0' respectivement
   dans le premier caractère de la chaîne résultat.

   Ensuite, à l'aide d'une boucle while, elle itère sur chaque chiffre du nombre en utilisant la division
   et le modulo par 10. Elle convertit chaque chiffre en son équivalent en caractère en ajoutant '0' et
   place le caractère correspondant dans la chaîne résultat à l'index approprié en partant de la fin.

   Enfin, elle retourne la chaîne résultat. */

char *ft_itoa(int nbr)
{
    char *result;
    int len;

    len = get_len(nbr);
    result = malloc(sizeof(char) * (len + 1));
    result[len] = '\0';

    if (nbr < 0)
        result[0] = '-';
    else if (nbr == 0)
        result[0] = '0';

    while (nbr != 0)
    {
        --len;
        result[len] = absolute_value(nbr % 10) + '0';
        nbr = nbr / 10;
    }
    return (result);
}

 
//-------------------------------------------------------
// #include <stdio.h>
// #include <limits.h>
 
// int      main(void)
// {
//  int d = INT_MIN;
//  printf("%d =? %s\n", d, ft_itoa(d));
 
//  d = -13;
//  printf("%d =? %s\n", d, ft_itoa(d));
 
//  d = 0;
//  printf("%d =? %s\n", d, ft_itoa(d));
 
//  d = 5;
//  printf("%d =? %s\n", d, ft_itoa(d));
 
//  d = INT_MAX;
//  printf("%d =? %s\n", d, ft_itoa(d));
// }
 
 ----------------------------------------*/
 
