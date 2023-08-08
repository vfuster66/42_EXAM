/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:50:25 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/11 15:15:25 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);

---------------------------------------------*/

#include <stdlib.h>

char    *ft_strdup(char *src)
{
    // Chaine de caracteres
    char    *dest;
    // Index pour parcourir la chaine
    int i = 0;

    // Boucle pour parcourir la chaine de caracteres jusqu'a la fin
    while (src[i])
            i++;
    // Allouer de la memoire dynamiquement pour la chaine de caracteres dest
    dest = malloc(sizeof(char) * (i + 1));
    if (!dest)
        return (NULL);
    // Reinitialiser i pour parcourir a nouveau la chaine
    i = 0;
    // Boucle pour parcourir la chaine de caracteres
    while (src[i])
    {
        // Copier l'index de src dans dest
        dest[i] = src[i];
        // Passer au caractere suivant
        i++;
    }
    // Ajouter le caractere nul de fin de chaine de caracteres
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
