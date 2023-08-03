/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:48:02 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 09:53:00 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//Version 1
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	a;
	int	b;
	
	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		while (a != b)
		{
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		printf("%d", a);
	}
	printf("\n");
	return (0);
}

//Version 2

#include <stdio.h>
#include <stdlib.h>

int     main(int ac, char **av)
{
        int     a;
        int     b;
        int     temp;

        if (ac == 3)
        {
                a = atoi(av[1]);
                b = atoi(av[2]);
                while (b != 0)
                {
                        temp = b;
                        b = a % b;
                        a = temp;
                }
                printf("%d", a);
        }
        printf("\n");
        return (0);
}

//Version 3

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	int	a;
	int	b;
	int	n;
	
	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		n = a;
		while (n > 0)
		{
			if (a % n == 0 && b % n == 0)
			{
				printf("%d\n", n);
				return ;
			}
			n--;
		}
	}	
	printf("\n");
	return (0);
}
