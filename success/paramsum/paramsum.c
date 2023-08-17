#include <unistd.h>

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
	(void)av;
	ft_putnbr(ac - 1);
	write(1, "\n", 1);
	return (0);
}
