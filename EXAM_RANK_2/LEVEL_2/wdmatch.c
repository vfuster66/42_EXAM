/*Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$

------------------------------------------*/

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    // Vérifier qu'il y a 2 arguments en ligne de commande
    if (argc != 3)
    {
        // Afficher un saut de ligne et quitter
        write(1, "\n", 1);
        return (0);
    }
    // Initialiser les compteurs pour les deux chaînes
    i = 0;
    j = 0;
    // Parcourir les deux chaînes caractère par caractère
    while (argv[1][i] && argv[2][j])
    {
        // Si les deux caractères sont identiques, avancer dans la première chaîne
        if (argv[1][i] == argv[2][j])
        {
            i++;
        }
        // Avancer dans la deuxième chaîne dans tous les cas
        j++;
    }
    // Si on est arrivé à la fin de la première chaîne, cela signifie qu'on a trouvé
    // tous les caractères nécessaires dans la deuxième chaîne dans le bon ordre
    if (argv[1][i] == '\0')
    {
        // Réinitialiser le compteur pour la première chaîne
        i = 0;
        // Afficher chaque caractère de la première chaîne un par un
        while (argv[1][i])
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    // Afficher un saut de ligne et quitter
    write(1, "\n", 1);
    return (0);
}

