/*Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.

--------------------------*/

#include <stdlib.h>

// fonction pour trouver le maximum dans un tableau
int max(int *tab, unsigned int len)
{
    int result;
    
    // si la longueur est nulle, il n'y a pas de maximum
    if (!len)
        return (0);
    // initialisation du maximum à la première valeur du tableau
    result = *tab; 
    unsigned int i;
    
    // on commence à parcourir le tableau à partir de l'indice 1
    i = 1; 
    while (i < len)
    {
        // si la valeur courante est supérieure au maximum actuel
        if (result < *(tab + i))
            // on met à jour le maximum
            result = *(tab + i); 
        i++;
    }
    // on retourne le maximum trouvé
    return (result); 
}

/*--------------------------------

#include <stdlib.h>
#include <stdio.h>

int max(int *tab, unsigned int len);

int main(void)
{
    int tab1[] = {1, 2, 3, 4, 5};
    int tab2[] = {-1, -2, -3, -4, -5};
    int tab3[] = {0, 0, 0, 0, 0};
    int tab4[] = {5};
    int tab5[] = {0, -5, 7, 10, -2, 3};
    int tab6[] = {};

    printf("Max of tab1: %d\n", max(tab1, sizeof(tab1)/sizeof(int)));
    printf("Max of tab2: %d\n", max(tab2, sizeof(tab2)/sizeof(int)));
    printf("Max of tab3: %d\n", max(tab3, sizeof(tab3)/sizeof(int)));
    printf("Max of tab4: %d\n", max(tab4, sizeof(tab4)/sizeof(int)));
    printf("Max of tab5: %d\n", max(tab5, sizeof(tab5)/sizeof(int)));
    printf("Max of tab6: %d\n", max(tab6, sizeof(tab6)/sizeof(int)));

    return (0);
}

-------------------------------------*/
