 #include <stdlib.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	sign = 1;
	int	result = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		str++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		str++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * str_base + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			result = result * str_base + str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			result = result * str_base + str[i] - 'A' + 10;
		else
			break ;
		str++;
	}
	return (result * sign);
}
