/*Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>

---------------------------------*/

#include <unistd.h>

int		main(int ac, const char **av)
{
	int n; 
	char c;
	
	n = ac - 1;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		main(n / 10, av);
		main(n % 10, av);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
	return (0);
}
