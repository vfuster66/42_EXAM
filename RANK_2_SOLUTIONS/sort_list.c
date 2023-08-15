/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:08:33 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 17:44:55 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

---------------------------------*/
//#include "list.h"
#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	// Variable temporaire pour echanger 2 noeuds
	int	temp;
	// Pointeur utilise pour stocker le pointeur initial vers le 1er noeud de la liste
	t_list	*ptr_to_first_node = lst;

	// Boucle pour parcourir la liste tant que l'element n'est pas le dernier
	while(lst->next != NULL)
	{
		// Les donnees actuelles et les suivantes sont egales
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			// Swap
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			// Mise a jour de lst vers le debut de la liste stocke dans ptr_to_first_node
			lst = ptr_to_first_node;
		}
		// Ou si les donnees actuelles et suivantes sont differentes
		else
			// Affecter l'element suivant a lst
			lst = lst->next;
	}
	// Mise a jour de lst vers le debut de la liste stocke dans ptr_to_first_node
	lst = ptr_to_first_node;
	return (lst);
}

/*-----------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int));

t_list	*add_int(t_list *list, int nb)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	new->data = nb;
	new->next = list;
	return (new);
}

int		ascending(int a, int b)
{
		return (a <= b);
}

int	main(void)
{
	t_list *list;

	list = NULL;
	list = add_int(list, 9);
	list = add_int(list, 3);
	list = add_int(list, 2);
	list = add_int(list, 4);
	list = add_int(list, 1);
	list = sort_list(list, &ascending);

	while(list != NULL)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
	
	return (0);
}
---------------------------------------------*/
