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
	char *IPstr;
	char str[50];
	unsigned int account;
	struct clientdata datapack;
	struct clientdata *dataptr;
	int key;

	//个人用户名赋值
	char UserName[5] = "Chaos";

	//读取参数
	if (argc < 2) {
		fputs("usage: ./client message\n", stderr);
		exit(1);
	}
	IPstr = argv[3];
	account = (unsigned int)atoi(argv[2]);
	//str = argv[1];
    
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, IPstr, &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);
    
	//与服务器建立链接
	int re = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if (re == -1){
		printf("Connection Failed\n");
		//exit(1);
	}
	else
		printf("Successfully Connected\n");

	//等待登录请求
	printf("waiting for LOGIN signal-tab");
	while(1){
		key = scanKeyboard();
		if (key == KEY_LOGIN)
			break;
	}
	//添加登录信号
	char* login = encode(UserName, LOGIN, account, TEXT, strlen(UserName));
	//
	while(1){
		switch(key){
			case KEY_LOGIN:
				//添加并发送登录信号
				writenBytes = write(sockfd, login, strlen(UserName)+8);
				printf("%d bytes have been writen for login\n",writenBytes);
				key = KEY_INPUT;

			case KEY_INPUT:
				printf("Please input your message, but no bigger that 50 letters!\n");
				scanf("%[^\n]", str);
				printf("23456\n");
				//信息包编码
				char* data = encode(str, SEND, account, TEXT, strlen(str));
				printf("%02x %dasd\n", *(data), strlen(str));
				//发送信息
				int writeTimes = 0;
				int times = 3;
				while(times--){
					printf("The %ds writing~\n",writeTimes);
					sleep(1);
					writeTimes++;
					printf("seeing~\n");
					writenBytes = write(sockfd, data, strlen(str)+8);
					printf("%d bytes have been writen\n",writenBytes);	
					n = read(sockfd, buf, MAXLINE);
					printf("Response from server:\n");
					write(STDOUT_FILENO, buf, n);
					printf("\n");
				}

			case KEY_LOGOUT:
				break;

			default:
				printf("error");
				break;

		}
	}

	
	

	while(1);

	//发送结束信息
	str[0]='e';str[1]='n';str[2]='d';str[3]='\0';
	printf("Transferring the signal of %s\n",str);
	write(sockfd, str, strlen(str));
	close(sockfd);
	return 0;
}
