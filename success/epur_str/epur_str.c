#include <unistd.h>

int main(int ac, char const **av)
{
	int i = 0;
	int etat_des_espaces = 0;

	if (ac == 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
				etat_des_espaces = 1;
			if (av[1][i] != ' ' && av[1][i] != '\t')
			{
				if (etat_des_espaces)
					write(1, " ", 1);
				etat_des_espaces = 0;
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
