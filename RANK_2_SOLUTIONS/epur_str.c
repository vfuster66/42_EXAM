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

int main(int ac, char **av)
{
	int	i = 0;
	int	space = -1;
	
	if (ac == 2)
	{
		while(av[1][i])
		{	
			if (av[1][i] != ' ' && av[1][i] != '\t')
			{
				if (space == 1)
					write(1, " ", 1);
				space = 0;
				write(1, &av[1][i], 1);
			}
			else if (space == 0)
				space = 1;
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
