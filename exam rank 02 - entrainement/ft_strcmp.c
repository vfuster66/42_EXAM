/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:48:55 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 18:35:13 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

#include <stdio.h>
#include <string.h>

int ft_strcmp(const char *s1, const char *s2);

int main(void)
{
    char str1[] = "hello";
    char str2[] = "world";

    int result = ft_strcmp(str1, str2);

    if (result == 0)
        printf("Les chaînes sont identiques\n");
    else if (result < 0)
        printf("La chaîne \"%s\" est avant la chaîne \"%s\" dans l'ordre alphabétique\n", str1, str2);
    else
        printf("La chaîne \"%s\" est après la chaîne \"%s\" dans l'ordre alphabétique\n", str1, str2);

    return 0;
}
