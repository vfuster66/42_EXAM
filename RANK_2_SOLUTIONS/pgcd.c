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
	int	nb1;
	int	nb2;
	
	if (ac == 3)
	{
		nb1 = atoi(av[1]);
		nb2 = atoi(av[2]);
		while (nb1 != nb2)
		{
			if (nb1 > nb2)
				nb1 = nb1 - nb2;
			else
				nb2 = nb2 - nb1;
		}
		printf("%d", nb1);
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
                        nb2 = nb1 % mb2;
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

int		main(int ac, char **av)
{
	int	nb1;
	int	nb2;
	int	diviseur_commun;

	// Verifier le nombre exact d'arguments
	if (ac == 3)
	{
		// Convertir les 2 chaines de caracteres et les affecter a nb1 et nb2
		nb1 = atoi(av[1]);
		nb2 = atoi(av[2]);
		// Affecter nb1 a diviseur_commun
		diviseur_commun = nb1;
		// Boucle qui itere tant que le diviseur_commun est positif
		while (diviseur_commun > 0)
		{
			// Si nb1 et nb2 sont divisibles par le diviseur_commun
			if (nb1 % diviseur_commun == 0 && nb2 % diviseur_commun == 0)
			{
				// Afficher le diviseur_commun
				printf("%d\n", diviseur_commun);
				// Rtourner nb1
				return (nb1);
			}
			// Ou passer au diviseur_commun precedent
			diviseur_commun--;
		}
	}	
	printf("\n");
	return (0);
}
