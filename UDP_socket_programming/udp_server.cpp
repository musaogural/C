// server

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <cstdio>
#include <iostream>
using namespace std;
#include <cstring>

#define SIZE 256

int main(void)
{
	int server_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if( server_socket < 0 )
	{
		perror("socket()");
		return -1;
	}
	cout << "server socket : " << server_socket << endl;

	struct sockaddr_in server_address;
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(50505);
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	if( bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) )
	{
		perror("bind()");
		close(server_socket);
		return -1;
	}

	struct sockaddr_in client_address;
	memset(&client_address, 0, sizeof(client_address));
	socklen_t client_address_length = sizeof(client_address);
	while(1)
	{
		char buffer[SIZE];

		if ( recvfrom(server_socket,
					  buffer,
					  SIZE,
					  0,
					  (struct sockaddr*) &client_address,
					  &client_address_length) > 0 )
		{
			cout << inet_ntoa(client_address.sin_addr)
				 << ":"
				 << ntohs(client_address.sin_port)
				 << ">>>"
				 << buffer
				 << endl
				 << endl;
			memset(&client_address, 0, sizeof(client_address));
			memset(buffer, 0, SIZE);
		}
	}

	close(server_socket);
	return 0;
}




















