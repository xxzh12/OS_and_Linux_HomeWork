// 程序：TcpClient
// 源文件：serverWindow.cpp

#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);

    startServer();
}

void ServerWindow::startServer()
{
    m_server = new QTcpServer(this);

    m_server->listen(QHostAddress::Any, 19999);

    connect(m_server,SIGNAL(newConnection()),this,SLOT(slot_newConnection()));  //
}

void ServerWindow::slot_newConnection()
{
    // 把新加入的socket放入链表中
    QTcpSocket* socket = m_server->nextPendingConnection();

    m_sockets.push_back(socket);

    connect(socket,SIGNAL(readyRead()),this,SLOT(slot_readMessage()));
}

// 每一个socket处理收到消息的函数
void ServerWindow::slot_readMessage()
{
    QTcpSocket* socket = (QTcpSocket*)QObject::sender();  // 获得是哪个socket收到了消息

    QString str = socket->readAll().data();

    for(int i=0; i<m_sockets.size(); i++)
    {
        m_sockets[i]->write(str.toStdString().data());
    }
}

ServerWindow::~ServerWindow()
{
    delete ui;
}
