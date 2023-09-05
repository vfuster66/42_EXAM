#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stddef.h>
#define BUFFER_SIZE 32

typedef struct	s_list
{
	char			*content;
	int				fd;
	struct s_list	*next;
}				t_list;

// Fonction pour dupliquer une chaîne de caractères
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// Fonction pour joindre deux chaînes de caractères
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	while (s1[len1])
		len1++;
	len2 = 0;
	while (s2[len2])
		len2++;
	joined = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!joined)
		return (NULL);
	i = -1;
	while (++i < len1)
		joined[i] = s1[i];
	j = 0;
	while (j < len2)
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}

// Fonction pour trouver la première occurrence d'un caractère dans une chaîne de caractères
int	ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}


static t_list	*find_fd(t_list **lst, int fd)
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

static int		process_line(char **line, char **remainder)
{
	char	*tmp;
	int		pos;

	pos = ft_strchr(*remainder, '\n');
	if (pos >= 0)
	{
		(*remainder)[pos] = '\0';
		*line = ft_strdup(*remainder);
		tmp = ft_strdup(*remainder + pos + 1);
		free(*remainder);
		*remainder = tmp;
		return (1);
	}
	else
	{
		*line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_list			*cur;
	char			buf[BUFFER_SIZE + 1];
	ssize_t			bytes_read;
	int				line_found;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	cur = find_fd(&lst, fd);
	if (!cur)
		return (-1);
	line_found = 0;
	while (!line_found && (bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		if (cur->content == NULL)
			cur->content = ft_strdup(buf);
		else
			cur->content = ft_strjoin(cur->content, buf);
		if (ft_strchr(cur->content, '\n') >= 0)
			line_found = process_line(line, &cur->content);
	}
	if (bytes_read == -1)
		return (-1);
	if (!line_found)
	{
		if (cur->content == NULL)
			*line = ft_strdup("");
		else
		{
			*line = cur->content;
			cur->content = NULL;
		}
	}
	return (line_found);
}

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    int result;
    while ((result = get_next_line(fd, &line)) > 0)
    {
        printf("Line read: %s\n", line);
        free(line);
    }

    if (result == 0)
    {
        printf("End of file reached\n");
    }
    else if (result == -1)
    {
        perror("Error reading line");
    }

    close(fd);

    return 0;
}

