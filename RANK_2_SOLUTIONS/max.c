/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:54:24 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 09:30:02 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	max(int* tab, unsigned int len)
{
    // Verifier si le tableau est vide
    if (len == 0)
        return (0);
    // Assigner la 1ere valeur du tableau a la valeur_max
    int    valeur_max = tab[0];
    // Initialiser i a la deuxieme valeur du tableau
    unsigned int    i = 1;
    // Boucle qui parcourt tous les elements du tableau
    while (i < len)
    {
        // Comparaison de la valeur_max avec la valeur actuelle du tableau
        if (valeur_max < tab[i])
            // Mise a jour de valeur_max chaque fois qu'une valeur plus grande est trouvee
            valeur_max = tab[i];
        // Passer a l'element suivant
        i++;
    }
    return (valeur_max);
}

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
