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

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
    // compteur pour la boucle while
	int	i;
    // le nombre à factoriser
	int	number;  

	// Vérifier s'il y a un seul argument passé en ligne de commande
	if (ac == 2)
	{
		i = 1;
        // convertir la chaîne de caractères en entier
		number = atoi(av[1]);  

		// Si le nombre est égal à 1, la seule factorisation possible est 1
		if (number == 1)
			printf("1");

		// Tant que le nombre est supérieur ou égal à i
		while (number >= ++i)
		{
			// Si i est un facteur de number
			if (number % i == 0)
			{
                // afficher le facteur i
				printf("%d", i);  

				// Si number est égal à i, cela signifie que tous les facteurs ont été trouvés
				if (number == i)
					break ;

                // afficher l'opérateur de multiplication
				printf("*");
                // diviser number par i
				number /= i;
                // réinitialiser le compteur i
				i = 1;            
			}
		}
	}
    // afficher un retour à la ligne
	printf("\n");   
	return (0);
}

