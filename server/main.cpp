#include<DataProcesser.h>
#include<Online.h>
#include<HeadData.h>

using namespace std;

int main()
{
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr{}, clientAddr{};
    int opt = 1;
    if (-1 == setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        cout << "setsockopt fail" << endl;
        exit(-1);
    }//设置端口复用
    int epfd = epoll_create(MAX_CONNECTIONS);
    epoll_event ev{}, events[MAX_CONNECTIONS];
    //ev是告诉内核需要监听什么事
    ev.data.fd = lfd;
    ev.events = EPOLLIN;
    //注册epoll事件 EPOLL_CTL_ADD代表注册新的fd到epfd中，这里是添加对lfd的监听
    if (-1 == epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev)) { 
        cout << "epoll_ctl fail" << endl;
        exit(-1);
    }
    //配置ip地址和端口号
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_family = AF_INET;
    //inet_pton(AF_INET, HOST, &serverAddr.sin_addr);//字符串转ip地址
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);//监听所有的网卡
    if (-1 == bind(lfd, (sockaddr *) &serverAddr, sizeof(serverAddr))) {//绑定地址
        cout << "bind fail" << endl;
        exit(-1);
    }
    if (-1 == listen(lfd, MAX_CONNECTIONS)) {//打开监听
        cout << "listen fail" << endl;
        exit(-1);
    }
    cout << "listening..." << endl;
    char ipAddress[BUFSIZ];
    Online online;
    while (true){
        //等待事件的产生，返回的是产生的事件数
        int nready = epoll_wait(epfd, events, MAX_CONNECTIONS, -1);
        if (nready < 0) {
            cout << "epoll_wait error" << endl;
            exit(-1);
        }
        cout << "收到" << nready << "个请求" << endl;
        for (int i = 0; i < nready; i++) {//遍历所有事件（请求）
            int fd = events[i].data.fd;
            if (fd == lfd) {//收到连接请求
                socklen_t len = sizeof(clientAddr);
                int cfd = accept(lfd, (sockaddr *) &clientAddr, &len);
                ev.data.fd = cfd;
                ev.events = EPOLLIN;
                epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev); //为新的用户注册新的fd
                inet_ntop(AF_INET, &clientAddr.sin_addr, ipAddress, sizeof(clientAddr)); //获取当前连接用户的ip地址到ipAddress
                //设置超时read
                struct timeval timeout = {1, 0}; //超时时间设置为1.0s
                setsockopt(cfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(struct timeval)); //套接字选项SO_RCVTIMEO： 用来设置socket接收数据的超时时间；
                cout << cfd << "收到连接请求" << endl;
            }
            else if (events[i].events & EPOLLIN) {//EPOLLIN表示对应的文件描述符可以读。如果监听到的事件里包含可读事件
                //这里每次都接收到完整的消息，包括协议头+消息内容（这里是广义上的消息，不只是聊天的内容）
                HeadData hd(fd);
                unsigned int protocolId = hd.getProtocolId();
                unsigned int account = hd.getAccount();
                unsigned int dataType = hd.getDataType();
                unsigned int dataLength = hd.getDataLength();
                cout << "protocol_head=" << protocolId << " " << account <<" "<< dataType <<" "<< dataLength <<" "<< endl;
                DataProcesser dp;
                switch (protocolId) {
                    case LOGIN:
                    {
                        string username = dp.readTextContent(fd, dataLength);
                        online.appendUser(fd, account, username);
                        string Loginmessage = username + " login";
                        cout << Loginmessage << endl;
                        dp.writeOnline_UserToAllUser(online.getAllReadFd(), account, online.getUserList());
                        dp.writeTextToAllUser(online.getAllReadFd(), account, Loginmessage, protocolId = LOGIN);
                    }
                        break;
                    case SEND:
                    {
                        //if (dataType)
                        string message = dp.readTextContent(fd, dataLength);
                        string baseMsg = online.getUserName(account) + "(" + to_string(account) + "):";
                        cout << baseMsg + message <<endl;
                        if (dataType == TEXT) {
                            dp.writeTextToAllUser(online.getAllReadFd(), account, baseMsg + message, protocolId = SEND);
                        }
                        cout << message << endl;
                    }
                        break;
                    case LOGOUT:
                    {
                        string username = online.getUserName(account);
                        string Logoutmessage = username + " logout";
                        cout << Logoutmessage << endl;
                        dp.writeTextToAllUser(online.getAllReadFd(), account, Logoutmessage, protocolId = LOGOUT);
                        //cout << "size" << online.getAllReadFd().size() << endl;
                        online.removeUser(fd, account);
                        dp.writeOnline_UserToAllUser(online.getAllReadFd(), account, online.getUserList());
                        ev.data.fd = fd;
                        ev.events = EPOLLIN;
                        epoll_ctl(epfd, EPOLL_CTL_DEL, fd, &ev);
                        close(fd);
                    }
                        break;

                }
            }
        }
    }
    return 0;
}