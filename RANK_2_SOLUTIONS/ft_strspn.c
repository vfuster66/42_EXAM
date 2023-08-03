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
    size_t  i = 0;
    size_t  j;

    while (s[i])
    {
        j = 0;
        while (accept[j])
        {
            if (s[i] == accept[j])
                break ;
            j++;
        }
        if (accept[j] == '\0')
            return (i);
        i++;
    }
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
