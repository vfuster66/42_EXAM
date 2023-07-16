/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:13:21 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 17:56:39 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

char    *ft_itoa(int nbr)
{

}



int      main(void)
{
	int d = INT_MIN;
	printf("%d = %s\n", d, ft_itoa(d));
	d = -13;
	printf("%d = %s\n", d, ft_itoa(d));
	d = 0;
	printf("%d = %s\n", d, ft_itoa(d));
	d = 5;
	printf("%d = %s\n", d, ft_itoa(d));
	d = INT_MAX;
	printf("%d = %s\n", d, ft_itoa(d));
}
