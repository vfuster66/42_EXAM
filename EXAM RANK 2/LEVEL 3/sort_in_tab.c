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
	unsigned int i = 0;
        unsigned int j;
	int	temp;

    	if (size <= 1)
	        return ;
	while (i < size - 1) 
	{
		j = 0;
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

c
Copy code
#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size);

int main() {
    int tab[] = {5, 2, 7, 3, 9, 1, 4, 6, 8};
    unsigned int size = sizeof(tab)/sizeof(int);

    printf("Tableau avant tri : ");
    unsigned int i = 0;
    while (i < size) {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");

    sort_int_tab(tab, size);

    printf("Tableau après tri : ");
    i = 0;
    while (i < size) {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");

    return 0;
}

--------------------------------------*/
