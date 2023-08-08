/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:14:08 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 10:40:35 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
-------------------------------------

Write a program that takes one or more strings and, for each argument, puts 
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>

-------------------------------------*/

#include <unistd.h>

int		main(int ac, char **av)
{
	// Argument
	int		i = 1;
	// Index de l'argument
	int		j;

	// Verifier s'il n'y a qu'un argument, afficher un retour a la ligne
	if (ac == 1)
		write(1, "\n", 1);
	// Ou s'il y a plusieurs arguments 
	else
	{
		// Boucle pour parcourir tous les arguments 
		while (i < ac)
		{
			j = 0;
			// Boucle pour parcourir chaque caractere de chaque argument
			while (av[i][j])
			{
				// Si le caractere actuel est une lettre majuscule
				if (av[i][j] >= 'A' && av[i][j] <= 'Z')
					// Mettre la lettre en miniscule
					av[i][j] += 32;
				// Si le caractere actuel est une lettre minuscule et
				// que le caractere suivant est un espace ou une tab ou un caractere nul
				if ((av[i][j] >= 'a' && av[i][j] <= 'z') 
						&& (av[i][j + 1] == ' ' 
						|| av[i][j + 1] == '\t' 
						|| av[i][j + 1] == '\0'))
					// Mettre la lettre en majuscule
					av[i][j] -= 32;
				write(1, &av[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}


