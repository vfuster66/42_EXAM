#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}


int	ft_atoi(char *str)
{
	int	i = 0;
	int	result = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i] - '0';
			i++;
		}
		else
			return (0);
	}
	return (result);
}

int	main(int ac, char **av)
{
	int	nb1;
	int	nb2;

	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		nb1 = 1;
		nb2 = ft_atoi(av[1]);
		if (nb2 == 0)
			return (0);
		else
		{
			while (nb1 <= 9)
			{
				ft_putnbr(nb1);
				write(1, " x ", 3);
				ft_putnbr(nb2);
				write(1, " = ", 3);
				ft_putnbr(nb1 * nb2);
				write(1, "\n", 1);
				nb1++;
			}
		}
	}
	return (0);
}
