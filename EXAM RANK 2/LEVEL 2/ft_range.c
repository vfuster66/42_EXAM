/*Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
-----------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.

---------------------------*/

#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int		size;
	int		*range;
	int		i;

	if (start > end)
		size = start - end + 1;
	else
		size = end - start + 1;
	range = (int *)malloc(sizeof(int) * size);
	if (range == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (start <= end)
			range[i] = start++;
		else
			range[i] = start--;
		i++;
	}
	return (range);
}

/*-------------------------

#include <stdio.h>
#include <stdlib.h>

int		*ft_range(int start, int end);

int		main(void)
{
	int		*range;
	int		size;
	int		i;

	range = ft_range(1, 3);
	if (range == NULL)
	{
		printf("Error: Memory allocation failed\n");
		return (1);
	}
	size = 3;
	i = 0;
	while (i < size)
	{
		printf("%d ", range[i]);
		i++;
	}
	free(range);
	range = NULL;
	printf("\n");

	range = ft_range(-1, 2);
	if (range == NULL)
	{
		printf("Error: Memory allocation failed\n");
		return (1);
	}
	size = 4;
	i = 0;
	while (i < size)
	{
		printf("%d ", range[i]);
		i++;
	}
	free(range);
	range = NULL;
	printf("\n");

	range = ft_range(0, 0);
	if (range == NULL)
	{
		printf("Error: Memory allocation failed\n");
		return (1);
	}
	size = 1;
	i = 0;
	while (i < size)
	{
		printf("%d ", range[i]);
		i++;
	}
	free(range);
	range = NULL;
	printf("\n");

	range = ft_range(0, -3);
	if (range == NULL)
	{
		printf("Error: Memory allocation failed\n");
		return (1);
	}
	size = 4;
	i = 0;
	while (i < size)
	{
		printf("%d ", range[i]);
		i++;
	}
	free(range);
	range = NULL;
	printf("\n");

	return (0);
}


----------------------------*/
