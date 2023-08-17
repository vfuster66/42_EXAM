#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int	i = 0;
	char	*str;
	int	temp = nbr;

	if (nbr == -2147483648)
		return ("-2147483648");
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (nbr == 0)
		return ("0");
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
		str[0] = '-';
	}
	while (temp)
	{
		temp /= 10;
		i++;
	}
	while (nbr)
	{
		str[--i] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
