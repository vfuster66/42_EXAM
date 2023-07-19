/*Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
-------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);

--------------------------------------------*/

int	is_power_of_2(unsigned int n)
{
	// Si n est 0, il n'est pas une puissance de 2
	if (!n)
		return (0);

	// Tant que n est plus grand que 1, on teste s'il est divisible par 2.
	//Si oui, on divise n par 2. Sinon, on retourne 0 car n n'est pas une puissance de 2.
	while (n > 1)
	{
		// Si n est divisible par 2
		if (n % 2 == 0)
			// On divise n par 2
			n /= 2; 
		// Sinon, n n'est pas une puissance de 2
		else 
			return (0);
	}
	// Si on arrive ici, n est une puissance de 2
	return (1); 
}

/*-----------------------------------------

#include <stdio.h>

int is_power_of_2(unsigned int n);

int main(void)
{
    unsigned int n;
    printf("Entrez un entier positif : ");
    scanf("%u", &n);
    if (is_power_of_2(n))
        printf("%u est une puissance de 2.\n", n);
    else
        printf("%u n'est pas une puissance de 2.\n", n);
    return 0;
}

------------------------------------------*/
