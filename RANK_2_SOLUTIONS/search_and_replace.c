/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:58:01 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/11 09:36:02 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
-------------------------

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
zaz$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $

-----------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	
	// Verifier le nombre exact d'arguments et que les arguments av[2] et av[3]
	// ne comportent qu'un seul caractere
	if (ac == 4 && av[2][1] == '\0' && av[3][1] == '\0')
	{
		// Boucle pour parcourir la chaine de caracteres jusqu'a la fin
		while (av[1][i])
		{
			// Si le caractere de av[2] est egal au caractere actuel de av[1]
			if (av[1][i] == av[2][0])
				// Remplacer le caractere actuel de av[1] par le caractere de av[3]
				av[1][i] = av[3][0];
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
