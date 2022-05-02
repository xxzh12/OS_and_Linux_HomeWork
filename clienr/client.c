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
#include "client.h"

#define MAXLINE 80
#define SERV_PORT 8888

int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int sockfd, n, writenBytes;
	char *str, *IPstr;
	unsigned int account;
	struct clientdata datapack;
	struct clientdata *dataptr;

	//读取参数
	if (argc < 2) {
		fputs("usage: ./client message\n", stderr);
		exit(1);
	}
	IPstr = argv[3];
	account = (unsigned int)atoi(argv[2]);
	str = argv[1];
    
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, IPstr, &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);
    
	//建立链接
	int re = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if (re == -1){
		printf("Connection Failed\n");
		//exit(1);
	}
	else
		printf("Successfully Connected\n");
	
	//信息包编码
	char* data = encode(str, SEND, account, TEXT, strlen(str));
	printf("%02x %dasd\n", *(data), strlen(str));
	int i = 0;
	for (i=0;i++;i<strlen(str)+8){
		printf("data %02x\n", *(data+i));
	}

	//添加并发送登录信号
	char* login = encode(str, LOGIN, account, TEXT, strlen(str));
	writenBytes = write(sockfd, login, strlen(str)+8);
	printf("%d bytes have been writen\n",writenBytes);	
	
	//发送信息
	int writeTimes = 0;
	int times = 3;
	while(1){
		printf("The %ds writing~\n",writeTimes);
		sleep(1);
		writeTimes++;
		printf("seeing~\n");
		//writenBytes = write(sockfd, data, strlen(str)+8);
		//printf("%d bytes have been writen\n",writenBytes);	
		n = read(sockfd, buf, MAXLINE);
		printf("Response from server:\n");
		write(STDOUT_FILENO, buf, n);
		printf("\n");
	}
	
	//发送结束信息
	str[0]='e';str[1]='n';str[2]='d';str[3]='\0';
	printf("Transferring the signal of %s\n",str);
	write(sockfd, str, strlen(str));
	close(sockfd);
	return 0;
}
