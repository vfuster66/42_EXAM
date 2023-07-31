/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:34:32 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 17:55:15 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>

-----------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	next;

	if (ac == 2)
	{
		while (av[1][i])
			i++;
		i--;
		while (i >= 0)
		{
			if (av[1][i] == ' ')
			{
				next = i + 1;
				while (av[1][next] && av[1][next] != ' ')
				{
					write(1, &av[1][next], 1);
					next++;
				}
				write(1, " ", 1);
			}
			else if (i == 0)
			{
				next = i;
				while (av[1][next] && av[1][next] != ' ')
				{
					write(1, &av[1][next], 1);
					next++;
				}
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
