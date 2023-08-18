/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:08:53 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/11 09:07:13 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
-------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

--------------------------------*/

#include <unistd.h>

int main(int ac, char **av)
{
	// Index pour parcourir la chaine de caracteres
	int	i = 0;

	// Verifier le nombre exact d'arguments
	if (ac == 2)
	{
		// Boucle pour ignorer les espaces, tabulations de debut de chaine
        	while (av[1][i] == ' ' || av[1][i] == '\t')
            		i++;
		// Verifier si la chaine est vide ou si elle ne contient que
		// des espaces ou des tabs
        	if (av[1][i] == '\0' || av[1][i] == '\n' || av[1][i] == '\t')
		{
			// Afficher un retour a la ligne et sortir du programme
            		write(1, "\n", 1);
            		return 0;
        	}
		// Boucle pour afficher le premier mot
		while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i] != '\0' 
			&& av[1][i] != '\n' && av[1][i] != '\r')
		{
			write(1, &av[1][i], 1);
            		i++;
        	}
    }
    write(1, "\n", 1);
    return 0;
}

