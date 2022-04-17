#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>

int main(int argc, char** argv)
{
    int client_socket = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM TCP için kullanıyor
    if(client_socket < 0 ) //Hata varsa -1 dönüyor
    {
        perror("socket()");
        exit(1);
    }

    //Client'in bağlanmak istediği server'in bilgilerini yazıyoruz
    struct sockaddr_in server_sockaddr; //socket adresi oluşturuyoruz
    memset( (void*) &server_sockaddr, 0, sizeof(struct sockaddr_in));
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(50505); //serveri hangi portta dinleyecek onu yazıyoruz
    server_sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(client_socket, (struct sockaddr*) &server_sockaddr, sizeof(struct sockaddr_in)) <0 )
    {
        perror("socket()");
        exit(1);
    }

    char buffer [256];
    memset((void*) &buffer, 0, 256);
    std::cout<<"enter message:";
    std::cin>>buffer;
    write(client_socket, buffer, strlen(buffer));

    close(client_socket);
    return 0;

}