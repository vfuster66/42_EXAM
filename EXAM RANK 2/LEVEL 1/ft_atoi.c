/*Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
---------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);

------------------------------*/

int	ft_atoi(char const *nptr)
{
	int		i;
	long	number;
	long	sign;

	i = 0;
	sign = 1;
	number = 0;
	while (nptr[i] == ' ' || ((9 <= nptr[i]) && (nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + nptr[i] - '0';
		i++;
	}
	return (number * sign);
}

/*---------------------

#include <stdio.h>
#include <stdlib.h>

int ft_atoi(const char *str);

int	main()
{	char str1[] = "123";
	char str2[] = "-456";
	char str3[] = "0";
	char str4[] = "999999999";
	char str5[] = "-2147483648";
	char str6[] = "2147483647";
	
	printf("'%s' converti en int : %d\n", str1, ft_atoi(str1));
	printf("'%s' converti en int : %d\n", str2, ft_atoi(str2));
	printf("'%s' converti en int : %d\n", str3, ft_atoi(str3));
	printf("'%s' converti en int : %d\n", str4, ft_atoi(str4));
	printf("'%s' converti en int : %d\n", str5, ft_atoi(str5));
	printf("'%s' converti en int : %d\n", str6, ft_atoi(str6));
	return 0;
}

-------------------------*/
