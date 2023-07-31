/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:25:45 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 17:57:38 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{

}

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end);

int	main(void)
{
	int	*range;
	int	i;

	range = ft_range(1, 3);
	i = 0;
	while (i < 3)
	{
		printf("%d ", range[i]);
		i++;
	}
	printf("\n");
	free(range);

	range = ft_range(-1, 2);
	i = 0;
	while (i < 4)
	{
		printf("%d ", range[i]);
		i++;
	}
	printf("\n");
	free(range);

	range = ft_range(0, 0);
	printf("%d\n", range[0]);
	free(range);

	range = ft_range(0, -3);
	i = 0;
	while (i < 4)
	{
		printf("%d ", range[i]);
		i++;
	}
	printf("\n");
	free(range);

	return (0);
}