#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#define MAX_CLIENT 65535
#define MESSAGE 450000
#define MESSAGE_EXT 400000
#define IP 2130706433

void fatal()
{
	write (2, "Fatal error\n", 12);
	exit(1);
}

void send_all(char *message, int server, int client, int size)
{
	for (int i = 0; i <= size; i++)
		if (i != server && i != client)
			send(i, message, strlen(message), 0);
}

int main(int ac, char **av)
{
	int client;
	int server;
	int size;
	int received_status;
	int limit = 0;
	int max_client[MAX_CLIENT];

	struct sockaddr_in servaddr;

	fd_set old_fd;
	fd_set new_fd;

	char message[MESSAGE];
	char message_ext[MESSAGE_EXT];

	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	server = socket(AF_INET, SOCK_STREAM, 0);

	if (server == -1)
		fatal();

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(IP);
	servaddr.sin_port = htons(atoi(av[1]));

	if ((bind(server, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		fatal();

	if (listen(server, 10) != 0)
		fatal();

	FD_ZERO(&old_fd);
	FD_ZERO(&new_fd);
	FD_SET(server, &new_fd);
	size = server;

	while(1)
	{
		old_fd = new_fd;

		if (select(size + 1, &old_fd, NULL, NULL, NULL) < 0)
			fatal();

		for(int connected_id = 0; connected_id <= size; connected_id++)
		{
			if (FD_ISSET(connected_id, &old_fd) == 0)
				continue;
			
			if (connected_id == server)
			{
				if ((client = accept(server, NULL, NULL)) < 0)
					fatal();
				
				if (client > size)
					size = client;

				max_client[client] = limit++;

				FD_SET(client, &new_fd);
				sprintf(message, "server: client %d just arrived\n", max_client[client]);
				send_all(message, server, client, size);
			}
			else
			{
				bzero(message, MESSAGE);
				bzero(message_ext, MESSAGE_EXT);

				received_status = 1;

				while (received_status == 1 && (!message_ext[0] || message_ext[strlen(message_ext) - 1] != '\n'))
					received_status = recv(connected_id, &message_ext[strlen(message_ext)], 1, 0);

				if (received_status <= 0)
				{
					sprintf(message, "server: client %d just left\n", max_client[client]);
					send_all(message, server, client, size);
					FD_CLR(connected_id, &new_fd);
					close(connected_id);
				}
				else
				{
					sprintf(message, "client %d: %s", max_client[connected_id], message_ext);
					send_all(message, server, client, size);
				}
			}
		}
	}
	return (0);
}
