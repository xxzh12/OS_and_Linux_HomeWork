// 程序：TcpClient
// 头文件：clientWindow.h

#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include "logwidget.h"
#include "mysqldb.h"

namespace Ui {
class ClientWindow;
}

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

    QTcpSocket* m_socket;      // 客户端套接字
    LogWidget *m_log;

    void connectToServer();    // 连接到服务器
    char* encode(char* msg, unsigned int protocolId, unsigned int account, unsigned int dataType, unsigned int dataLength);
    char* encodeElement(char* datahead, unsigned int data, unsigned int len);

private slots:
    void slot_readMessage();   // 处理接收服务器方发送的消息
    void slot_btnSendMsg();    // 点击发送按钮后，后发送消息
    void slot_sendloginmessage();

private:
    Ui::ClientWindow *ui;

};

#endif // CLIENTWINDOW_H
