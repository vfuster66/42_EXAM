/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:55:55 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 18:03:50 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
-----------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>

--------------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	// Index pour parcourir la chaine de caracteres
	int	i = 0;
	// Variable pour definir le début du 1er mot
	int	start;
	// Variable pour definir la fin du 1er mot
	int	end;
	// Variable pour marquer la presence d'un espace
	int	space = 0;

	// Verifier s'il y a plus d'un argument et que la chaine de caracteres n'est pas vide
	if (ac > 1 && av[1][0])
	{
		// Boucle pour ignorer les espaces et les tabs
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		// Marquer le debut du 1er mot
		start = i;
		// Boucle pour trouver la fin du 1er mot
		while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i] != '\0')
			i++;
		// Marquer la fin du 1er mot
		end = i;
		// Boucle pour ignorer les espaces et les tabs apres le 1er mot
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		// Boucle pour parcourir la chaine de caracteres jusqu'a la fin
		while (av[1][i])
		{
			// Boucle pour ignorer les espaces et les tabs consecutifs
			while ((av[1][i] == ' ' && av[1][i + 1] == ' ') 
					|| (av[1][i] == '\t' && av[1][i + 1] == '\t'))
				i++;
			// Si le caractere actuel est un espace ou une tab, mise a jour de space a 1
			if (av[1][i] == ' ' || av[1][i] == '\t')
				space = 1;
			write(1, &av[1][i], 1);
			i++;
		}
		// Si un espace est present, l'afficher
		if (space)
			write(1, " ", 1);
		Boucle pour afficher le 1er mot
		while (start < end)
		{
			write(1, &av[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
