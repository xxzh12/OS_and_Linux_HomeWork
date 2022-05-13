#ifndef READCLIENT_H
#define READCLIENT_H

#include "dataparser.h"
#include "common.h"

char* encodeElement(char* datahead, unsigned int data, unsigned int len);
char* encode(char* msg, unsigned int protocolId, unsigned int account, unsigned int dataType, unsigned int dataLength);

const QString acknowledge = QString::fromLocal8Bit(encode(nullptr,ACK,0,0,0), 8);
using namespace std;
class ReadClient: public QObject
{
   Q_OBJECT
private:
    // static ReadClient *readClient;
    // string imagePath;

    // string notice = "";
public:
    ReadClient();
    string content = "";
    unsigned int protocolId;
    unsigned int account;
    unsigned int dataType;
    unsigned int dataLength;
    char buffer[TCP_BUFSIZ];

    const string ACK_PACKET = acknowledge.toStdString();

    QTcpSocket* m_socket;

    // static ReadClient * getTcpSocketClient();

    void read_HeadData();

    bool readData();

    void readTextContent();

    // void readImageContent();

    string getTextContent();

    //string getNoticeContent();

    //string getImagePath();

    ~ReadClient();
signals:
    void textDisplayAble();
    //void imageDisplayAble();
    //void noticeDisplayAble();
    void onlineDisplayAble();
    void loginDisplayAble();
    void logoutDisplayAble();
    void imageDownload();
};

#endif // READCLIENT_H
