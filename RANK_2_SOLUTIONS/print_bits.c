/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:36:24 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 09:33:58 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"

-------------------------------*/

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	// Boucle qui parcourt chaque bit du plus fort au moins fort
	int	i = 7;
	while (i >= 0)
	{
		// Decalage vers la droite et extraction du bit a la position i de l'octet
		// Si le bit est egal a 1, afficher 1
		if ((octet >> i) & 1)
			write(1, "1", 1);
		// Ou si le bit est egal a 0, afficher 0
		else
			write(1, "0", 1);
		// Passer au bit moins fort
		i--;
	}
}

#include <unistd.h>

void	print_bits(unsigned char octet);

int	main(void)
{
	print_bits(2);
	return (0);
}
