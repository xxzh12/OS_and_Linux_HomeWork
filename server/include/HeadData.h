#pragma once
#include<common.h>

using namespace std;

class HeadData {
    //协议号(1B)-账号(2B)-数据类型(1B)-数据长度(4B)-数据
private:
    char buffer[BASE_BUFFER_SIZE]; //八个字节的协议头
    const char *bp; //bp是当前解析的指针位置，这部分考虑改成struct结构体
    unsigned int protocolId;
    unsigned int account;
    unsigned int dataType;
    unsigned int dataLength;

    bool baseParse();

    unsigned int parseInt(int len);

public:
    HeadData(int fd);

    HeadData();

    bool parse(const char *buffer);

    unsigned int getProtocolId();

    unsigned int getAccount();

    unsigned int getDataType();

    unsigned int getDataLength();

};