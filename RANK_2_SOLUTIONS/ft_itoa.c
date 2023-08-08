/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:13:21 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 14:17:17 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
-----------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);

------------------------------*/

#include <stdlib.h>

char    *ft_itoa(int nbr)
{
	// Index pour la construction de la chaine de caracteres
	int		i = 0;
	// Variable temporaire utilisee pour determiner le nombre de 
	// chiffres dans nbr
	long	temp = nbr;
	// Pointeur vers un caractere = tableau de caracteres pour stocker 
	// la chaine de caracteres
	char	*str;

	// INT_MIN  = Seul cas ou la conversion necessite un traitement special
	if (nbr == -2147483648)
		return ("-2147483648");
	// Allocation dynamique de la memoire pour le tableau de caracteres 
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	// Terminer correctement la chaine de caracteres creee a partir de l'entier converti
	str[i] ='\0';
	// Si le nombre est egal a 0, on revoie la chaine '0'
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	// Si le nombre est negatif
	if (nbr < 0)
	{
		// Passer au caractere suivant = ignorer le caractere '-'
		i++;
		// Rendre le nombre positif
		nbr *= -1;
		// le premier caractere de la chaine sera le caractere '-'
		str[0] = '-';
	}
	// Boucle pour calculer le nombre de chiffres dans nbr
	while (temp)
	{
		temp /= 10;
		i++;
	}
	// Boucle pour convertir  nbr en chaine de caracteres
	while (nbr)
	{
		str[--i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

/*-------------------------------------------
#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr);

int main(int ac, char **av)
{
	(void)ac;
    printf("%s\n", ft_itoa(atoi(av[1])));
    return (0);
}
-------------------------------------------*/
