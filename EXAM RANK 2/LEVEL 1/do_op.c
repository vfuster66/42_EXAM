/*Assignment name  : do_op
Expected files   : do_op.c
Allowed functions: atoi, printf, write
--------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$

-----------------------------------*/

#include <unistd.h>

int	ft_atoi(char *str)
{
	// Initialisation de variables
	int	result;
	int	sign;
	int	i;
	
	i = 0;
	sign = 1;
	result = 0;
	// Gestion du signe éventuel
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	// Parcours de la chaîne de caractères
	while (str[i])
	{
		// Conversion de chaque chiffre en entier et construction du nombre
		result = result * 10 + str[i] - '0';
		i++;
	}
	// Retourne le nombre final avec le signe approprié
	return (result * sign);
}

void	ft_putnbr(int n)
{
	char	c;
	
	// Si l'entier est négatif, on affiche le signe '-' et on travaille avec la valeur absolue
	if (n < 0) 
	{
		write(1, "-", 1);
		n = -n;
	}
	// Si l'entier est supérieur à 9, on continue à récursivement afficher les chiffres
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	// Conversion du chiffre en caractère
	c = (n % 10) + '0';
	// Affichage du caractère
	write(1, &c, 1);
}

int	main(int ac, char **av) 
{
	// Vérification du nombre d'arguments
	if (ac != 4) 
	{
		write(1, "\n", 1);
		return 0;
    }
    // Conversion des deux opérandes en entiers et récupération de l'opérateur
	int nb1 = ft_atoi(av[1]);
	int nb2 = ft_atoi(av[3]);
	char op = av[2][0];
	int	result;
	
	// Calcul du résultat en fonction de l'opérateur
	if (op == '+')
		result = nb1 + nb2;
	else if (op == '-')
		result = nb1 - nb2;
	else if (op == '*') 
		result = nb1 * nb2;
	else if (op == '/') 
		result = nb1 / nb2;
	else if (op == '%') 
		result = nb1 % nb2;
	else
		result = 0;
	// Si le résultat n'est pas 0, on l'affiche
	if (result != 0) 
		ft_putnbr(result);
	// On affiche un retour à la ligne à la fin
	write(1, "\n", 1); 
	return 0;
}
