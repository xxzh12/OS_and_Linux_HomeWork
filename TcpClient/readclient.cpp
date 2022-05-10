#include "readclient.h"


char* encodeElement(char* datahead, unsigned int data, unsigned int len){
    char* c = datahead + len - 1;
    for(int i = len;i>0;i--){
        *c = (char)(data & 0xff);
        c--;
        data >>=8;
    }
    datahead = datahead + len;
    return datahead;
}

//编码数据包
char* encode(char* msg, unsigned int protocolId, unsigned int account, unsigned int dataType, unsigned int dataLength) {
    char* data = (char *)malloc(sizeof(msg)+8);
    char* datahead = data;
    datahead = encodeElement(datahead, protocolId, PROTOCOL_ID_SIZE);
    datahead = encodeElement(datahead, account, ACCOUNT_SIZE);
    datahead = encodeElement(datahead, dataType, DATA_TYPE_SIZE);
    datahead = encodeElement(datahead, dataLength, DATA_SIZE);
    printf("data packed\n");
    if (dataLength!=0 && msg!=nullptr) strcpy(datahead, msg);
    return data;
}

void ReadClient::read_HeadData() //
{
    int size = m_socket->read(buffer, BASE_BUFFER_SIZE);
    DataParser parser(buffer);
    parser.baseParse();
    protocolId = parser.getProtocolId();
    account = parser.getAccount();
    dataType = parser.getDataType();
    dataLength = parser.getDataLength();
}

bool ReadClient::readData()
{
    read_HeadData();
    m_socket->write(ACK_PACKET.data(), ACK_PACKET.length());
    content = "";
    qDebug() << "----------数据长度-----------" << dataLength;
    if(dataType == TEXT){
        readTextContent();
        return true;
    }
    /*else if(dataType == IMAGE){
        readImageContent();
        return true;
    }*/
    return false;
}


void ReadClient::readTextContent()
{
    while(m_socket->waitForReadyRead(-1)){
        unsigned int size = 0;
        qDebug() << "-------readTextContent需要读取的字节数---------" << dataLength;
        unsigned int splitDataLength = m_socket->bytesAvailable();
        unsigned int bufsize = TCP_BUFSIZ;
        while(dataLength != 0 && m_socket->bytesAvailable()){
            qDebug() << "-----------------可读数据------------" << m_socket->bytesAvailable();
            size = m_socket->read(buffer, min(bufsize, dataLength));
            dataLength -= size;
            qDebug() << "-------readTextContent剩余读取的字节数---------" << dataLength;
            content = content + string(buffer, size);
        }
//        tcpClient.write(ACK_PACKET.data(), ACK_PACKET.length());
        string SPLIT_ACK_PACKET = encode(nullptr,ACK,account,TEXT,splitDataLength);
        m_socket->write(SPLIT_ACK_PACKET.data(), SPLIT_ACK_PACKET.length());
        if(dataLength == 0){
            switch(protocolId){
                case SEND: emit textDisplayAble();break;
            // case NOTICE:notice = content; emit noticeDisplayAble();break;
            // case ONLINELIST: emit onlineDisplayAble();break;
            }
            break;
        }
        qDebug() << "-----------readTextContent剩余读取的字节数------" << dataLength;
    }
    qDebug() << "读取完毕.......";
}

/*
void ReadClient::readImageContent()
{

}
*/
string ReadClient::getTextContent()
{
    return content;
}

/*
string ReadClient::getNoticeContent()
{

}

string ReadClient::getImagePath()
{

}*/

ReadClient::~ReadClient()
{

}
