/* client.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <time.h>

#define MAXLINE 80
#define SERV_PORT 8888

int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int sockfd, n, writenBytes;
	char *str;
	char *IPstr;
	if (argc < 2) {
		fputs("usage: ./client message\n", stderr);
		exit(1);
	}
	IPstr = argv[2];
	str = argv[1];
    
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, IPstr, &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);
    
	int re = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if (re == -1){
		printf("Connection Failed\n");
		exit(1);
	}
	puts("Successfully Connected");
	
	int writeTimes = 0;
	int times = 3;
/*	while(times--)
	{
		printf("The %ds writing~\n",writeTimes);
		sleep(1);
		writeTimes++;
		printf("seeing~\n");
		writenBytes = write(sockfd, str, strlen(str));
		
		//n = read(sockfd, buf, MAXLINE);
		puts("Response from server:\n");
		//write(STDOUT_FILENO, buf, n);
		printf("\n");
	}*/
	str[0]='e';str[1]='n';str[2]='d';str[3]='\0';
	printf("Transferring the signal of %s\n",str);
	write(sockfd, str, strlen(str));
	close(sockfd);
	return 0;
}
