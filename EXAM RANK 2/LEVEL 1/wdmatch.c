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

int main(int ac, char **av)
{
    int i;
    int j;
    
    // Vérifie s'il y a exactement 2 arguments
    if (ac != 3)
    {
        // Si ce n'est pas le cas, affiche une nouvelle ligne et quitte le programme
        write(1, "\n", 1);
        return 0;
    }
    i = 0;
    j = 0;
    while (av[1][i])
    {
        // Parcourt la deuxième chaîne de caractères jusqu'à trouver le même caractère
        // que celui de la première chaîne, ou jusqu'à atteindre la fin de la deuxième chaîne
        while (av[2][j] && av[1][i] != av[2][j])
               j++;
        // Si on a atteint la fin de la deuxième chaîne sans trouver le caractère, la fonction se termine
        if (av[2][j] == '\0')
        {
            write(1, "\n", 1);
            return 0;
        }
        // Si le caractère existe dans les deux chaînes, on passe au caractère suivant dans la première chaîne
        i++;
        j++;
    }
    // Si on a atteint cette ligne, c'est que tous les caractères de la première chaîne existent dans la deuxième chaîne
    i = 0;
    while (av[1][i])
    {
        // Affiche chaque caractère de la première chaîne
        write(1, &av[1][i], 1);
        i++;
    }
    // Affiche une nouvelle ligne à la fin
    write(1, "\n", 1);
    return 0;
}
