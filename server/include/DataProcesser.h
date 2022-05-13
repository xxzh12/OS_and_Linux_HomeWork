#include<common.h>

#ifndef TCP_BUFSIZE 
#define TCP_BUFSIZE 8192
#endif

using namespace std;

class DataProcesser {
    //协议号(1B)-账号(2B)-数据类型(1B)-数据长度(4B)-数据
private:
    char buffer[TCP_BUFSIZE];

    int checkSocketConnected(int sock);

public:
    DataProcesser();

    string readTextContent(int fd, unsigned int dataLength);

    //string readImageContent(int fd, unsigned int dataLength);

    void writeText(int fd, unsigned int account, string text, unsigned int protocolId);

    void writeImageSignal(int fd, unsigned int account, string text, unsigned int protocolId);

    //void writeImage(int fd, unsigned int account, const string &imagePath);

    //void writeMsg(int fd, string text);

    void writeTextToAllUser(const vector<int> &fds, unsigned int account, string text, unsigned int protocolId);

    void writeOnline_UserToAllUser(const vector<int> &fds, unsigned int account, string text, unsigned int protocolId = ONLINE_LIST);

    void sendImageSignalToAllUser(const vector<int> &fds, unsigned int account, string text, unsigned int protocolId = SEND);

    //void writeImageToAllUser(const vector<int> &fds, int account, const string &imagePath);

    //int getFileLength(const string &fileName);

};