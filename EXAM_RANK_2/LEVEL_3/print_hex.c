/*Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
-----------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$

------------------------------*/

#include <unistd.h>

// Cette fonction convertit une chaîne de caractères représentant un entier en un entier.
int ft_atoi(char *str)
{
        // compteur de caractères
        int     i;
        // entier résultat
        int     result;

        i = 0;
        result = 0;
        // tant que la chaîne n'est pas terminée...
        while (str[i])
        {
                // on multiplie le résultat par 10 et on ajoute la valeur du caractère courant
                result = result * 10 + str[i] - '0';
                // on passe au caractère suivant
                i++;
        }
        // on retourne le résultat
        return (result);		
}

// Cette fonction convertit un entier en sa représentation en base 16 et l'affiche sur la sortie standard.
void ft_print_hex(int n)
{
        // tableau des chiffres hexadécimaux
        char hex[] = "0123456789abcdef";
        // si l'entier est supérieur ou égal à 16...
        if (n >= 16)
                // on appelle récursivement la fonction avec le quotient de la division par 16
                ft_print_hex(n / 16);
        // on écrit le chiffre hexadécimal correspondant au reste de la division par 16 sur la sortie standard
        write(1, &hex[n % 16], 1);
}

int main(int ac, char **av)
{
        // entier à convertir
        int     n;

        // si le nombre d'arguments est égal à 2...
        if (ac == 2)
        {
                // on convertit la chaîne de caractères en entier
                n = ft_atoi(av[1]);
                // si l'entier est positif...
                if (n >= 0)
                        // on affiche sa représentation en base 16
                        ft_print_hex(n);
        }
        write(1, "\n", 1);
        return (0);
}
