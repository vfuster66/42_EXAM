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

/*-------------------------------------

#include <stdio.h>
#include <stdlib.h>

int *ft_rrange(int start, int end);

int main()
{
    int start = -1;
    int end = 2;
    int *arr = ft_rrange(start, end);
    int size = abs(start - end) + 1;

    if (arr == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    printf("Array of %d integers, starting at %d and ending at %d:\n", size, start, end);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

---------------------------------------*/
