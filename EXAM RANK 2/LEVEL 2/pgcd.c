/*Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
---------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$

-----------------------------------*/

#include <unistd.h>

void ft_putnbr(int nb)
{
    if (nb >= 10)
        ft_putnbr(nb / 10);
    char c = nb % 10 + '0';
    write(1, &c, 1);
}

int ft_atoi(char *str)
{
    int result = 0;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        write(1, "\n", 1);
        return 0;
    }
    int a = ft_atoi(av[1]);
    int b = ft_atoi(av[2]);
    while (a != 0 && b != 0)
    {
        if (a > b)
            a = a % b;
	    else
            b = b % a;
    }
    int pgcd;
    if (a == 0)
        pgcd = b;
    else
        pgcd = a;
    ft_putnbr(pgcd);
    write(1, "\n", 1);
    return 0;
}
