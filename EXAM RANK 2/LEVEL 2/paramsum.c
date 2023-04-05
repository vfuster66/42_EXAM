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

int main(int ac, char **av)
{
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
    	int i = 1;
    	int count = 0;
    	while (av[i] != NULL)
    	{
        	i++;
        	count++;
    	}
    	char count_str[20];
    	int j = 0;
    	while (count > 0)
    	{
        	count_str[j] = count % 10 + '0';
        	count /= 10;
        	j++;
    	}
    	if (j == 0)
    	{
        	count_str[j] = '0';
        	j++;
    	}
    	count_str[j] = '\n';
    	write(1, count_str, j + 1);
    	return 0;
}
