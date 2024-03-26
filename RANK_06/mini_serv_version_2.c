#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>

void fatal()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

void sendall(char *message_ext, int server_socket, int client_socket, int max_fd)
{
	for (int fd = 0; fd <= max_fd; fd++)
		if (fd != server_socket && fd != client_socket)
			send(fd, message_ext, strlen(message_ext), 0);
}

int main(int ac, char **av)
{
	int server_socket, client_socket, max_fd, recv_status, client_index[65535] = {0}, next_client_index = 0;
	struct sockaddr_in servaddr;
	fd_set current_fd, next_fd;
	char message_ext[500000] = {0}, message[450000] = {0};

	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}
	server_socket = socket(AF_INET, SOCK_STREAM, 0); 
	if (server_socket == -1)
		fatal();
	memset(&servaddr, 0, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	servaddr.sin_port = htons(atoi(av[1])); 
	if ((bind(server_socket, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		fatal();
	if (listen(server_socket, 10) != 0)
		fatal();
	FD_ZERO(&current_fd);
	FD_ZERO(&next_fd);
	FD_SET(server_socket, &next_fd);
	max_fd = server_socket;
	while (1)
	{
		current_fd = next_fd;
		if (select(max_fd + 1, &current_fd, NULL, NULL, NULL) < 0)
			fatal();
		for (int index = 0; index <= max_fd; index++)
		{
			if (FD_ISSET(index, &current_fd) == 0)
				continue;
			if (index == server_socket)
			{
				if ((client_socket = accept(server_socket, NULL, NULL)) < 0)
					fatal();
				if (client_socket > max_fd)
					max_fd = client_socket;
				client_index[client_socket] = next_client_index++;
				FD_SET(client_socket, &next_fd);
				sprintf(message_ext, "server: client %d just arrived\n", client_index[client_socket]);
				sendall(message_ext, server_socket, client_socket, max_fd);
			}
			else
			{
                		memset(message_ext, 0, 500000);
				memset(message, 0, 450000);
				recv_status = 1;
				while (recv_status == 1 && (!message[0] || message[strlen(message) - 1] != '\n'))
					recv_status = recv(index, &message[strlen(message)], 1, 0);
				if (recv_status <= 0)
				{
					sprintf(message_ext, "server: client %d just left\n", client_index[index]);
					sendall(message_ext, server_socket, index, max_fd);
					FD_CLR(index, &next_fd);
					close(index);
				}
				else
				{
					sprintf(message_ext, "client %d: %s", client_index[index], message);
					sendall(message_ext, server_socket, index, max_fd);
				}
			}
		}
	}
	return (0);
}
