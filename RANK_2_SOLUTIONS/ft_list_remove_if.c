/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:33:12 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 16:22:38 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>

-------------------------------------*/

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	// Verifier si begin_list est un pointeur NULL ou si le 1er element
	// de la liste est NULL.
	if ((begin_list == NULL) || (*begin_list == NULL))
		return ;
	// Pointeur pour parcourir la liste initialise au 1er element
	// de la liste
	t_list	*current = *begin_list;
	
	// Si la comparaison entre les 2 valeurs est egale
	if (cmp(current->data, data_ref) == 0)
	{
		// Mise a jour du pointeur *begin_list vers l'element suivant
		*begin_list = current->next;
		// Suppression de l'element current
		free(current);
		// Recursion pour comparer les elements suivants et supprimer
		// ce qui doit l'etre
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	// Passer a l'element suivant de la liste
	current = *begin_list;
	// Recursion pour continuer de chercher et de supprimer d'autres elements
	ft_list_remove_if(&current->next, data_ref, cmp);
}

/*---------------------------------------
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while ((s1[idx] == s2[idx]) && (s1[idx] != '\0' && s2[idx] != '\0'))
		idx++;
	return (s1[idx] - s2[idx]);
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != NULL)
	{
		if (begin_list->data)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

t_list	*ft_new_elem(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (node = NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list	*test_list;
	t_list	**begin_list;

	begin_list = &test_list;
	test_list = ft_new_elem("Follow the ");
	test_list->next = ft_new_elem("White rabbit...");
	test_list->next->next = ft_new_elem("!");
	test_list->next->next->next = ft_new_elem("!");
	ft_list_foreach(test_list, (void *)ft_putstr);
	ft_putstr("\n");
	ft_list_remove_if(begin_list, "!", ft_strcmp);
	ft_putstr("Removing the dot -> (!)\n");
	ft_list_foreach(test_list, (void *)ft_putstr);
	ft_putstr("\n");
}
-------------------------------------------------------*/
