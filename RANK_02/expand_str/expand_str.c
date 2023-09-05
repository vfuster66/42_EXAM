#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	etat_des_espaces = -1;

	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] != ' ' && av[1][i] != '\t')
			{
				if (etat_des_espaces == 1)
					write(1, "   ", 3);
				etat_des_espaces = 0;
				write(1, &av[1][i], 1);
			}
			else if (etat_des_espaces == 0)
				etat_des_espaces = 1;
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
