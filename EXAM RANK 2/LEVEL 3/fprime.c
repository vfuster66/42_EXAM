/*Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$

--------------------------------*/

#include <unistd.h>

void    ft_putnbr(int nb)
{
    if (nb >= 10)
        ft_putnbr(nb / 10);
    char c = nb % 10 + '0';
    write(1, &c, 1);
}

void    ft_putnbr_factor(int nb)
{
    int     i;

    i = 2;
    while (i <= nb)
    {
        if (nb % i == 0)
        {
            ft_putnbr(i);
            nb /= i;
            if (nb > 1)
                write(1, "*", 1);
            i = 1;
        }
        i++;
    }
    write(1, "\n", 1);
}

int     ft_atoi(char *str)
{
    int     nb;

    nb = 0;
    while (*str >= '0' && *str <= '9')
    {
        nb = nb * 10 + (*str - '0');
        str++;
    }
    return (nb);
}

int     main(int ac, char **av)
{
    if (ac != 2)
        write(1, "\n", 1);
    else
        ft_putnbr_factor(ft_atoi(av[1]));
    return (0);
}


