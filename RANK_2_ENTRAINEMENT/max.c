/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:54:24 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 17:59:04 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	max(int* tab, unsigned int len)
{

}

#include <stdlib.h>
#include <stdio.h>

int max(int *tab, unsigned int len);

int main(void)
{
    int tab1[] = {1, 2, 3, 4, 5};
    int tab2[] = {-1, -2, -3, -4, -5};
    int tab3[] = {0, 0, 0, 0, 0};
    int tab4[] = {5};
    int tab5[] = {0, -5, 7, 10, -2, 3};
    int tab6[] = {};

    printf("Max of tab1: %d\n", max(tab1, sizeof(tab1)/sizeof(int)));
    printf("Max of tab2: %d\n", max(tab2, sizeof(tab2)/sizeof(int)));
    printf("Max of tab3: %d\n", max(tab3, sizeof(tab3)/sizeof(int)));
    printf("Max of tab4: %d\n", max(tab4, sizeof(tab4)/sizeof(int)));
    printf("Max of tab5: %d\n", max(tab5, sizeof(tab5)/sizeof(int)));
    printf("Max of tab6: %d\n", max(tab6, sizeof(tab6)/sizeof(int)));

    return (0);
}
