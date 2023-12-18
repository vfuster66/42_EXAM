#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>

typedef struct s_server
{
	int				socket;
	int				port;
	int				nextClientId;
	struct sockaddr_in	addr;
}	t_server;

typedef struct s_client
{
	int				id;
	int				socket;
	struct s_client *next;
}	t_client;

t_server	server;
t_client	*clients = NULL;

fd_set		opened_fd;
fd_set		read_fd;

char		buff_low[256];
char		buff_recv[300000];
char		buff_send[300100];

//########## utils ###########

int	fatal()
{
	write(2, "Fatal error\n", 12);
	exit(1);
	return (1);
}

int	get_id(int socket)
{
	for (t_client *clt = clients; clt; clt = clt->next)
		if (clt->socket == socket)
			return (clt->id);
	return (-1);
}

int	get_max_fd()
{
	int	maxfd = server.socket;

	for (t_client *clt = clients; clt; clt = clt->next)
		if (clt->socket > maxfd)
			maxfd = clt->socket;
	return (maxfd);
}

//########### message ##########

int	send_to_all(char *str, int sender)
{
	for (t_client *clt = clients; clt; clt = clt->next)
		if (clt->socket != sender)
			send(clt->socket, str, strlen(str), 0);
	return (0);
}

//########### clients ############

int	accept_client()
{
	t_client	*client = calloc(sizeof(t_client), 1);

	if (!client)
		return (fatal());
	client->socket = accept(server.socket, NULL, NULL);
	if (client->socket < 0)
		return (free(client), 1);​
	client->id = server.nextClientId ++;
	client->next = clients;
	bzero(&buff_low, sizeof(buff_low));
	sprintf(buff_low, "server: client %d just arrived\n", client->id);
	send_to_all(buff_low, client->socket);
	clients = client;
	FD_SET(client->socket, &opened_fd);
	return (0);
}

int	remove_client(int socket)
{
	if (clients && clients->socket == socket)
	{
		t_client *tofree = clients;
		
    clients = clients->next;
		FD_CLR(tofree->socket, &opened_fd);
		close(tofree->socket);
		free(tofree);
		return (0);
	}
	for (t_client *clt = clients; clt; clt = clt->next)
	{
		if (clt->next && clt->next->socket == socket)
		{
			t_client *tofree = clt->next;
			clt->next = clt->next->next;
			FD_CLR(tofree->socket, &opened_fd);
			close(tofree->socket);
			free(tofree);
			return (0);
    }
	}
	return (1);
}

int	process_client(int i)
{
	int	size = 1;

	bzero(&buff_recv, sizeof(buff_recv));
	while (size == 1 && (!buff_recv[0] || buff_recv[strlen(buff_recv) - 1] != '\n'))
		size = recv(i, buff_recv + strlen(buff_recv), 1, 0);
	if (size == 0)
	{
		bzero(&buff_low, sizeof(buff_low));
		sprintf(buff_low, "server: client %d just left\n", get_id(i));
		send_to_all(buff_low, i);
		remove_client(i);
	}
	else
	{
		bzero(&buff_send, sizeof(buff_send));
		sprintf(buff_send, "client %d: %s", get_id(i), buff_recv);
		send_to_all(buff_send, i);
	}
	return (0);
}

//########## server #############

int	process_server(int maxfd)
{
	for (int i = 0; i <= maxfd; i ++)
	{
		if (!FD_ISSET(i, &read_fd))
			continue ;
		if (i == server.socket)
		{
			accept_client();
			break ;
		}
		else
		{
			process_client(i);
			break ;
		}
	}
	return (0);
}​

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (write(2, "Wrong number of arguments\n", 26), exit(1), 1);
	server.port = atoi(argv[1]);
	server.nextClientId = 0;
	server.socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server.socket < 0)
		return (fatal());
	bzero(&server.addr, sizeof(server.addr));
	server.addr.sin_port = htons(server.port);
	server.addr.sin_family = AF_INET;
	server.addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	if (bind(server.socket, (const struct sockaddr *)&server.addr, sizeof(server.addr)) != 0)
		return (fatal());
	if (listen(server.socket, 128) != 0)
		return (fatal());
	FD_ZERO(&opened_fd);
	FD_SET(server.socket, &opened_fd);
	while (1)
	{
		read_fd = opened_fd;
		int maxfd = get_max_fd();
    
		if (select(maxfd + 1, &read_fd, NULL, NULL, NULL) < 0)
			return (fatal());
		process_server(maxfd);
	}
	return (0);
}
