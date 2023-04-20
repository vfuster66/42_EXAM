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

int main(int ac, char **av)
{
    int n;
    int i;
    
    // Vérifier que le programme a reçu exactement 2 arguments : le nom du programme et un entier
    if (ac != 2)
    {
        // Si le nombre d'arguments est incorrect, afficher une ligne vide et terminer le programme
        printf("\n"); 
        return 0;
    }
    // Convertir l'argument en entier
    n = atoi(av[1]);
    // Si l'argument est 1, afficher 1 et terminer le programme
    if (n == 1)
    {
        printf("1\n");
        return 0;
    }
    i = 2; 
    // Boucler tant que i est inférieur ou égal à n
    while (i <= n)
    {
        // Si n est divisible par i
        if (n % i == 0)
        {
            // Afficher i
            printf("%d", i);
            // Diviser n par i
            n /= i;
            // Si n est plus grand que 1, afficher une étoile
            if (n > 1)                
                printf("*");
            // Réinitialiser i à 1
            i = 1; 
        }
        // Passer au prochain i
        i++; 
    }
    // Afficher une ligne vide à la fin de la boucle
    printf("\n"); 
    return 0;
}
