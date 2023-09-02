#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (!begin_list || !f)
	        return ;
	t_list *list_ptr = begin_list;

	while (list_ptr)
	{
		 (*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

void	print_data(void *data)
{
	printf("%d ", *(int *)data);
}

t_list	*create_element(void *data)
{
	t_list *new_element = malloc(sizeof(t_list));

	if (new_element)
	{
		new_element->next = NULL;
		new_element->data = data;
	}
	return (new_element);
}

int	main(void)
{
	int	data1 = 42;
	int	data2 = 77;
	int	data3 = 123;
	t_list	*list;
	t_list	*temp;

	list = create_element(&data1);
	list->next = create_element(&data2);
	list->next->next = create_element(&data3);
	ft_list_foreach(list, print_data);
	printf("\n");
	while (list)
    	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return (0);
}
