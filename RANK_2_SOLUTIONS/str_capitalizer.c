/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:51:44 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 10:52:05 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
-------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>

-------------------------------------*/

#include <unistd.h>

int main(int ac, char **av)
{
	// Argument
	int	i = 1;
	// Index de l'argument
	int	j;

	// S'il n'y a pas d'argument, afficher un retour a la ligne
	if (ac == 1)
		write(1, "\n", 1);
	// Ou s'il y a au moins 1 argument
	else
	{
		// Boucle pour parcourir tous les arguments 
		while (i < ac)
		{	
			j = 0;
			// Si le 1er caractere de l'argument est une lettre minuscule
			if (av[i][j] >= 'a' && av[i][j] <= 'z')
				// Mettre la lettre en majuscule
				av[i][j] -= 32;
			// Afficher le caractere
			write(1, &av[i][j], 1);
			// Boucle qui parcourt les caracteres suivants de l'argument
			while (av[i][++j])
			{
				// Si le caractere actuel est une lettre majuscule
				if (av[i][j] >= 'A' && av[i][j] <= 'Z')
					// Passer la lettre en minuscule
					av[i][j] += 32;
				// Si le caractere actuel est une lettre minuscule et le caractere suivant est un espace ou une tab ou un cractere nul
				if ((av[i][j] >= 'a' && av[i][j] <= 'z') && (av[i][j - 1] == ' ' || av[i][j - 1] == '\t' || av[i][j - 1] == '\0'))
					// Passer la lettre en majuscule
					av[i][j] -= 32;
				write(1, &av[i][j], 1);
				
			}
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
