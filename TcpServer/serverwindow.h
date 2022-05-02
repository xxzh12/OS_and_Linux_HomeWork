// 程序：TcpClient
// 头文件：serverWindow.h

#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>

namespace Ui {
class ServerWindow;
}

class ServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerWindow(QWidget *parent = 0);
    ~ServerWindow();

    QTcpServer* m_server;

    QList<QTcpSocket*> m_sockets;   // 连接到server的所有客户.  链表方式, 在服务器端的一个备份(客户端的socket)

    void startServer();    // 启动一个server
public slots:
    void slot_newConnection();    //  对应客户端的 connectToHost();

    void slot_readMessage();   // 每一个socket绑定


private:
    Ui::ServerWindow *ui;
};

#endif // SERVERWINDOW_H
