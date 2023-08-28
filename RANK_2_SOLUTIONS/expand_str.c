/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:49:15 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 18:50:13 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str 
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>

-----------------------------------*/

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
				// Verifier si le flag est actif, afficher trois espaces
				if (etat_des_espaces)
					write(1, "   ", 3);
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
