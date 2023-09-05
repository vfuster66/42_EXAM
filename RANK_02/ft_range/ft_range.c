#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	i = 0;
	int	size;
	int	*tab;

	if (start > end)
		size = start - end + 1;
	else
		size = end - start + 1;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		if (start <= end)
			tab[i] = start++;
		else
			tab[i] = start--;
		i++;
	}
	return (tab);
}
