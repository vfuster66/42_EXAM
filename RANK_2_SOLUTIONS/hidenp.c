/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 08:29:08 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 08:36:46 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
-------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>

-------------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	// Index pour parcourir av[1]
	int	i = 0;
	// Index pour parcourir av[2]
	int	j = 0;

	// Verifier le nombre exact d'arguments
	if (ac == 3)
	{
		// Boucle qui parcourt les 2 chaines simultanement
		while (av[1][i] && av[2][j])
		{
			// Si le caractere de av[1] est present dans av[2]
			if (av[1][i] == av[2][j])
				// Passer au caractere suivant de av[1]
				i++;
			// Passer au caractere suivant de av[2]
			j++;
		}
		// Si la fin de la chaine av[1] est atteinte, tous les caracteres ont ete
		// trouves dans av[2]
		if (av[1][i] == '\0')
			write(1, "1", 1);
		// Ou si la fin de la chaine av[1] n'a pas ete atteinte, au moins 1 caractere
		// n'a pas ete trouve dans av[2]
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
