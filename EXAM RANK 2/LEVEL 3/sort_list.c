/*Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions: 
--------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.

Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list 
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}

---------------------------------
list.h

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

---------------------------------*/
#include "list.h"

// Cette fonction échange les valeurs des données de deux nœuds de la liste.
// Elle prend en entrée deux pointeurs vers des nœuds de la liste.
void	swap_values(t_list *a, t_list *b)
{
	int	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

// Cette fonction trie une liste chaînée en utilisant l'algorithme de tri à bulles.
t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	// Variable booléenne indiquant si des échanges ont eu lieu lors de la dernière itération.
	int	swapped;
	// Pointeur vers le nœud courant lors du parcours de la liste.
	t_list	*current; 

	// On effectue l'algorithme de tri à bulles jusqu'à ce qu'il n'y ait plus d'échanges à effectuer.
	while (swapped == 1)
	{
		// On initialise swapped à 0 avant chaque itération.
		swapped = 0;
		// On initialise cur au premier nœud de la liste.
		current = lst; 

		// On parcourt la liste jusqu'à l'avant-dernier nœud, en comparant chaque nœud avec son successeur.
		// Si les données des deux nœuds sont dans le mauvais ordre, on échange leurs valeurs.
		while (current && current->next)
		{
			if (cmp(cur->data, cur->next->data) == 0)
			{
				swap_values(cur, cur->next);
				swapped = 1;
			}
			cur = cur->next;
		}
	}
	// On retourne un pointeur vers le premier nœud de la liste triée.
	return (lst); 
}

/*------------------------------

//#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void	swap_values(t_list *a, t_list *b);
t_list	*sort_list(t_list *lst, int (*cmp)(int, int));

int ascending(int a, int b)
{
	return (a <= b);
}

int	main(void)
{
	t_list *c = malloc(sizeof(t_list));
	c->next = 0;
	c->data = 45;

	t_list *b = malloc(sizeof(t_list));
	b->next = c;
	b->data = 73;

	t_list *a = malloc(sizeof(t_list));
	a->next = b;
	a->data = 108;

	t_list *cur = a;
	while (cur)
	{
		printf("%d", cur->data);
		if (cur->next != 0)
			printf(", ");
		cur = cur->next;
	}
	printf("\n");

	cur = sort_list(a, ascending);

	// cur = a;
	while (cur)
	{
		printf("%d", cur->data);
		if (cur->next != 0)
			printf(", ");
		cur = cur->next;
	}
	printf("\n");
}

---------------------------------*/
