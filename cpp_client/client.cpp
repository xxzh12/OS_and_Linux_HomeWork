/* client.cpp by Chaos */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <time.h>
#include <string>
#include <cstring>
#include "client.h"

#define MAXLINE 80
#define SERV_PORT 8888

using namespace std;

//编译生成的可执行程序后的第一个跟着账户名（数字），第二个跟着服务器的IP地址
int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int sockfd;
	unsigned int account;
	char* IPstr;
	char* UserName;

	if (argc != 4){
		cout << "Usage: ./client <account> <UserName> <serverIP>" << endl;
		exit(1);
	}
	account = (unsigned int)atoi(argv[1]);
	UserName = argv[2];
	IPstr = argv[3];

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

	string login = Encoder::encode(UserName, LOGIN, account, TEXT, strlen(UserName));
}