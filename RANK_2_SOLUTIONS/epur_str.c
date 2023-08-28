/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:23:46 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 18:29:27 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>

-------------------------------------*/

#include <unistd.h>

int main(int ac, char const **av)
{
	// index pour parcourir la chaine de caracteres
	int i = 0;
	// variable pour gerer les espaces
	int etat_des_espaces;

	// Verifier le nombre d'arguments
	if (ac == 2)
	{
		// Ignorer les esspaces et les tabulations
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		// Parcourir la chaine de caracteres jusqu' a la fin
		while (av[1][i])
		{
			// Verifier s'il y a un espace et activer le flag
			if (av[1][i] == ' ' || av[1][i] == '\t')
				etat_des_espaces = 1;
			// Verifier s'il n'y a pas d'espace ou de tab
			if (av[1][i] != ' ' && av[1][i] != '\t')
			{
				// Verifier si le flag est actif, afficher un espace
				if (etat_des_espaces)
					write(1, " ", 1);
				// Desactiver le flag
				etat_des_espaces = 0;
				// Afficher le caractere
				write(1, &av[1][i], 1);
			}
			// Passer au caractere suivant
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
