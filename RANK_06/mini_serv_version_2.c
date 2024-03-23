#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

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
	int max_client[65535];

	struct sockaddr_in servaddr;

	fd_set old_fd;
	fd_set new_fd;

	char message[400000];
	char message_ext[410000];

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
	servaddr.sin_addr.s_addr = htonl(2130706433);
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

		for(int connected_client = 0; connected_client <= size; connected_client++)
		{
			if (FD_ISSET(connected_client, &old_fd) == 0)
				continue;
			
			if (connected_client == server)
			{
				if ((client = accept(server, NULL, NULL)) < 0)
					fatal();
				
				if (client > size)
					size = client;

				max_client[client] = limit++;

				FD_SET(client, &new_fd);
				sprintf(message_ext, "server: client %d just arrived\n", max_client[client]);
				send_all(message_ext, server, client, size);
			}
			else
			{
				bzero(message, 400000);
				bzero(message_ext, 410000);

				received_status = 1;

				while (received_status == 1 && (!message[0] || message[strlen(message) - 1] != '\n'))
					received_status = recv(connected_client, &message[strlen(message)], 1, 0);

				if (received_status <= 0)
				{
					sprintf(message_ext, "server: client %d just left\n", max_client[connected_client]);
					send_all(message_ext, server, client, size);
					FD_CLR(connected_client, &new_fd);
					close(connected_client);
				}
				else
				{
					sprintf(message_ext, "client %d: %s", max_client[connected_client], message);
					send_all(message_ext, server, client, size);
				}
			}
		}
	}
	return (0);
}
