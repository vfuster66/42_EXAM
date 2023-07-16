/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:59:01 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 18:31:09 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		if (av[2][0] == '+')
			printf("%d", atoi(av[1]) + atoi(av[3]));
		if (av[2][0] == '-')
			printf("%d", atoi(av[1]) - atoi(av[3]));
		if (av[2][0] == '*')
			printf("%d", atoi(av[1]) * atoi(av[3]));
		if (av[2][0] == '/')
			printf("%d", atoi(av[1]) / atoi(av[3]));
		if (av[2][0] == '%')
			printf("%d", atoi(av[1]) % atoi(av[3]));
	}
	write(1, "\n", 1);;
	return (0);
}
