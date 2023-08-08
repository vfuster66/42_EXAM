/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:34:32 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 17:55:15 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>

-----------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	next;

	// Verifier le nombre exact d'arguments
	if (ac == 2)
	{
		// Boucle pour parcourir la chaine de caracteres jusqu'a la fin
		while (av[1][i])
			i++;
		// Revenir au caractere precedent '\0'
		i--;
		// Boucle tant que i n'est pas revenu au debut de la chaine
		while (i >= 0)
		{
			// Si le caractere actuel est un espace, un mot est trouve
			if (av[1][i] == ' ')
			{
				// Boucle pour parcourir le mot inverse a partir du caractere suivant
				// et tant qu'il ne rencontre pas d'espace
				next = i + 1;
				while (av[1][next] && av[1][next] != ' ')
				{
					// Afficher le mot
					write(1, &av[1][next], 1);
					next++;
				}
				// Afficher un espace
				write(1, " ", 1);
			}
			// Ou si le debut de la chaine est atteint
			else if (i == 0)
			{
				// Boucle pour parcourir le mot inverse a partir du caractere actuel
				// et tant qu'il ne rencontre pas d'espace
				next = i;
				while (av[1][next] && av[1][next] != ' ')
				{
					// Afficher le mot
					write(1, &av[1][next], 1);
					next++;
				}
			}
			// Passer au mot precedent
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
