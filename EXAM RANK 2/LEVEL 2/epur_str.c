/*Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>

-------------------------------------*/

#include <unistd.h>

int     main(int ac, char const *av[])
{
        int     i;
        int     flag;
        
        if (ac == 2)
        {
                i = 0;
                // Ignorer les espaces et tabulations au début de la chaîne
                while (av[1][i] == ' ' || av[1][i] == '\t')
                        i += 1;
                while (av[1][i])
                {
                        // Si on rencontre un espace ou une tabulation, activer le flag
                        if (av[1][i] == ' ' || av[1][i] == '\t')
                                flag = 1;
                        // Si on rencontre un caractère qui n'est pas un espace ou une tabulation
                        if (!(av[1][i] == ' ' || av[1][i] == '\t'))
                        {
                                // Si le flag est actif, ajouter un espace avant d'ajouter le caractère
                                if (flag)
                                        write(1, " ", 1);
                                // Désactiver le flag et ajouter le caractère
                                flag = 0;
                                write(1, &av[1][i], 1);
                        }
                        i += 1;
                }
        }
        // Ajouter un saut de ligne à la fin
        write(1, "\n", 1);
        return (0);
}
