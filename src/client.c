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

//编译生成的可执行程序后的第一个跟着账户名（数字），第二个跟着服务器的IP地址
int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int sockfd, n, writenBytes;
	char *IPstr;
	char str[50];
	char nonestr[10] = " ";
	unsigned int account;
	int key;
	char* shell;

	//个人用户名赋值
	char UserName[5] = "Chaos";

	//读取参数
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

	//等待登录请求
	printf("waiting for LOGIN signal-tab\n");
	while(1){
		key = scanKeyboard();
		if (key == KEY_LOGIN)
			break;
	}

	//添加登录信号
	char* login = encode(UserName, LOGIN, account, TEXT, strlen(UserName));
	char* logout = encode(UserName, LOGOUT, account, TEXT, strlen(UserName));
	printf("hello");
	//
	shell = "gnome-terminal -x ./receive 145 127.0.0.1";
	/*
	strncat(shell, account, strlen(account));
	strncat(shell, " ", 1);
	strncat(shell, IPstr, strlen(IPstr));
	*/
	system(shell);

	while(1){
		printf("Input '#' to go into INPUT mode, 'Esc' for LOGOUT mode\n");
		switch(key){
			case KEY_LOGIN:
				//添加并发送登录信号
				writenBytes = write(sockfd, login, strlen(UserName)+8);
				printf("%d bytes writen for login\n",writenBytes);
				key = KEY_INPUT;
				break;

			case KEY_INPUT:
				printf("Please input your message, but no bigger that 50 letters!\n");
				strcpy(str, nonestr);
				scanf("%[^\n]", str);
				//信息包编码
				char* data = encode(str, SEND, account, TEXT, strlen(str));
				//printf("%02x %dasd\n", *(data), strlen(str));
				//发送信息
				//int writeTimes = 0;
				int times = 1;
				while(times--){
					//printf("The %ds writing~\n",writeTimes);
					sleep(1);
					//writeTimes++;
					writenBytes = write(sockfd, data, strlen(str)+8);
					printf("%d bytes writen for message\n",writenBytes);	
					n = read(sockfd, buf, MAXLINE);
					printf("Response from server:\n");
					write(STDOUT_FILENO, buf, n);
					printf("\n");
				}
				break;

			case KEY_LOGOUT:
				//发送登出信息
				writenBytes = write(sockfd, logout, strlen(UserName)+8);
				printf("%d bytes writen for logout\n", writenBytes);
				n = read(sockfd, buf, MAXLINE);
				printf("Response from server:\n");
				write(STDOUT_FILENO, buf, n);
				printf("\n");
				key = KEY_LOGOUTED;
				break;

			default:
				printf("error, %d\n", key);
				break;
		}
		if(key == KEY_LOGOUTED)
			break;
		key = scanKeyboard();
	}

	//发送结束信息
	str[0]='e';str[1]='n';str[2]='d';str[3]='\0';
	printf("Transferring the signal of %s\n",str);
	//write(sockfd, str, strlen(str));
	close(sockfd);
	return 0;
}
