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

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	unsigned int	j;
	int	temp;

	// Verifier si le tableau est vide ou qu'il ne comporte qu'un argument
	// Le tableau est deja trie
	if (size <= 1)
		return ;
	// Boucle externe qui parcourt le tableau jusqu'a la fin
	// Controle le nombre d'iteration pour trier le tableau
	while (i < size - 1)
	{
		j = 0;
		// Boucle interne utilisee pour comparer chaque element avec son voisin
		// et l'intervertir si necessaire
		while (j < size - i - 1)
		{
			// Comparaison entre l'element actuel et le suivant et swap des 
			// elements si necessaire
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			// Passer a la comparaison suivante
			j++;
		}
		i++;
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
