/*Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
----------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>

--------------------------------*/

#include <unistd.h>

int     main(int ac, char **av)
{
        int i;
        int j;
        int k;
    
        i = 0;
        if (ac == 2)
        {
                while (av[1][i])
                {
                        k = 1;
                        if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                                k = av[1][i] - 64;
                        if (av[1][i] >= 'a' && av[1][i] <= 'z')
                                k = av[1][i] - 96;
                        j = 0;
                        while (j < k)
                        {
                                write(1, &av[1][i], 1);
                                j++;
                        }
                        i++;
                }
        }
        write(1, "\n", 1);
        return (0);
}


