/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:06:32 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/16 17:57:44 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_rrange(int start, int end)
{

}

#include <stdio.h>
#include <stdlib.h>

int *ft_rrange(int start, int end);

int main()
{
    int *arr;
    int i;
    
    arr = ft_rrange(1, 3);
    printf("Array: ");
    for (i = 0; i < 3; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    
    arr = ft_rrange(-1, 2);
    printf("Array: ");
    for (i = 0; i < 4; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    
    arr = ft_rrange(0, 0);
    printf("Array: %d\n", arr[0]);
    free(arr);
    
    arr = ft_rrange(0, -3);
    printf("Array: ");
    for (i = 0; i < 4; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    
    return 0;
}

