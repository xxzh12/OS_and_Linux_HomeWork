/* receive.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <time.h>
#include "receive.h"


#define MAXLINE 80
#define SERV_PORT 8888

int main(int argc, char *argv[]){
    struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int sockfd, n, writenBytes;
	char *IPstr;
	unsigned int account;

    char UserName[6] = "ChaosL";

    //读取可执行程序的参数
    if (argc != 3) {
		fputs("usage: ./client <account> <serverIP>\n", stderr);
		exit(1);
	}
	IPstr = argv[2];
	account = (unsigned int)atoi(argv[1]);

    //创建socket套接字，初始化IP地址与端口号
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, IPstr, &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);

    //与服务器建立链接
	int re = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if (re == -1){
		printf("Connection Failed\n");
		exit(1);
	}
	else
		printf("Successfully Connected\n");

    char* login = encode(UserName, LOGIN, account, TEXT, strlen(UserName));
    writenBytes = write(sockfd, login, strlen(UserName)+8);
	printf("%d bytes writen for login\n",writenBytes);

    while(1){
        n = read(sockfd, buf, MAXLINE);
        printf("Response from server:\n");
        write(STDOUT_FILENO, buf, n);
        printf("\n");
    }
    close(sockfd);
	return 0;
}