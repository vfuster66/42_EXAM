/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:04:39 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 18:07:52 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	unsigned int	j;
	int	temp;

	if (size <= 1)
		return ;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size);

int main()
{
    int tab[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    unsigned int size = sizeof(tab) / sizeof(tab[0]);

    sort_int_tab(tab, size);

    for (unsigned int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}