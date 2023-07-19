/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:58:46 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 17:56:19 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi_base(const char *str, int str_base)
{

}

#include <stdio.h>
#include <stdlib.h>

int ft_atoi_base(const char *str, int str_base);

int main()
{
	printf("%d\n", ft_atoi_base("1010", 2)); // attendu : 10
	printf("%d\n", ft_atoi_base("a", 16)); // attendu : 10
	printf("%d\n", ft_atoi_base("-1010", 2)); // attendu : -10
	printf("%d\n", ft_atoi_base("z123", 16)); // attendu : 0
	printf("%d\n", ft_atoi_base("1010", 1)); // attendu : 0
	return 0;
}