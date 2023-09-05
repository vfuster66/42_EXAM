#include "list.h"
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	temp;
	t_list	*ptr_to_begin_list = lst;

	while (lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = ptr_to_begin_list;
		}
		else
			lst = lst->next;
	}
	lst = ptr_to_begin_list;
	return (lst);
}
				
