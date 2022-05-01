#include<DataProcesser.h>

DataProcesser::DataProcesser() {

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

void DataProcesser::writeText(int fd, string text){
    int count = 0;
    unsigned int dataLength = text.length();
    const char *data = text.data();
    unsigned int buffSize = TCP_BUFSIZE;
    while (true) {
        ssize_t size = send(fd, data, min(buffSize, dataLength - count), MSG_NOSIGNAL);
        count += size;
        data = data + size;
        if (count == dataLength) {
            break;
        }
    }
}

void DataProcesser::writeTextToAllUser(const vector<int> &fds, string text) {
    for (auto &fd : fds) {
        writeText(fd, text);
    }
}