/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:50:25 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 18:39:17 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int i = 0;
    char    *dest;

    while (src[i])
        i++;
    dest = malloc(sizeof(char) * i);
    if (!dest)
        return (NULL);
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *src);

int main(void)
{
    char *src = "Hello world!";
    char *dup = ft_strdup(src);

    if (dup == NULL)
    {
        printf("Erreur : échec de l'allocation mémoire.\n");
        return 1;
    }

    printf("La chaîne originale est : %s\n", src);
    printf("La chaîne dupliquée est : %s\n", dup);

    free(dup);
    return 0;
}
