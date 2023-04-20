/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
-----------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);

------------------------------*/

#include <stdlib.h>

char	*ft_itoa(int n)
{
    char	*str;
    int	len;
    int	sign;
    int	temp;

    if (n == 0)
        return ("0");
    len = 0;
    sign = 0;
    if (n < 0)
    {
        sign = 1;
        n = -n;
    }
    temp = n;
    while (temp > 0)
    {
        temp /= 10;
        len++;
    }
    if (sign)
        len++;
    str = (char *)malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    while (len > 0)
    {
        len--;
        str[len] = (n % 10) + '0';
        n /= 10;
    }
    if (sign)
        str[0] = '-';
    return (str);
}

/*---------------------------------------

 #include <stdio.h>
 #include <limits.h>

 int		main(void)
 {
 	int d = INT_MIN;
 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = -13;
 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = 0;
 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = 5;
 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = INT_MAX;
 	printf("%d =? %s\n", d, ft_itoa(d));
 }
 
 ----------------------------------------*/
 
