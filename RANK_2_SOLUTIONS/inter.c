/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:33:27 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 08:49:29 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$

-----------------------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	// Index pour parcourir les chaines
	int	i = 0;
	// Tableau de 256 elements pour stocker les caracteres presents de la
	// 2eme chaine
	int	tab[256];

	// Boucle pour initialiser tous les elements du tableau a 0 
	while (i < 256)
	{
		tab[i] = 0;
		i++;
	}
	// Verifier le nombre exact d'arguments
	if (ac == 3)
	{
		// Reinitialiser i
		i = 0;
		// Boucle pour parcourir av[2]
		while (av[2][i])
		{
			// Marquer la presence du caractere dans tab
			tab[(unsigned char)av[2][i]] = 1;
			i++;
		}
		// Reinitialiser i
		i = 0;
		// Boucle pour parcourir av[1]
		while (av[1][i])
		{
			// Si le caractere actuel de av[1] est present dans av[2]
			if (tab[(unsigned char)av[1][i]] == 1)
			{
				// Afficher le caractere actuel
				write(1, &av[1][i], 1);
				// Marquer la presence du caractere dans tab pour eviter les doublons
				tab[(unsigned char)av[1][i]] = 2;
			}
			// Passer au caractere suivant
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
			
