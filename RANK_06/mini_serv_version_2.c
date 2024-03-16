#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void putstr(char *str, int fd)
{
	write(fd, str, strlen(str));
	exit(1);
}

void sendall(char *buffer, int serverfd, int clienfd, int fd_size)
{
	for (int i = 0; i <= fd_size; i++)
		if (i != serverfd && i != clienfd)
			send(i, buffer, strlen(buffer), 0);
}

int main(int argc, char **argv)
{
	int serverfd, clientfd, fd_size, readed, db[65535] = {0}, limit = 0;
	struct sockaddr_in servaddr;
	fd_set old_fd, new_fd;
	char buffer[400000], buffer2[450000];

	if (argc != 2)
		putstr("Wrong number of arguments\n", 2);
	serverfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (serverfd == -1)
		putstr("Fatal error\n", 2);
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(argv[1])); 
	if ((bind(serverfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		putstr("Fatal error\n", 2);
	if (listen(serverfd, 10) != 0)
		putstr("Fatal error\n", 2);
    FD_ZERO(&old_fd);
	FD_ZERO(&new_fd);
	FD_SET(serverfd, &new_fd);
	fd_size = serverfd;
	while (1)
	{
		old_fd = new_fd;
		if (select(fd_size + 1, &old_fd, NULL, NULL, NULL) < 0)
			putstr("Fatal error\n", 2);
		for (int id = 0; id <= fd_size; id++)
		{
			if (FD_ISSET(id, &old_fd) == 0)
				continue;
			if (id == serverfd)
			{
				if ((clientfd = accept(serverfd, NULL, NULL)) < 0)
					putstr("Fatal error\n", 2);
				if (clientfd > fd_size)
					fd_size = clientfd;
				db[clientfd] = limit++;
				FD_SET(clientfd, &new_fd);
				sprintf(buffer, "server: client %d just arrived\n", db[clientfd]);
				sendall(buffer, serverfd, clientfd, fd_size);
			}
			else
			{
                bzero(buffer, 400000);
				bzero(buffer2, 450000);
				readed = 1;
				while (readed == 1 && (!buffer2[0] || buffer2[strlen(buffer2) - 1] != '\n'))
					readed = recv(id, &buffer2[strlen(buffer2)], 1, 0);
				if (readed <= 0)
				{
					sprintf(buffer, "server: client %d just left\n", db[id]);
					sendall(buffer, serverfd, id, fd_size);
					FD_CLR(id, &new_fd);
					close(id);
				}
				else
				{
					sprintf(buffer, "client %d: %s", db[id], buffer2);
					sendall(buffer, serverfd, id, fd_size);
				}
			}
		}
	}
	return (0);
}
