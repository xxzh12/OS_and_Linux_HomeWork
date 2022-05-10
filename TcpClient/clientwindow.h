// 程序：TcpClient
// 头文件：clientWindow.h

#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#define BUF_SIZE 8192

#include "common.h"
#include "readclient.h"
#include "logwidget.h"

namespace Ui {
class ClientWindow;
}

using namespace std;

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    ReadClient *rd;

    explicit ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

    QTcpSocket *m_socket;      // 客户端套接字
    char buffer[BUF_SIZE];
    unsigned int protocolId;
    unsigned int account;
    unsigned int dataType;
    unsigned int dataLength;
    const string ACK_PACKET = acknowledge.toStdString();

    void connectToServer();    // 连接到服务器
    void read_HeadData();   //to parse the datahead
    char* encodeElement(char* datahead, unsigned int data, unsigned int len);
    char* encode(char* msg, unsigned int protocolId, unsigned int account, unsigned int dataType, unsigned int dataLength);

private slots:
    void slot_readMessage();   // 处理接收服务器方发送的消息
    void slot_btnSendMsg();    // 点击发送按钮后，后发送消息
    void slot_sendloginmessage();

private:
    Ui::ClientWindow *ui;
    LogWidget *m_log;
};

#endif // CLIENTWINDOW_H
