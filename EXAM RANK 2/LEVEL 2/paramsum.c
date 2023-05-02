/*Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>

---------------------------------*/

#include <unistd.h>

// Fonction récursive pour afficher les chiffres de n
void ft_putnbr(int n)
{       
        char    digit;
        if (n >= 10)
                ft_putnbr(n / 10);  // Appel récursif pour afficher les chiffres de n/10
        digit = n % 10 + '0';  // Convertit le dernier chiffre en caractère
        write(1, &digit, 1);   // Écrit le caractère sur la sortie standard
}       

int main(int ac, char **av)
{       
        (void)av;  // Utilisation inutile de av, évite un avertissement de compilation
        
        ft_putnbr(ac - 1);  // Appelle ft_putnbr avec le nombre d'arguments moins 1
        write(1, "\n", 1);  // Écrit un saut de ligne sur la sortie standard
        return (0);
} 
