#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

void fatal()
{
    write(2, "Fatal error\n", 12);
    exit(1);
}

void send_all(char *message_ext, int server, int client, int size)
{
    for(int fd = 0; fd <= size; fd++)
        if (fd != server && fd != client)
            send(fd, message_ext, strlen(message_ext), 0);
}

int main(int ac, char **av)
{
    int server, client, size, recv_status, max_client[65535] = {0}, limit = 0;
    fd_set old_fd, new_fd;
    struct sockaddr_in servaddr;
    char message[400000];
    char message_ext[450000];

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
    while (1)
    {
        old_fd = new_fd;
        if (select(size + 1, &old_fd, NULL, NULL, NULL) < 0)
            fatal();
        for(int client_connected = 0; client_connected <= size; client_connected++)
        {
            if (FD_ISSET(client_connected, &old_fd) == 0)
                continue;
            if (client_connected == server)
            {
                if ((client = accept(server, NULL, NULL)) < 0)
                    fatal();
                if (client > size)
                    size = client;
                max_client[client] = limit++;
                FD_SET(client, &new_fd);
                bzero(message_ext, 450000);
                sprintf(message_ext, "server: client %d just arrived\n", max_client[client]);
                send_all(message_ext, server, client, size);
            }
            else
            {
                bzero(message, 400000);
                bzero(message_ext, 450000);
                recv_status = 1;
                while (recv_status == 1 && (!message[0] || message[strlen(message) - 1] != '\n'))
                    recv_status = recv(client_connected, &message[strlen(message)], 1, 0);
                if (recv_status == 0)
                {
                    sprintf(message_ext, "server: client %d just left\n", max_client[client_connected]);
                    send_all(message_ext, server, client_connected, size);
                    FD_CLR(client_connected, &new_fd);
                    close(client_connected);
                }
                else
                {
                    sprintf(message_ext, "client %d: %s", max_client[client_connected], message);
                    send_all(message_ext, server, client_connected, size);
                }
            }
        }
    }
    return (0);
}
