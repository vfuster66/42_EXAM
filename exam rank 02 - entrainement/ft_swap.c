/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:42:16 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 18:09:35 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
