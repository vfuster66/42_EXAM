/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:52:05 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/20 15:14:24 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int ft_atoi(const char *str) 
{
    int sign;
    int result;
    int i;

    sign = 1;
    result = 0;
    i = 0;
    if (str[0] == '-')
    {
        sign = -1;
        i = 1;
    }
    while (str[i] != '\0')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return sign * result;
}

void    ft_putnbr(int n)
{
    char    c;
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10) 
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
    {
        c = n + '0';
        write(1, &c, 1);
    }
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        write(1, "\n", 1);
        return 0;
    }
    int op1 = ft_atoi(argv[1]);
    int op2 = ft_atoi(argv[3]);
    char op = argv[2][0];
    int result;
    if (op == '+')
    {
        result = op1 + op2;
    }
    else if (op == '-')
    {
        result = op1 - op2;
    }
    else if (op == '*')
    {
        result = op1 * op2;
    }
    else if (op == '/')
    {
        result = op1 / op2;
    }
    else if (op == '%')
    {
        result = op1 % op2;
    }
    else
    {
        write(1, "\n", 1);
        return 0;
        }
        ft_putnbr(result);
        write(1, "\n", 1);
        return 0;
}
