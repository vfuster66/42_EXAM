/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:04:39 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 18:07:52 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.

--------------------------------------*/

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void sort_int_tab(int *tab, unsigned int size)
{
	// Indice pour parcourir le tableau
	int i;
	// Compteur pour suivre le nombre d'itérations (passages) effectués
	int compteur_passages; 

	i = 0;
	compteur_passages = 0;

	// Si le tableau est vide ou contient un seul élément, il est déjà trié, donc on retourne
	if (size <= 1)
		return;

	// Boucle principale pour contrôler les itérations (passages) à travers le tableau
	while (compteur_passages < size)
	{
		// Réinitialisation de l'indice de parcours pour chaque passage
		i = 0;
		
		// Boucle interne pour comparer et échanger les éléments adjacents
		while (i < (size - 1))
		{
		// Si l'élément actuel est plus grand que l'élément suivant, on les échange
		if (tab[i] > tab[i + 1])
		{
			// La fonction ft_swap est utilisée pour échanger les éléments en mémoire
			ft_swap(&tab[idx], &tab[idx + 1]);
		}
		// Passage à l'élément suivant dans le tableau
		i++; 
        }
	// Passage au prochain itération (passage)
        compteur_passages++; 
    }
}


/*--------------------------------------------
#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size);

int main()
{
    int tab[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    unsigned int size = sizeof(tab) / sizeof(tab[0]);

    sort_int_tab(tab, size);

    for (unsigned int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}
--------------------------------------------*/
