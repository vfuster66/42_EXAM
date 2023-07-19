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

// Cette fonction trie un tableau d'entiers en ordre croissant en utilisant l'algorithme de tri à bulles.
// Elle prend en entrée un pointeur vers le tableau et sa taille.
void	sort_int_tab(int *tab, unsigned int size)
{
	// Initialise un compteur i à 0 pour parcourir le tableau.
	unsigned int i;
	// Initialise un compteur j pour parcourir le tableau lors du tri.
	unsigned int j;
	// Variable temporaire utilisée pour effectuer les échanges.
	int temp;
	
	// Si la taille du tableau est inférieure ou égale à 1, il est déjà trié et la fonction se termine.
	if (size <= 1)
		return;
	// Sinon, on effectue l'algorithme de tri à bulles en parcourant le tableau plusieurs fois.
	i = 0;
	while (i < size - 1) 
	{
		j = 0;
		// On parcourt le tableau jusqu'à la fin, en comparant chaque élément avec son voisin.
		// Si l'élément actuel est plus grand que son voisin, on échange leurs positions.
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/*----------------------------------

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

--------------------------------------*/
