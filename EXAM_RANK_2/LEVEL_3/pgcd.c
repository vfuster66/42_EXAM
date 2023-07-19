/*Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
---------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$

-----------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/* Cette fonction calcule le PGCD (Plus Grand Commun Diviseur) de deux entiers
   passés en argument en ligne de commande, et l'affiche sur la sortie standard. */
int     main(int ac, char **av)
{
        int     a;
        int     b;

        // si le nombre d'arguments est différent de 3, on affiche une ligne vide et on termine le programme
        if (ac != 3)	
        {
                printf("\n");
                return (0);
        }
        // on convertit la première chaîne de caractères en entier
        a = atoi(av[1]);
        // on convertit la deuxième chaîne de caractères en entier
        b = atoi(av[2]);
        // tant que les deux entiers sont différents...
        while (a != b)
        {
                // si le premier est plus grand que le deuxième...
                if (a > b)
                {
                        // on lui soustrait le deuxième
                        a = a - b;
                }
                else
                {
                        // on soustrait le premier au deuxième
                        b = b - a;
                }
        }
        // on affiche le PGCD (qui est dans a) sur la sortie standard
        printf("%d\n", a);	
        return (0);
}
