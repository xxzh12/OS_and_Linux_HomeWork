#include<iostream>
#include<vector>
#include<map>
#include<string> 
#include<algorithm>
#include<unistd.h>
#include<cstdlib>
#include<jsoncpp/json/json.h>
#include<sys/epoll.h>
#include<arpa/inet.h>
#include<protocolmsg.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#ifndef MAX_CONNECTIONS 
#define MAX_CONNECTIONS 100
#endif

#ifndef PORT
#define PORT 8888
#endif


