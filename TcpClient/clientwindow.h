// 程序：TcpClient
// 头文件：clientWindow.h

#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include "logwidget.h"

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

    void connectToServer();    // 连接到服务器

private slots:
    void slot_readMessage();   // 处理接收服务器方发送的消息
    void slot_btnSendMsg();    // 点击发送按钮后，后发送消息


private:
    Ui::ClientWindow *ui;
    LogWidget *m_log;
};

#endif // CLIENTWINDOW_H
