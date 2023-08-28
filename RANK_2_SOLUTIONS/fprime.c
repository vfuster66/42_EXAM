/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:48:14 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 13:33:52 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Écrire un programme qui prend en paramètre un entier strictement positif, et
qui affiche sa décomposition en facteurs premiers sur la sortie standard,
suivie d'un '\n'.

Les facteurs doivent être affichés dans l'ordre croissant et séparés par des
'*', de telle sorte que l'expression affichée donne le bon résultat.

Si le nombre de paramètres est différent de 1, le programme doit afficher '\n'.

L'entrée, quand elle est passée, sera toujours un nombre valide sans caractères
parasites.

Exemple:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$

-------------------------*/
// Programme qui prend un entier en argument et affiche sa decomposition
// en facteurs premiers
// Un facteur premier est un nombre qui divise exactement le nombre donne
// sans laisser de reste

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	// Verifier le nombre exact d'arguments
	if (ac == 2)
	{
		// Affecter l'argument converti en entier a nombre
		int	nombre = atoi(av[1]);
		// Variable utilisee pour parcourir les diviseurs potentiels du nombre donne
		// intitialise a 2 qui est le plus petit nombre premier
		int	diviseur = 2;
		
		// Si nombre est plus petit ou egal a 0 , il n'a pas de decomposition en
		// facteurs premiers
		if (nombre <= 0)
		{
			printf("\n");
			return (0);
		}
		if (nombre == 1)
		{
			printf("1\n");
			return (0);
		}
		// Boucle tant que le nombre n'est pas egal a 1
		while (nombre != 1)
		{
			Si le nombre est divisible par le diviseur = facteur premier de nombre
			if (nombre % diviseur == 0)
			{
				// Afficher le diviseur qui est un facteur premier
				printf("%d", diviseur);
				// Mise a jour de nombre en le divisant par diviseur
				nombre /= diviseur;
				// Si le nombre n'est pas egal a 1, afficher '*'
				if (nombre != 1)
					printf("*");
			}
			// Ou passer au diviseur suivant 
			else
				diviseur++;
		}
	}
	printf("\n");
	return (0);
}
