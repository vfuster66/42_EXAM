/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:07:04 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 09:09:05 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
-------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);

--------------------------------------------*/

int is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n > 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			return (0);
	}
	return (1);
}

#include <stdio.h>

int is_power_of_2(unsigned int n);

int main(void)
{
	unsigned int n;
	printf("Entrez un entier positif : ");
	scanf("%u", &n);
	if (is_power_of_2(n))
        	printf("%u est une puissance de 2.\n", n);
	else
        	printf("%u n'est pas une puissance de 2.\n", n);
	return 0;
}
