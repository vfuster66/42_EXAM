/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:07:04 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 17:58:50 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_power_of_2(unsigned int n)
{

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