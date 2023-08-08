/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:55:35 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 08:39:51 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);

--------------------------------------*/

#include <stdlib.h>

size_t  ft_strspn(const char *s, const char *accept)
{
    // Index pour parcourir la chaine de caracteres s
    size_t  i = 0;
    // Index pour parcourir la chaine de caracteres accept
    size_t  j;

    // Boucle pour parcourir la chaine s
    while (s[i])
    {
        j = 0;
        // Boucle pour parcourir la chaine accept
        while (accept[j])
        {
            // Si les deux caracteres sont egaux, s[i] fait partie de accept
            if (s[i] == accept[j])
                // Sortir de la boucle 
                break ;
            // Passer au caractere suivant de accept 
            j++;
        }
        // Si on arrive au bout de la chaine accept
        if (accept[j] == '\0')
            // Renvoyer la valeur de i
            return (i);
        // Passer au caractere suivant de s
        i++;
    }
    // Renvoyer la valeur de i
    return (i);
}

#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept);

int main(void)
{
    const char *s = "Hello, world!";
    const char *accept = "eloH wrd";

    size_t ft_result = ft_strspn(s, accept);
    size_t std_result = strspn(s, accept);

    printf("ft_strspn result: %zu\n", ft_result);
    printf("strspn result: %zu\n", std_result);

    if (ft_result == std_result)
        printf("Both functions returned the same result.\n");
    else
        printf("The results differ.\n");

    return 0;
}
