/*Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions: 
--------------------------

Write a function that swaps the contents
of two integers the adresses of which are 
passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);

-----------------------*/

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*-----------------------------


#include <unistd.h>
#include <stdio.h>
void    ft_swap(int *a, int *b);


int	main(void)
{
	int	*a;
	int	*b;
	int	n1;
	int	n2;

	n1 = 9;
	n2 = 6;
	a = &n1;
	b = &n2;
	printf("Value of n1 is: %u and the value of n2 is: %u.", *a, *b);
	ft_swap(a, b);
	printf("\n");
	printf("Now the value of n1 is: %u and the value of n2 is: %u.", *a, *b);
	printf("\n");
}

-----------------------*/
