#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	tab[256];

	if (i < 256)
	{
		tab[i] = 0;
		i++;
	}
	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			if (tab[(unsigned char)av[1][i]] == 0)
			{
				tab[(unsigned char)av[1][i]] = 1;
				write(1, &av[1][i], 1);
			}
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			if (tab[(unsigned char)av[2][i]] == 0)
			{
				tab[(unsigned char)av[2][i]] = 1;
				write(1, &av[2][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
