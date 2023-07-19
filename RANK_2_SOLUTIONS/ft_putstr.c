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
