/*Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$

-----------------------------------------*/

#include <unistd.h>

int main(int ac, char **av)
{
    // Compteur pour les boucles
    int i;
    // Tableau pour stocker les valeurs ASCII
    int ascii[256];

    // Initialisation du tableau ascii à 0 pour toutes les valeurs possibles de l'ASCII
    i = 0;
    while (i < 256)
    {
        ascii[i] = 0;
        i++;
    }

    // Si le nombre d'arguments n'est pas égal à 3, on écrit un retour à la ligne et on retourne 0
    if (ac != 3)
    {
        write(1, "\n", 1);
        return 0;
    }

    // Remplissage du tableau ascii avec les valeurs ASCII des caractères de la deuxième chaîne de caractères
    i = 0;
    while (av[2][i])
    {
        ascii[(unsigned char)av[2][i]] = 1;
        i++;
    }

    // Parcours de la première chaîne de caractères pour afficher les caractères qui sont présents dans la deuxième chaîne
    i = 0;
    while (av[1][i])
    {
        if (ascii[(unsigned char)av[1][i]] == 1)
        {
            write(1, &av[1][i], 1);
            // Marquage du caractère dans le tableau ascii
            ascii[(unsigned char)av[1][i]] = 2; 
        }
        i++;
    }
    // Écriture d'un retour à la ligne
    write(1, "\n", 1); 
    return 0;
}
