/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:42:16 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/11 09:14:43 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions: 
--------------------------

Write a function that swaps the contents
of two integers the adresses of which are 
passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);

-----------------------*/

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


#include <unistd.h>
#include <stdio.h>
void    ft_swap(int *a, int *b);


int	main(void)
{
	int	x = 5;
	int	y = 10;

	printf("Avant swap: x = %d, y = %d\n", x, y);
	ft_swap(&x, &y);
	printf("Apres swap: x = %d, y = %d\n", x, y);
	return (0);
}
