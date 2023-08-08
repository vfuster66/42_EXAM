/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:17:51 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/11 09:10:13 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
----------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$> 
-----------------------------------*/

#include <unistd.h>

// Afficher un nombre entier sur la sortie standard
void	ft_putnbr(int n)
{
	char	c;
	
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{
	// nombre de 1...
	int	nombre = 1;

	// ... a 100
	while (nombre <= 100)
	{
		// Verifier si le nombre est divisible par 3 et par 5
		if (nombre % 3 == 0 && nombre % 5 == 0)
			write(1, "fizzbuzz", 8);
		// Ou verifier si le nombre est divisible par 3
		else if (nombre % 3 == 0)
			write(1, "fizz", 4);
		// Ou verifier si le nombre est divisible par 5
		else if (nombre % 5 == 0)
			write(1, "buzz", 4);
		// Ou afficher  le nombre qui ne fait pas partie des conditions ci-dessus
		else
			ft_putnbr(nombre);
		write(1, "\n", 1);
		// Passer au nombre suivant
		nombre++;
	}
	return (0);
}
