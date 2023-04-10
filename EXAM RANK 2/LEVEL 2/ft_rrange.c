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

int     *ft_rrange(int start, int end)
{
    int size;
    int *result;
    int i;
    int step;

    if (start > end)
        size = start - end + 1;
    else
        size = end - start + 1;
    result = (int *)malloc(sizeof(int) * size);
    if (!result)
        return (NULL);
    i = 0;
    if (start > end)
        step = 1;
    else
        step = -1;
    while (i < size)
    {
        result[i] = end;
        end += step;
        i++;
    }
    return (result);
}

/*-----------------------------------------

#include <stdio.h>

int     *ft_rrange(int start, int end);

int     main(void)
{
    int     *result;
    int     i;

    // Test case 1
    result = ft_rrange(1, 3);
    i = 0;
    while (i < 3)
    {
        printf("%d ", result[i]);
        i++;
    }
    printf("\n");
    free(result);

    // Test case 2
    result = ft_rrange(2, -1);
    i = 0;
    while (i < 4)
    {
        printf("%d ", result[i]);
        i++;
    }
    printf("\n");
    free(result);

    // Test case 3
    result = ft_rrange(0, 0);
    printf("%d\n", result[0]);
    free(result);

    // Test case 4
    result = ft_rrange(-3, 0);
    i = 0;
    while (i < 4)
    {
        printf("%d ", result[i]);
        i++;
    }
    printf("\n");
    free(result);

    return (0);
}

---------------------------------------*/
