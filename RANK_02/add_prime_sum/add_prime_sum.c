#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i = 0;
	int	result = 0;

	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int	is_prime(int nombre)
{
	int	diviseur = 2;

	if (nombre <= 1)
		return (0);
	while (diviseur * diviseur <= nombre)
	{
		if (nombre % diviseur == 0)
			return (0);
		else
			diviseur++;
	}
	return (1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	somme_des_premiers = 0;
	int	nombre_actuel = 2;

	if (ac == 2)
	{
		while (nombre_actuel <= ft_atoi(av[1]))
		{
			if (is_prime(nombre_actuel))
				somme_des_premiers += nombre_actuel;
			nombre_actuel++;
		}
	}
	ft_putnbr(somme_des_premiers);
	write(1, "\n", 1);
	return (0);
}
