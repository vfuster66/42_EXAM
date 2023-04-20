/*Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>

-----------------------------*/

#include <unistd.h>

int main(int ac, char *av[])
{
    int len;
    int i;

    // Vérifie qu'il y a un argument en entrée
    if (ac == 2) 
    {
        len = 0;
        // Calcule la longueur de la chaîne de caractères en entrée
        while (av[1][len]) 
            len++;
        // Soustrait 1 à la longueur pour accéder à l'index le plus à droite
        len--;
        // Parcourt la chaîne de caractères de droite à gauche
        while (len >= 0) 
        {
            // Si un espace est trouvé, affiche le mot suivant
            if (av[1][len] == ' ') 
            {
                // Démarre à l'index suivant
                i = len + 1;
                // Parcourt le mot jusqu'à un nouvel espace ou la fin de la chaîne
                while (av[1][i] && av[1][i] != ' ') 
                {
                    // Affiche chaque caractère du mot
                    write(1, &av[1][i], 1); 
                    i++;
                }
                // Ajoute un espace entre les mots
                write(1, " ", 1); 
            }
            // Si le début de la chaîne est atteint, affiche le premier mot
            else if (len == 0) 
            {
                int i = len;
                // Parcourt le mot jusqu'à un espace ou la fin de la chaîne
                while (av[1][i] && av[1][i] != ' ') 
                {
                    // Affiche chaque caractère du mot
                    write(1, &av[1][i], 1); 
                    i++;
                }
            }
             // Décrémente la longueur pour accéder à l'index suivant
            len--;
        }
    }
    // Ajoute un retour à la ligne à la fin de l'affichage
    write(1, "\n", 1);
    return (0);
}
