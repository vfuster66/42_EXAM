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
        int     nb1;
        int     nb2;
        int     temp;

        if (ac == 3)
        {
                nb1 = atoi(av[1]);
                nb2 = atoi(av[2]);
                while (nb2 != 0)
                {
                        temp = nb2;
                        nb2 = nb1 % nb2;
                        nb1 = temp;
                }
                printf("%d", nb1);
        }
        printf("\n");
        return (0);
}

//Version 3

#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int n = a;

	while (n > 0)
	{
		if (a % n == 0 && b % n == 0)
		{
			printf("%d", n);
			return;
		}
		--n;
	}
}
