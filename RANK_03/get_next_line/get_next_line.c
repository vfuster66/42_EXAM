#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stddef.h>
#define BUFFER_SIZE 32

// Fonction pour dupliquer une chaîne de caractères
char    *ft_strdup(char *src)
{
	char	*dest;
	int	i = 0;

	while (src[i])
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// Fonction pour joindre deux chaînes de caractères
char *ft_strjoin(const char *s1, const char *s2)
{
	size_t len_s1 = 0;
	size_t len_s2 = 0;
	size_t	i;
	size_t	j;
	char	*str;
    
	if (s1 == NULL || s2 == NULL)
        	return (NULL);
	while (s1[len_s1])
        	len_s1++;
    	while (s2[len_s2])
        	len_s2++;
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (str == NULL)
        	return (NULL);
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

// Fonction pour trouver la première occurrence d'un caractère dans une chaîne de caractères
char *ft_strchr(const char *s, int c)
{
	char find = (char)c;
	int i = 0;

	while (s[i])
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return NULL;
}

static t_list *trouver_fd(t_list **lst, int fd)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
        	return (NULL);
	tmp->fd = fd;
	tmp->content = NULL;
	tmp->next = *lst;
	*lst = tmp;
	return (tmp);
}

static int	traiter_ligne(char **ligne, char **reste)
{
	char	*ligne_courante;
	int		position;

	position = ft_strchr(*reste, '\n');
	if (position >= 0)
	{
		(*reste)[position] = '\0';
		*ligne = ft_strdup(*reste);
		ligne_courante = ft_strdup(*reste + position + 1);
		free(*reste);
		*reste = ligne_courante;
		return (1);
	}
	else
	{
		*ligne = ft_strdup(*reste);
		free(*reste);
		*reste = NULL;
		return (0);
	}
}

int	get_next_line(int fd, char **ligne)
{
	static t_list	*lst;
	t_list			*current;
	char			buffer[BUFFER_SIZE + 1];
	ssize_t			octet_lu;
	int				ligne_trouvee;

	if (fd < 0 || ligne == NULL || BUFFER_SIZE <= 0)
		return (-1);
	current = find_fd(&lst, fd);
	if (!current)
		return (-1);
	ligne_trouvee = 0;
	while (!ligne_trouvee && (octet_lu = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[octet_lu] = '\0';
		if (current->content == NULL)
			current->content = ft_strdup(buffer);
		else
			current->content = ft_strjoin(current->content, buffer);
		if (ft_strchr(current->content, '\n') >= 0)
			ligne_trouvee = traiter_ligne(ligne, &current->content);
	}
	if (octet_lu == -1)
		return (-1);
	if (!ligne_trouvee)
	{
		if (current->content == NULL)
			*ligne = ft_strdup("");
		else
		{
			*line = current->content;
			current->content = NULL;
		}
	}
	return (ligne_trouvee);
}

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	char *line;
	int result;

	if (ac != 2)
	{
		printf("Usage: %s <filename>\n", av[0]);
		return 1;
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}
	while ((result = get_next_line(fd, &line)) > 0)
	{
		printf("Line read: %s\n", line);
		free(line);
	}
	if (result == 0)
		printf("End of file reached\n");
	else if (result == -1)
		perror("Error reading line");
	close(fd);
	return 0;
}

