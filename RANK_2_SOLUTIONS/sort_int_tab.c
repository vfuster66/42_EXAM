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
// Version 1
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
	unsigned int i = 0;
	// Compteur pour suivre le nombre d'itérations (passages) effectués
	unsigned int compteur_passages = 0; 

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
			ft_swap(&tab[i], &tab[i + 1]);
		}
		// Passage à l'élément suivant dans le tableau
		i++; 
        }
	// Passage au prochain itération (passage)
        compteur_passages++; 
    }
}

// Version 2
void sort_int_tab(int *tab, unsigned int size)
{
	// Indice pour parcourir le tableau
	unsigned int i = 0;
	// Variable temporaire pour effectuer l'échange
	int temp;                

	// Boucle principale pour contrôler les itérations à travers le tableau
	while (i < (size - 1))
	{
		// Si l'élément actuel est plus grand que l'élément suivant, on les échange
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];         
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			// Réinitialisation de l'indice de parcours pour vérifier à nouveau depuis le début
			i = -1; 
		}

		// Passage à l'élément suivant dans le tableau
		i++; 
	}
}

/*--------------------------------------------
#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size);

int main() 
{
    int arr[] = {4, 2, 7, 1, 9, 3};
    unsigned int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Avant le tri : ");
    for (unsigned int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    sort_int_tab(arr, arr_size);
    printf("Après le tri : ");
    for (unsigned int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
--------------------------------------------*/
