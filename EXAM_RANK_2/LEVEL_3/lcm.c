/*Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
---------------------------

Write a function who takes two unsigned int as parameters and returns the 
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and 
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)
  
  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
  
  ---------------------------*/
  
/* Cette fonction calcule le plus petit multiple commun (PPCM) de deux nombres
   entiers non signés passés en paramètre. */
unsigned int	lcm(unsigned int a, unsigned int b)
{
	// variable pour stocker le nombre en cours de test
	unsigned int	n;

	// si l'un des deux nombres est nul, le PPCM est zéro
	if (a == 0 || b == 0)
		return (0);
	// on choisit le plus grand nombre pour commencer à tester les multiples
	if (a > b)
		n = a;
	else
		n = b;

	// boucle infinie, on sortira de la fonction avec un return
	while (1)
	{
		// si n est divisible par a et b, alors n est le PPCM
		if (n % a == 0 && n % b == 0)
			return (n);
		// sinon, on teste le multiple suivant en incrémentant n
		++n;
	}
}

/*--------------------------------

#include <stdio.h>

unsigned int lcm(unsigned int a, unsigned int b);

int main(void)
{
    unsigned int a, b;
    unsigned int result;

    // Test case 1
    a = 12;
    b = 18;
    result = lcm(a, b);
    printf("LCM of %u and %u is %u\n", a, b, result);

    // Test case 2
    a = 7;
    b = 13;
    result = lcm(a, b);
    printf("LCM of %u and %u is %u\n", a, b, result);

    // Test case 3
    a = 0;
    b = 5;
    result = lcm(a, b);
    printf("LCM of %u and %u is %u\n", a, b, result);

    // Test case 4
    a = 16;
    b = 0;
    result = lcm(a, b);
    printf("LCM of %u and %u is %u\n", a, b, result);

    return (0);
}

------------------------------------*/

