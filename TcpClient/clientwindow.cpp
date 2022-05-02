// 程序：TcpClient
// 源文件：clientWindow.cpp

#include <bits/stdc++.h>
#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "common.h"

using namespace std;
//编码数据头中的元素信息
char* ClientWindow::encodeElement(char* datahead, unsigned int data, unsigned int len){
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
char* ClientWindow::encode(char* msg, unsigned int protocolId, unsigned int account, unsigned int dataType, unsigned int dataLength) {
    char* data = (char *)malloc(sizeof(msg)+8);
    char* datahead = data;
    datahead = encodeElement(datahead, protocolId, PROTOCOL_ID_SIZE);
    datahead = encodeElement(datahead, account, ACCOUNT_SIZE);
    datahead = encodeElement(datahead, dataType, DATA_TYPE_SIZE);
    datahead = encodeElement(datahead, dataLength, DATA_SIZE);
    printf("data packed\n");
    strcpy(datahead, msg);
    return data;
}

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    m_log = new LogWidget;
    m_log->show();
    // 注意，这个信号槽的作用就是激活主窗口的，我们已经让主窗口不可以自动打开，
    // 必须通过登录窗口中登录按钮发出的信号槽的信号才能打开
    connect(m_log,SIGNAL(login()),this,SLOT(show()));
    connect(m_log,SIGNAL(login()),this,SLOT(slot_sendloginmessage()));
    // do other things
}

void ClientWindow::slot_sendloginmessage()
{
    connectToServer();
    cout << m_log->m_username.length() << endl;
    std::string st = m_log->m_username.toStdString();
    char* name = (char *)st.c_str();
    char* str = encode(name, LOGIN, (unsigned int)m_log->m_password.toInt(), TEXT, (unsigned int)m_log->m_username.length());
    //cout << str << endl;
    //printf("%s\n",str);
    //QString message = QString::fromLocal8Bit(str, strlen(name)+8);
    //qDebug() << message + "end";
    m_socket->write(str, strlen(name)+8);
    //cout << message.toStdString().data() << endl;

}
void ClientWindow::connectToServer()
{
    m_socket = new QTcpSocket(this);

    //连接到服务器

    // 尝试连接到IP为"127.0.0.1" & 端口号为8888服务器
    // 如果想要实现局域网通信, 只需将第一个IP地址设置为“服务器”所在主机的IP地址即可
    // 如  m_socket->connectToHost("172.24.40.226", 19999);
    m_socket->connectToHost(QHostAddress::LocalHost, 8888);

    connect(m_socket,SIGNAL(readyRead()),this,SLOT(slot_readMessage()));   // 告诉socket, 要用slot_readMessage()去处理接收的消息.

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_btnSendMsg()));
}

void ClientWindow::slot_readMessage()   // 只会在socket接收到server消息时调用
{
    QString str = m_socket->readAll().data();


    ui->textBrowser->setText(ui->textBrowser->toPlainText() + "\n" + str);
}

void ClientWindow::slot_btnSendMsg()
{
    QString message = ui->lineEdit->text();
    std::string st = message.toStdString();
    char* MM = (char *)st.c_str();
    char* str = encode(MM, SEND, (unsigned int)m_log->m_password.toInt(), TEXT, (unsigned int)message.length());
    m_socket->write(str, strlen(MM)+8);    // Exception

    ui->lineEdit->clear();
}

ClientWindow::~ClientWindow()
{
    delete ui;
}
