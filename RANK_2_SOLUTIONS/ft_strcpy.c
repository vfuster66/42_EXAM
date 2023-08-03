/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:40:05 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/11 09:12:28 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
-------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);

-------------------------------*/

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
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
