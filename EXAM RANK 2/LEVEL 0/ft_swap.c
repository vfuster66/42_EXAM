Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions: 
---------------------------------------------------------

Write a function that swaps the contents of two integers
the adresses of which are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);

---------------------------------------------------------

#include <unistd.h>
#include <stdio.h>

void    ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

---------------------------------------------------------

void ft_swap(int *a, int *b);

int main() {
  int x = 10;
  int y = 20;

  printf("Avant l'appel de ft_swap:\n");
  printf("x = %d, y = %d\n", x, y);

  ft_swap(&x, &y);

  printf("Après l'appel de ft_swap:\n");
  printf("x = %d, y = %d\n", x, y);

  return 0;
}
