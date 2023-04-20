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

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	// Déclaration d'une variable temporaire pour stocker la valeur de a
	int	temp;
	// On stocke la valeur de a dans la variable temp
	temp = *a;
	// On affecte à a la valeur de b
	*a = *b;
	// On affecte à b la valeur stockée dans la variable temp
	*b = temp;
}

/*-----------------------------


#include <unistd.h>
#include <stdio.h>
void    ft_swap(int *a, int *b);


int	main(void)
{
	int	x = 5;
	int	y = 10;

	printf("Avant swap: x = %d, y = %d\n", x, y);
	ft_swap(&x, &y);
	printf("Apres swap: x = %d, y = %d\n", x, y);
	return (0);
}

-----------------------*/
