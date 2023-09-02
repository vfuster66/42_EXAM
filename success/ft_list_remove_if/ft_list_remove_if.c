#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
        if (begin_list == NULL || *begin_list == NULL)
                return;

        t_list *current = *begin_list;
        t_list *previous = NULL;

        while (current)
        {
                if (cmp(current->data, data_ref) == 0)
                {
                        if (previous == NULL)
                        {
                                *begin_list = current->next;
                                free(current);
                                current = *begin_list;
                        }
                        else
                        {
                                previous->next = current->next;
                                free(current);
                                current = previous->next;
                        }
                }
                else
                {
                        previous = current;
                        current = current->next;
                }
        }
}

t_list *ft_create_elem(void *data)
{
    t_list *new_element = malloc(sizeof(t_list));
    if (new_element)
    {
        new_element->next = NULL;
        new_element->data = data;
    }
    return new_element;
}

int compare_data(void *a, void *b)
{
    int *int_a = (int *)a;
    int *int_b = (int *)b;
    return (*int_a - *int_b);
}

void print_list(t_list *begin_list)
{
    t_list *current = begin_list;
    while (current)
    {
        int *data = (int *)(current->data);
        printf("%d ", *data);
        current = current->next;
    }
    printf("\n");
}

int main(void)
{
    t_list *list = NULL;

    int data1 = 1, data2 = 2, data3 = 3, data4 = 4, data5 = 5;

    list = ft_create_elem(&data1);
    list->next = ft_create_elem(&data2);
    list->next->next = ft_create_elem(&data3);
    list->next->next->next = ft_create_elem(&data4);
    list->next->next->next->next = ft_create_elem(&data5);

    printf("Liste d'origine : ");
    print_list(list);

    int data_ref = 3;

    ft_list_remove_if(&list, &data_ref, compare_data);

    printf("Liste après suppression : ");
    print_list(list);

    return (0);
}
