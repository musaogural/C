#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv)
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM TCP için kullanıyor
    if(server_socket < 0 ) //Hata varsa -1 dönüyor
    {
        perror("socket()");
        exit(1);
    }

    struct sockaddr_in server_sockaddr; //socket adresi oluşturuyoruz
    memset( (void*) &server_sockaddr, 0, sizeof(struct sockaddr_in));

    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(50505);
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY); //IP adresini saklıyor.

    if( bind(server_socket, (struct sockaddr*)&server_sockaddr, sizeof(struct sockaddr_in)) < 0)
    {
        perror("bind()");
        exit(1);
    }

    if( listen(server_socket, 1) <0 ) //server dinlenmeye başlıyor. Bu server kaç cliente hizmet verecek 2 diyelim.
    {
        perror("listen()");
        exit(1);
    }

    struct sockaddr_in client_sockaddr; 
    memset( (void*) &client_sockaddr, 0, sizeof(struct sockaddr_in));
    socklen_t client_sockaddrlen = sizeof( struct sockaddr_in );
    int client_socket;
    pid_t pid;

    while(1) //sonsuz döngüde accepte bağlantı gelene kadar sürekli bekliyor bağlantı gelince devam ediyor
    {
        client_socket = accept(server_socket, (struct sockaddr*) &client_sockaddr, &client_sockaddrlen);
        if( client_socket <0 )
        {
            perror("accept()");
            exit(1);
        }

        pid = fork(); //bizim programın bir kopyasını oluşturuyor. İki process var biri patent diğeri child. forktan sonra çalışmaya devam ediyorlar.

        if(pid < 0) //parentin yapacağı işlemler
        {
            perror("fork()");
            exit(1);
        }

        if(pid == 0) //childin yapacağı işlemler. clientten gelen mesajı ekrana yazdırıyor.
        {
            char buffer[256];
            memset((void*) &buffer, 0, 256);
            read(client_socket, (void*) buffer, 256); //client bize bir data gönderiyor. client_socket de gelen datayı buffera okuyor
            std::cout<< inet_ntoa(client_sockaddr.sin_addr) <<":" <<buffer <<std::endl;
            close(client_socket);
            
            return 0;
        }

        if(pid > 0)
        {
            close(client_socket);
        }
    }

    return 0;
}