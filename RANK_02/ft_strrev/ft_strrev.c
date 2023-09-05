#include <stdlib.h>

char    *ft_strrev(char *str)
{
	char	*start;
	char	*end;
	char	temp;

	if (!str)
		return (NULL);
	start = str;
	end = str;

	while (*end)
		end++;
	end--;
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	return (str);	
}
