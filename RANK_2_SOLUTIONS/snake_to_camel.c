/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:07:11 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 10:09:44 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
-------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$

---------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	// Index pour parcourir la chaine de caracteres
	int	i = 0;

	// Verifier le nombre exact d'arguments
	if (ac == 2)
	{
		// Boucle pour parcourir la chaine de caracteres jusqu'a la fin
		while (av[1][i])
		{
			// Si le caractere actuel est '_'
			if (av[1][i] == '_')
			{
				// Passer au caractere suivant
				i++;
				// Mettre la lettre minuscule en majuscule
				av[1][i] -= 32;
			}
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

