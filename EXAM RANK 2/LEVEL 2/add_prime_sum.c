/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
-----------------------------------

Écrire un programme qui prend un entier positif en argument et affiche la somme
de tous les nombres premiers inférieurs ou égaux à ce paramètre, suivie d'un
\n.

Si le nombre d'arguments n'est pas 1, ou que l'argument n'est pas positif,
afficher 0 et un \n.

Oui, les exemples sont justes.

Exemples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

-----------------------------*/

#include <unistd.h>

// Fonction récursive pour afficher un entier n en utilisant la fonction write()
void    ft_putnbr(int n)
{
    char    c;

    if (n > 9)
        // Appel récursif pour afficher les chiffres de gauche à droite
        ft_putnbr(n / 10);
     // Conversion du chiffre en caractère et écriture sur la sortie standard
    c = n % 10 + '0';
    write(1, &c, 1);
}

// Fonction pour convertir une chaîne de caractères en un entier
int     ft_atoi(char *str)
{
    int     i;
    int     result;

    i = 0;
    result = 0;
    while (str[i])
    {
        // Multiplication par 10 pour décaler le chiffre précédent d'une position décimale
        // et addition du chiffre actuel
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result);
}

// Fonction pour vérifier si un entier est premier
int     ft_is_prime(int n)
{
    int     i;

    if (n <= 1)
        return (0);
    i = 2;
    while (i * i <= n)
    {
        // Si n est divisible par i, alors n n'est pas premier
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int     main(int ac, char **av)
{
    int     i;
    int     result;

    if (ac != 2)
    {
        // Si le nombre d'arguments n'est pas 2, afficher 0 et un saut de ligne et quitter le programme
        write(1, "0\n", 2);
        return (0);
    }

    i = 2;
    result = 0;
    while (i <= ft_atoi(av[1]))
    {
        // Si i est premier, ajouter i à la somme des nombres premiers
        if (ft_is_prime(i))
            result += i;
        i++;
    }

    // Afficher la somme des nombres premiers suivie d'un saut de ligne
    ft_putnbr(result);
    write(1, "\n", 1);

    return (0);
}
