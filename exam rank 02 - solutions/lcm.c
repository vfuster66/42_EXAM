/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 08:42:46 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 08:46:31 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;
	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}

#include <stdio.h>

unsigned int lcm(unsigned int a, unsigned int b);

int main(void)
{
	unsigned int a, b;
	unsigned int result;

	// Test case 1
	a = 12;
	b = 18;
	result = lcm(a, b);
	printf("LCM of %u and %u is %u\n", a, b, result);

	// Test case 2
	a = 7;
	b = 13;
	result = lcm(a, b);
	printf("LCM of %u and %u is %u\n", a, b, result);

	// Test case 3
	a = 0;
	b = 5;
	result = lcm(a, b);
	printf("LCM of %u and %u is %u\n", a, b, result);

	// Test case 4
	a = 16;
	b = 0;
	result = lcm(a, b);
	printf("LCM of %u and %u is %u\n", a, b, result);

	return (0);
}