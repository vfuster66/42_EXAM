#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32 // Vous pouvez définir une taille de tampon par défaut si elle n'est pas définie ailleurs
# endif

int		get_next_line(int fd, char **line);

// Ajoutez ici les prototypes de vos fonctions auxiliaires, le cas échéant

#endif

