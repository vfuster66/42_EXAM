/*Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>

------------------------------------*/

#include <stdlib.h>
#include <unistd.h>

void    ft_putnbr(int nb)
{
    char    c;
    
    // Fonction récursive pour afficher un nombre entier en utilisant write
    if (nb >= 10)
        // On divise nb par 10 pour obtenir le nombre de dizaines, centaines, etc.
        ft_putnbr(nb / 10);
    // On calcule le chiffre des unités en faisant nb modulo 10 et en ajoutant le code ASCII pour '0'
    c = nb % 10 + '0';
    // On écrit le chiffre des unités
    write(1, &c, 1);
}

int ft_atoi(char *str)
{
    // Fonction pour convertir une chaîne de caractères en un entier
    int result;
    int i;
    
    result = 0;
    i = 0
    while (str[i] >= '0' && str[i] <= '9')
    {
        // On multiplie result par 10 pour décaler les chiffres et on ajoute le chiffre courant de la chaîne
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result);
}

void print_table(int n, int i)
{
    // Fonction récursive pour afficher la table de multiplication de n jusqu'à 9*n
    if (i <= 9)
    {
        // On affiche le multiplicateur
        ft_putnbr(i);
        // On affiche le symbole 'x' pour indiquer la multiplication
        write(1, " x ", 3);
        // On affiche le multiplicande
        ft_putnbr(n);
        // On affiche le symbole '=' pour indiquer le résultat
        write(1, " = ", 3);
        // On affiche le résultat de la multiplication
        ft_putnbr(n * i);
        // On saute une ligne pour passer à la multiplication suivante
        write(1, "\n", 1);
        // On appelle la fonction récursivement pour afficher la multiplication suivante
        print_table(n, i + 1);
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        // Si le nombre d'arguments est incorrect, on affiche une ligne vide et on termine le programme
        write(1, "\n", 1);
        return 0;
    }
    // On convertit le premier argument en un entier
    int n = ft_atoi(av[1]);
    // On affiche la table de multiplication pour ce nombre
    print_table(n, 1); 
    return 0;
}
