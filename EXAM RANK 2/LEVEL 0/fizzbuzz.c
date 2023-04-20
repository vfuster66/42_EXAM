/*Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
----------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$> 
-----------------------------------*/

#include <unistd.h>

void    ft_putnbr(int n)
{
        char    c;
        
        if (n >= 10)
                // Récursivement, on divise le nombre par 10 pour extraire chaque chiffre
                ft_putnbr(n / 10);
        // On ajoute '0' pour obtenir le caractère correspondant à ce chiffre dans la table ASCII
        c = n % 10 + '0';
        // On écrit ce caractère sur la sortie standard
        write(1, &c, 1);
}

int     main(void)
{
        int     i;
        
        i = 1;
        while (i <= 100)
        {
                // Si le nombre est divisible par 3 et 5
                if (i % 3 == 0 && i % 5 == 0)
                        // On écrit "fizzbuzz" sur la sortie standard
                        write(1, "fizzbuzz", 8);
                // Si le nombre est divisible par 3
                else if (i % 3 == 0)
                        // On écrit "fizz" sur la sortie standard
                        write(1, "fizz", 4);
                // Si le nombre est divisible par 5
                else if (i % 5 == 0)
                        // On écrit "buzz" sur la sortie standard
                        write(1, "buzz", 4);
                else
                        // Sinon, on écrit le nombre sur la sortie standard
                        ft_putnbr(i);
                // On ajoute une nouvelle ligne à la fin de chaque sortie
                write(1, "\n", 1);
                // On incrémente i pour passer au nombre suivant
                i++;
        }
        return (0);
}


