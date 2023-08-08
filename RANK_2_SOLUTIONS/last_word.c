/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:14:10 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 09:23:18 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
---------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

----------------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	// Index pour parcourir la chaine de caracteres
	int	i = 0;

	// Verifier le nombre exact d'arguments
	if (ac == 2)
	{
		// Boucle qui avance pour parcourir la chaine de caracteres jusqu'a la fin
		while (av[1][i])
			i++;
		// Boucle qui recule pour ignorer les espaces et les tabs en partant 
		// du caractere precedent '\0'
		while (--i && (av[1][i] == ' ' || av[1][i] == '\t'))
			;
		// Boucle qui recule tant qu'il n'y a pas d'espace ou de tab
		while (i && av[1][i] != ' ' && av[1][i] != '\t')
			i--;
		// Boucle qui avance pour ignorer les espaces ou les tabs
		if (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		// Boucle qui avance tant qu'il  n'y a pas d'espace ou de tab
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
		{
			// Afficher les caracteres du dernier mot
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
} 
