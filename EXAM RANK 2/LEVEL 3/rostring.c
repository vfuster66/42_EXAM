/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
-----------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>

--------------------------------*/

#include <unistd.h>  // Bibliothèque pour utiliser la fonction write
#include <stdlib.h>  // Bibliothèque standard du C

int main(int ac, char **av)
{
    int i = 0;
    int start;
    int end;
    int flag;

    if (ac > 1 && av[1][0])
    {
        // Recherche des espaces ou tabulations au début du deuxième argument
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        start = i;

        // Recherche de la fin du premier mot dans le deuxième argument
        while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i] != '\0')
            i++;
        end = i;

        // Recherche des espaces ou tabulations après la fin du premier mot
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;

        // Affichage des mots sans espaces/tabs consécutifs
        while (av[1][i])
        {
            // Ignorer les espaces/tabs consécutifs
            while ((av[1][i] == ' ' && av[1][i + 1] == ' ') || (av[1][i] == '\t' && av[1][i + 1] == '\t'))
                i++;

            // Vérification si l'espace ou la tabulation est présente
            if (av[1][i] == ' ' || av[1][i] == '\t')
                flag = 1;

            // Affichage du caractère courant
            write(1, &av[1][i], 1);
            i++;
        }

        // Affichage d'un espace si nécessaire
        if (flag)
            write(1, " ", 1);

        // Affichage du premier mot
        while (start < end)
        {
            write(1, &av[1][start], 1);
            start++;
        }
    }

    // Affichage d'une nouvelle ligne
    write(1, "\n", 1);

    return (0);
}
	
