/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:23:52 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 17:57:02 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{

}

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void print_int(void *data)
{
    printf("%d ", *(int*)data);
}

int main()
{
    t_list *list = NULL;
    int n1 = 10, n2 = 20, n3 = 30;
    list = malloc(sizeof(t_list));
    list->data = &n1;
    list->next = malloc(sizeof(t_list));
    list->next->data = &n2;
    list->next->next = malloc(sizeof(t_list));
    list->next->next->data = &n3;
    list->next->next->next = NULL;

    ft_list_foreach(list, print_int);
    printf("\n");

    free(list->next->next);
    free(list->next);
    free(list);

    return 0;
}