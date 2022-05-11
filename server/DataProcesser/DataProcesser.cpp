#include<DataProcesser.h>
#include<DataEncoder.h>
#include<HeadData.h>

DataProcesser::DataProcesser() {

}

int DataProcesser::checkSocketConnected(int sock) {
    //用来判断TCP异常，即判断socket连接是否断开了
    if (sock <= 0)
        return 0;
    tcp_info info{};
    int len = sizeof(info);
    getsockopt(sock, IPPROTO_TCP, TCP_INFO, &info, (socklen_t *) &len);
    if (info.tcpi_state == TCP_ESTABLISHED) {
        return 1;
    } else {
        return 0;
    }
}

string DataProcesser::readTextContent(int fd, unsigned int dataLength) {
    unsigned int count = 0;
    //注意size一定不能是unsigned型, 因为后面read可能会返回-1，从而造成错误
    int size = 0;
    unsigned int buffSize = TCP_BUFSIZE;
    string content;
    while (true) { //反复读取文本信息
    /*
        if (checkSocketConnected(fd) == 0) {
            break;
        }
    */
        if((size = read(fd, buffer, min(buffSize, dataLength - count))) <= 0){
            break;
        }
        if (size > 0) {
            count += size;
            content += string(buffer, size);
        }
        if (count == dataLength) {
            break;
        }
    }
    return content;
}

void DataProcesser::writeText(int fd, unsigned int account, string text, unsigned int protocolId){
    DataEncoder de;
    string headStr = de.encode(protocolId, account, TEXT, text.length());
    /*if (checkSocketConnected(fd) == 0){
        cout << "connection lost 1" << endl;
        return;
    }*/
    send(fd, headStr.data(), headStr.length(), MSG_NOSIGNAL);
    //cout << headStr.data() << endl;
    read(fd, buffer, BASE_BUFFER_SIZE);
    int count = 0;
    unsigned int dataLength = text.length();
    char *data = (char *)text.data();
    unsigned int buffSize = TCP_BUFSIZE;
    HeadData hd;
    while (true) {
        /*if (checkSocketConnected(fd) == 0) {
            cout << "connection lost 2" << endl;
            break;
        }*/
        ssize_t size = send(fd, data, min(buffSize, dataLength - count), MSG_NOSIGNAL);
        count += size;
        data = data + size;
        //接收客户端的确认信息
        unsigned int splitDataLength = 0;
        while (true) {
            if (checkSocketConnected(fd) == 0) {
                break;
            }
            read(fd, buffer, BASE_BUFFER_SIZE);
            hd.parse(buffer);
            splitDataLength += hd.getDataLength();
            if (splitDataLength == size) {
                break;
            }
        }
        if (count == dataLength) {
            break;
        }
    }
}

void DataProcesser::writeTextToAllUser(const vector<int> &fds, unsigned int account, string text, unsigned int protocolId) {
    for (auto &fd : fds) {
        writeText(fd, account, text, protocolId);
    }
}

void DataProcesser::writeOnline_UserToAllUser(const vector<int> &fds, unsigned int account, string text, unsigned int protocolId) {
    for (auto &fd : fds) {
        writeText(fd, account, text, protocolId);
    }
}