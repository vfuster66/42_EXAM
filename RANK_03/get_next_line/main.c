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
