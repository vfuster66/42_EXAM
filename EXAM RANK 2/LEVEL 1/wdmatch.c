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
    int len1 = 0;
    int len2 = 0;
    int i = 0;
    int j = 0;

    if (ac != 3) 
    {
        write(1, "\n", 1);
        return 0;
    }
    while (av[1][len1])
        len1++;
    while (av[2][len2])
        len2++;
    while (i < len1 && j < len2)
    {
        if (av[1][i] == av[2][j])
        {
		i++;
        }
        j++;
    }
    if (i == len1)
    {
        i = 0;
        while (av[1][i])
        {
            write(1, &av[1][i], 1);
            i++;
        }
        write(1, "\n", 1);
    }
    else 
    {
        write(1, "\n", 1);
    }
    return 0;
}


