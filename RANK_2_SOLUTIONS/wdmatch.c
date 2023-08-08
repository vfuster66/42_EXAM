/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:06:11 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 10:39:47 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int ac, char **av)
{
	// Index pour parcourir av[1]
	int	i = 0;
	// Index pour parcourir av[2]
	int	j = 0;

	// Verifier le nombre exact d'arguments
	if (ac == 3)
	{
		// Boucle pour parcourir les 2 chaines de caracteres simultanement
		while (av[1][i] && av[2][j])
		{
			// Si les caracteres sont identiques
			if (av[1][i] == av[2][j])
				// Passer au caractere suivant de av[1]
				i++;
			// Passer au caractere suivant de av[2]
			j++;
		}
		// Si la chaine de caracteres av[1] a ete parcourue jusqu'a la fin
		// La chaine est entierement contenue dans av[2]
		if (av[1][i] == '\0')
		{
			// Reinitialiser i
			i = 0;
			// Boucle pour afficher av[1]
			while (av[1][i])
			{
				write(1, &av[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}

