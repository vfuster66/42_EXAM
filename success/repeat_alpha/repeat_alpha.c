#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	multiplicateur;
	int	compteur;

	if (ac == 2)
	{
		while (av[1][i])
		{
			multiplicateur = 1;
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				multiplicateur = av[1][i] - 96;
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				multiplicateur = av[1][i] - 64;
			compteur = 0;
			while (compteur < multiplicateur)
			{
				write(1, &av[1][i], 1);
				compteur++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
