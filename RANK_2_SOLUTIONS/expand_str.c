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

int main(int ac, char **av)
{
	int	i = 0;
	// -1 = aucun espace rencontre pour le moment
	int	etat_des_espaces = -1;

	// Verifier le nombre exact d'arguments
	if (ac == 2)
	{
		// Parcourir la chaine de caracteres jusqu'a la fin
		while(av[1][i])
		{
			// Si le caractere actuel n'est pas un espace ou une tab
			if (av[1][i] != ' ' && av[1][i] != '\t')
			{
				// Si le caractere precedent est un espace ou une tab
				if (etat_des_espaces == 1)
					// Afficher 3 espaces
					write(1, "   ", 3);
				// Mise a jour de la variable 
				// 0 = caractere precedent different d'un espace ou d'une tab
				etat_des_espaces = 0;
				write(1, &av[1][i], 1);
			}
			// Ou si le caractere precedent est different d'un espace ou d'une tab 
			else if (etat_des_espaces == 0)
				// Mise a jour de la variable
				// 1 = caractere precedent egal a un espace ou une tab
				etat_des_espaces = 1;
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
