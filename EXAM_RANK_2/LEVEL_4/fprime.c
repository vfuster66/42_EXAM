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

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	// Variable pour stocker le nombre saisi en argument
    	int nombre;
	// Variable pour stocker le diviseur actuel
    	int diviseur;

	// Vérifie qu'un seul argument a été fourni lors de l'exécution du programme
	if (ac == 2)        
    	{
		// Convertit l'argument en entier et le stocke dans la variable 'nombre'
        	nombre = atoi(av[1]);
		// Initialise le diviseur à 2, car tout nombre est divisible par 1
        	diviseur = 2;
		// Continue tant que le nombre n'a pas été complètement décomposé en facteurs premiers
		while (nombre != 1)
        	{
			// Vérifie si 'nombre' est divisible par 'diviseur' sans laisser de reste
            		if (nombre % diviseur == 0) 
            		{
				// Affiche le diviseur, qui est un facteur premier du nombre
                		printf("%d", diviseur);
				// Divise 'nombre' par le diviseur pour obtenir le nombre réduit
                		nombre /= diviseur;
				// Vérifie si le nombre réduit est différent de 1 (il y a encore des facteurs premiers à trouver)
				if (nombre != 1)
					// Affiche un astérisque pour indiquer la multiplication des facteurs premiers
					printf("*");        
            		}
            		else
				// Si 'nombre' n'est pas divisible par 'diviseur', incrémente 'diviseur' pour essayer avec le prochain nombre
                		diviseur++;     
        	}
    	}
	// Affiche une nouvelle ligne à la fin pour une meilleure mise en forme
	printf("\n");
	// Indique que le programme s'est exécuté avec succès
    	return 0;       
}


