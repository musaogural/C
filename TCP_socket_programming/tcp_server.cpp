// server.cpp

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char**argv)
{
	int server_socket = socket(AF_INET, SOCK_STREAM, 0); // SOCK_STREAM TCP için kullanılıyor.
	if( server_socket < 0 ) // Hata varsa -1 dönüyor
	{
		perror("socket()");
		exit(1);
	}

	struct sockaddr_in server_sockaddr;  //soket adresi oluşturuyoruz.
	memset((void*)&server_sockaddr, 0, sizeof(struct sockaddr_in));
	server_sockaddr.sin_family = AF_INET;
	server_sockaddr.sin_port = htons(50505); // serverınız hangi portta dinleyecek bir sayi veriyoruz
	server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY); //IP adresini saklıyor. Long olduğu için htonl dedik
	if( bind(server_socket, (struct sockaddr*)&server_sockaddr, sizeof(struct sockaddr_in)) <0)
	{
		perror("bind()");
		exit(1);
	}

	if( listen(server_socket, 2) < 0 )  //server dinlemeye başlıyor. Bu server kaç client'a hizmet verecek (2 verelim.)
	{
		perror("listen()");
		exit(1);
	}

	struct sockaddr_in client_sockaddr;  
        memset( (void*)&client_sockaddr, 0, sizeof(struct sockaddr_in) );
        socklen_t client_sockaddrlen= sizeof(struct sockaddr_in);
	int client_socket;
        pid_t pid;

        while(1)  // sonsuz döngüde accepte bağlantı gelene kadar sürekli bekliyor bağlantı gelince devam ediyor
       {
              client_socket = accept(server_socket, (struct sockaddr*) &client_sockaddr, &client_sockaddrlen);
              if( client_socket < 0 )
	      {
	        perror("accept()");
		exit(1);
	      }
              pid=fork();  //bizim programımızın bir kopyasını oluşturuyor.İki process var biri parent diğeri child.
              // forktan sonra çalışmaya devam ediyorlar.
              if (pid<0)
              {
                perror("fork()");
                exit(1);
              }

              if (pid==0)    //child'ın yapacaği işlemler
              //client'tan gelen mesajı ekrana yazdıralım
              {
                char buffer [256];
                memset( (void*)buffer,0,256);
                read(client_socket,(void*)buffer, 256); // Client bize bir data gönderiyor, client_socket de gelen datayı buffera okuyor.
                std::cout << inet_ntoa(client_sockaddr.sin_addr)<< " : " << buffer<< std::endl;  //client ip adresini ve client
                //ne gönderdiyse onu ekrana yazdırdık
                close(client_socket);
                return 0;
              }

              if (pid>0)   //parent'ın yapacağı işlemler
              { 
                close(client_socket);
              }

       }	
            return 0;
}
