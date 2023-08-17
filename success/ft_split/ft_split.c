#include <stdlib.h>

char    **ft_split(char *str)
{
	int	i = 0;
	int	mot = 0;
	int	caractere;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 4096);
	if (!tab)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		caractere = 0;
		tab[mot] = malloc(sizeof(char) * 4096);
		if (! tab[mot])
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' 
				&& str[i] != '\n' 
				&& str[i] != '\0')
			tab[mot][caractere++] = str[i++];
		tab[mot][caractere] = '\0';
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		mot++;
	}
	tab[mot] = NULL;
	return (tab);
}

