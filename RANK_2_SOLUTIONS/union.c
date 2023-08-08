/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:47:25 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 10:17:54 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union 
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>

-------------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	// Index pour parcourir les chaines de caracteres
	int	i = 0;
	// Tableau de 256 elements pour garder une trace des elements deja rencontres
	int	tab[256];

	// Initialiser toutes les valeurs du tableau a 0
	if (i < 256)
	{
		tab[i] = 0;
		i++;
	}
	// Verifier le nombre exact des arguments
	if (ac == 3)
	{
		// Reinitialiser i
		i = 0;
		// Boucle pour parcourir la 1ere chaine de caracteres jusqu'a la fin
		while (av[1][i])
		{
			// Si le caractere actuel n'a jamais ete rencontree
			if (tab[(unsigned char)av[1][i]] == 0)
			{
				// Mise a jour de tab pour dire que le caractere a ete rencontre
				tab[(unsigned char)av[1][i]] = 1;
				// Afficher le caractere actuel
				write(1, &av[1][i], 1);
			}
			// Passer au caratere suivant
			i++;
		}
		// Reinitialiser i
		i = 0;
		// Boucle pour parcourir la 2eme chaine de caracteres
		while (av[2][i])
		{
			// Si le caractere actuel n'a jamais ete rencontree
			if (tab[(unsigned char)av[2][i]] == 0)
			{
				// Mise a jour de tab pour dire que le caractere a ete rencontre
				tab[(unsigned char)av[2][i]] = 1;
				// Afficher le caractere actuel
				write(1, &av[2][i], 1);
			}
			// Passer au caractere suivant
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
