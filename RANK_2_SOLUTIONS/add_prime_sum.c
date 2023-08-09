/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:06:14 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 11:16:27 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
-----------------------------------

Écrire un programme qui prend un entier positif en argument et affiche la somme
de tous les nombres premiers inférieurs ou égaux à ce paramètre, suivie d'un
\n.

Si le nombre d'arguments n'est pas 1, ou que l'argument n'est pas positif,
afficher 0 et un \n.

Oui, les exemples sont justes.

Exemples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

-----------------------------*/

#include <unistd.h>

// Fonction pour afficher un entier sur la sortie standard
void	ft_putnbr(int n)
{
	char	c;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

// Fonction pour convertir une chaine de caracteres en entier
int	ft_atoi(char *str)
{
	int	i = 0;
	int	result = 0;

	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

// Fonction pour verifier si un nombre donne est premier ou non
int	ft_is_prime(int nombre)
{
	int	diviseur = 2;
	
	//un nombre premier est obligatoirement superieur a 1
	if (nombre <= 1)
		return (0);
	while (diviseur * diviseur <= nombre)
	{
		if (nombre % diviseur == 0)
			return (0);
		diviseur++;
	}
	return (1);
}

// Fonction principale
int	main(int ac, char **av)
{
	int	nombre_actuel = 2;
	int	somme_des_premiers = 0;

	// Verifier le nombre exact d'arguments
	if (ac == 2)
	{
		// Boucle qui itere tant que le nombre_actuel est plus
		// petit ou egal a l'argument converti en entier
		while (nombre_actuel <= ft_atoi(av[1]))
		{
			// Verifier si le nombre_actuel est un nombre premier
			if (ft_is_prime(nombre_actuel))
				// Ajouter le nombre_actuel a la somme_des_premiers
				somme_des_premiers += nombre_actuel;
			// Passer au nombre_actuel suivant
			nombre_actuel++;
		}
	}
	// Afficher la somme des nombres premiers
	ft_putnbr(somme_des_premiers);
	write(1, "\n", 1);
	return (0);
}
