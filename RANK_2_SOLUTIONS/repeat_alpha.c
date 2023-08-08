/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:25:06 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/11 09:21:25 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
----------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>

--------------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	compteur;
	int	multiplicateur;

	// Verifier le nombre exact d'arguments
	if (ac == 2)
	{
		i = 0;
		// Boucle pour parcourir la chaine de caracteres
		while (av[1][i])
		{
   			multiplicateur = 1;
			// Verifie si le caractere est une lettre
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				// ex : 'A' - 64 = 65 - 64 = 1
				multiplicateur = av[1][i] - 64;
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
				// ex : 'a' - 96 = 97 - 96 = 1
				multiplicateur = av[1][i] - 96;
			j = 0;
			Boucle qui itere tant que le compteur est plus petit que le multiplicateur
			while (compteur < multiplicateur)
			{
				write(1, &av[1][i], 1);
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
