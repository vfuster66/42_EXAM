/*Assignment name  : do_op
Expected files   : do_op.c
Allowed functions: atoi, printf, write
--------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$

-----------------------------------*/

#include <stdlib.h>
#include <unistd.h>

int ft_atoi(const char *str)
{
    int sign = 1;
    int result = 0;
    int i = 0;

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

void	ft_putnbr(int n) 
{
    char c;
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}

int main(int ac, char **av) 
{
    if (ac != 4) 
    {
        write(1, "\n", 1);
        return 0;
    }
    int op1 = ft_atoi(av[1]);
    int op2 = ft_atoi(av[3]);
    char op = av[2][0];
    int result;
    if (op == '+')
        result = op1 + op2;
    else if (op == '-')
        result = op1 - op2;
    else if (op == '*') 
        result = op1 * op2;
    else if (op == '/')
        result = op1 / op2;
    else if (op == '%') 
        result = op1 % op2;
    else
    {
        write(1, "\n", 1);
        return 0;
    }
    ft_putnbr(result);
    write(1, "\n", 1);
    return 0;
}


