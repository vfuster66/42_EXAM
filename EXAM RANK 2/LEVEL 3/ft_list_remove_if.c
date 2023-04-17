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

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

#endif

//#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *prev = NULL;
    t_list *curr = *begin_list;

    while (curr != NULL)
    {
        if (cmp(curr->data, data_ref) == 0)
        {
            if (prev == NULL)
                *begin_list = curr->next;
            else
                prev->next = curr->next;
            free(curr);
            if (prev == NULL)
                curr = *begin_list;
            else
                curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

/*-----------------------------------

//#include "ft_list.h"
#include <stdio.h>

int cmp_int(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

void print_list(t_list *list)
{
    for (t_list *p = list; p != NULL; p = p->next)
    {
        printf("%d ", *(int *)(p->data));
    }
    printf("\n");
}

int main(void)
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    t_list *list = NULL;

    for (long unsigned int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        t_list *node = malloc(sizeof(t_list));
        node->data = &data[i];
        node->next = list;
        list = node;
    }

    printf("Original list: ");
    print_list(list);

    int remove_data = 2;
    ft_list_remove_if(&list, &remove_data, cmp_int);

    printf("List after removing %d: ", remove_data);
    print_list(list);

    return 0;
}

---------------------------------------------*/
