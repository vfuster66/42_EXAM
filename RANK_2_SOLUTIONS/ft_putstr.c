/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:38:55 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/11 09:10:38 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_putstr
Expected files   : ft_putstr.c
Allowed functions: write
-------------------------------

Write a function that displays a string on the standard output.

The pointer passed to the function contains the address of the string's first
character.

Your function must be declared as follows:

void	ft_putstr(char *str);

-------------------------------*/

#include <unistd.h>

void	ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

#include <unistd.h>

void ft_putstr(char *str);

int main()
{
    char str[] = "Hello, World!";
    ft_putstr(str);
    return 0;
}
