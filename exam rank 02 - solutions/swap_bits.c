/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:31:18 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 10:13:14 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned char	swap_bits(unsigned char octet);

int main(void)
{
	unsigned char octet = 0x41;
	unsigned char swapped_octet = swap_bits(octet);

	printf("Octet original : 0x%02x\n", octet);
	printf("Octet échangé  : 0x%02x\n", swapped_octet);

	return (0);
}
