#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i = 0;
	int	result = 0;
	int	sign = 1;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		str++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		str++;
	}
	return (result * sign);
}
