/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:40:05 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/19 13:05:30 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strcpy(char *s1, char *s2)
{

}

#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2);

int main()
{
    char src[] = "Hello World!";
    char dest[20];

    printf("Source : %s\n", src);
    ft_strcpy(dest, src);
    printf("Destination : %s\n", dest);
    return (0);
}
