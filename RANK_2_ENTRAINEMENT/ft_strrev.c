/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:19:22 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/19 13:05:46 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strrev(char *str)
{

}

#include <stdio.h>
#include <stdlib.h>

char	*ft_strrev(char *str);

int	main()
{
	char str[] = "Hello World";
	printf("Original string: %s\n", str);
	ft_strrev(str);
	printf("Reversed string: %s\n", str);
	return (0);
}
