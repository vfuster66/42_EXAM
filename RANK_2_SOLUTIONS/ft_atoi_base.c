/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:58:46 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 19:06:53 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
---------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);

--------------------------------*/

int ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	result = 0;
	int	sign = 1;

	// Verifier si str_base est compris entre la base binaire et la base hexadecimale
	if (str_base >= 2 && str_base <= 16)
	{
		// Si le 1er caractere de la chaine est le caractere '-'
		if (str[0] == '-')
		{
			// variable mise a jour indiquant que l'entier sera negatif 
			sign = -1;
			// Passer au caractere suivant
			i++;
		}
		// Boucle pour parcourir la chaine de caracteres jusqu'a la fin
		while (str[i])
		{
			// Verifier pour chaque caractere en fonction de la base specifiee
			// Convertir le caractere en sa valeur numerique
			if (str[i] >= '0' && str[i] <= '9')
				result = result * str_base + str[i] - '0';
			else if (str[i] >= 'a' && str[i] <= 'f')
				result = result * str_base + str[i] - 'a' + 10;
			else if (str[i] >= 'A' && str[i] <= 'F')
				result = result * str_base + str[i] - 'A' + 10;
			// Ou caractere invalide rencontre qui met fin a la conversion
			else
				break ;
			i++;
		}
	}
	return (result * sign);
}

#include <stdio.h>
#include <stdlib.h>

int ft_atoi_base(const char *str, int str_base);

int main()
{
	printf("%d\n", ft_atoi_base("1010", 2)); // attendu : 10
	printf("%d\n", ft_atoi_base("a", 16)); // attendu : 10
	printf("%d\n", ft_atoi_base("-1010", 2)); // attendu : -10
	printf("%d\n", ft_atoi_base("z123", 16)); // attendu : 0
	printf("%d\n", ft_atoi_base("1010", 1)); // attendu : 0
	return 0;
}
