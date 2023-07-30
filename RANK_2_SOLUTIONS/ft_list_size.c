/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:21:43 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 19:23:27 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Version 1
#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (ft_list_size(begin_list->next) + 1);
}

// Version 2
#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int     ft_list_size(t_list *begin_list)
{
        int     count = 0;
        t_list  *current = begin_list;

        while (current != NULL)
        {
                count++;
                current = current->next;
        }
        return (count);
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	t_list *head = malloc(sizeof(t_list));
	t_list *second = malloc(sizeof(t_list));
	t_list *third = malloc(sizeof(t_list));
	
	head->data = "Premier élément";
	head->next = second;
	
	second->data = "Deuxième élément";
	second->next = third;
	
	third->data = "Troisième élément";
	third->next = NULL;

	int size = ft_list_size(head);
	printf("La liste chaînée a une taille de %d élément(s)\n", size);
	free(head);
	free(second);
	free(third);
	
	return 0;
}
