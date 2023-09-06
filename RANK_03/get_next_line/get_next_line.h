#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32 // Vous pouvez définir une taille de tampon par défaut si elle n'est pas définie ailleurs
# endif

typedef struct	s_list
{
  char			*content;
	int				fd;
	struct s_list	*next;
}				t_list;

int		get_next_line(int fd, char **line);

#endif

