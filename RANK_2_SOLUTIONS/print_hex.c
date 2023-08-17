/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:58:55 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 10:04:24 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
-----------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$

------------------------------*/

#include <unistd.h>

// Fonction pour convertir une chaine de caracteres en entier
int	ft_atoi(char *str)
{
	int	i = 0;
	int	result = 0;

	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

// Fonction pour afficher la representation hexadecimale de l'entier sur la sortie standard
void	putnbr_hex(int n)
{
	char	tab[] = "0123456789abcdef";

	if (n >= 16)
		putnbr_hex(n / 16);
	write(1, &tab[n % 16], 1);
}

int	main(int ac, char **av)
{
	// Verifier le nombre exact d'arguments
	if (ac == 2)
	{
		// Si av[1] est positif
		if (ft_atoi(av[1]) >= 0)
			// Afficher la representation hexadecimale de av[1]
			putnbr_hex(ft_atoi(av[1]));
	}
	write(1, "\n", 1);
	return (0);
}
