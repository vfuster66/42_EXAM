/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:06:32 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 19:41:45 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
-------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.

-------------------------------*/

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int i = 0;
    int *rrange;
    int size;

    if (start > end)
        size = start - end + 1;
    else
        size = end - start + 1;
    rrange = malloc(sizeof(int) * size);
    if (!rrange)
        return (NULL);
    while (i < size)
    {
        if (start <= end)
            rrange[i] = end--;
        else
            rrange[i] = end++;
        i++;
    }
    return (rrange);
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

