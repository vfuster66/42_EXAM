/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:43:40 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 09:56:22 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int	i = 0;
	int	reversed = 0;
	
	while (i < 8)
	{
		reversed = (reversed << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
	return (reversed);
}

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet);

int	main(void)
{
	unsigned char	octet = 0x41;
	unsigned char	reversed;

	reversed = reverse_bits(octet);
	printf("Octet original : 0x%x\n", octet);
	printf("Octet inverse : 0x%x\n", reversed);
	return (0);
}
