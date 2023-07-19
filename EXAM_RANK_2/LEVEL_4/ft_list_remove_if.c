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
    // Pointeur vers le nœud suivant dans la liste.
    struct s_list *next;
    // Pointeur générique vers les données stockées dans le nœud.
    void          *data; 
}                 t_list;

// Cette fonction supprime tous les nœuds de la liste qui contiennent des données égales à data_ref.
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

#endif

//#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    // Pointeur vers le nœud précédent lors du parcours de la liste.
    t_list *prev = NULL;
    // Pointeur vers le nœud courant lors du parcours de la liste.
    t_list *curr = *begin_list; 

    // On parcourt la liste en comparant les données de chaque nœud avec data_ref.
    while (curr != NULL)
    {
        // Si les données sont égales, on supprime le nœud correspondant.
        if (cmp(curr->data, data_ref) == 0) 
        {
            // Si le nœud à supprimer est le premier de la liste, on met à jour le pointeur vers le premier nœud.
            if (prev == NULL) 
                *begin_list = curr->next;
            // Sinon, on met à jour le pointeur next du nœud précédent pour sauter le nœud à supprimer.
            else 
                prev->next = curr->next;
            // On libère la mémoire allouée pour le nœud à supprimer.
            free(curr);
            // Si on a supprimé le premier nœud, on continue à partir du nouveau premier nœud.
            if (prev == NULL)
                curr = *begin_list;
            // Sinon, on continue à partir du nœud suivant celui qui vient d'être supprimé.
            else 
                curr = prev->next;
        }
        // Si les données ne sont pas égales, on continue le parcours de la liste.
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
