// client

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
	int client_socket = socket(PF_INET, SOCK_DGRAM, 0);
	if(client_socket < 0)
	{
		perror("socket()");
		return -1;
	}

	struct sockaddr_in client_address;
	memset(&client_address, 0, sizeof(client_address));
	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(0);
	client_address.sin_addr.s_addr = htonl(INADDR_ANY);
	if( bind(client_socket, (struct sockaddr*)&client_address, sizeof(client_address)) )
	{
		perror("bind()");
		close(client_socket);
		return -1;
	}

	struct sockaddr_in server_address;
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family  = AF_INET;
	server_address.sin_port = htons(50505);
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	char buf[SIZE];
	cout << "enter message to send:";
	cin.getline(buf, SIZE);
	
	cout << sendto(client_socket,
				   buf,
				   strlen(buf),
				   0,
				   (struct sockaddr*) &server_address,
				   sizeof(server_address))
		 << " bytes are sent." << endl;

	close(client_socket);
	return 0;
}


























