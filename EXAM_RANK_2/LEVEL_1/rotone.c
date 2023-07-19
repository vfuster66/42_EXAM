/*Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>

------------------------------*/

#include <unistd.h>

int     main(int ac, char **av)
{
        int     i;
        // Vérification si le nombre d'arguments est égal à 2
        if (ac != 2)
        {
                // Si ce n'est pas le cas, on écrit un retour à la ligne et on retourne 0
                write(1, "\n", 1);
                return (0);
        }
        i = 0;
        // Tant qu'on n'est pas à la fin de la chaîne de caractères, on continue
        while (av[1][i])
        {
                // Si le caractère est une lettre entre a et y ou A et Y, on incrémente de 1 dans le code ASCII
                if ((av[1][i] >= 'a' && av[1][i] < 'z') || (av[1][i] >= 'A' && av[1][i] < 'Z'))
                        av[1][i] += 1;
                // Si le caractère est z ou Z, on soustrait 25 dans le code ASCII pour revenir à a ou A
                else if (av[1][i] == 'z' || av[1][i] == 'Z')
                        av[1][i] -= 25;
                // On écrit le caractère modifié dans la sortie standard
                write(1, &av[1][i], 1);
                // On incrémente le compteur
                i++;
        }
        // On écrit un retour à la ligne et on retourne 0
        write(1, "\n", 1);
        return (0);
}
