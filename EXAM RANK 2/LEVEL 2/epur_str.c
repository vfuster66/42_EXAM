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

int main(int ac, char **av)
{
        int        i = 0;
        int        space = -1;
    
        if (ac == 2)
        {
                while (av[1][i])
                {
                        // Vérifie si le caractère actuel n'est pas un espace ou une tabulation      
                        if (av[1][i] != ' ' && av[1][i] != '\t')
                        {
                                // Si le caractère précédent était un espace
                                if (space == 1)
                                        // Écrit un espace dans la sortie standard pour séparer les mots
                                        write(1, " ", 1);
                                // Le caractère actuel n'est pas un espace, donc isSpace est mis à 0
                                space = 0;
                                // Écrit le caractère actuel dans la sortie standard
                                write(1, &av[1][i], 1); 
                        }
                        // Si le caractère actuel est un espace et le caractère précédent n'était pas un espace
                        else if (space == 0)
                                // isSpace est mis à 1 pour indiquer qu'un espace consécutif a été rencontré
                                space = 1;
                        // Passe au caractère suivant
                        i++; 
                }
        }
        // Écrit un saut de ligne à la fin de la sortie standard
        write(1, "\n", 1);
        return 0;
}

