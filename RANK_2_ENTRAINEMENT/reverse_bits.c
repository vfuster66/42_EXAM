/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:43:40 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 18:00:01 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{

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
