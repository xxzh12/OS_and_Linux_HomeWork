// 程序：TcpClient
// 源文件：clientWindow.cpp

#include <bits/stdc++.h>
#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "common.h"
#include <QFont>
#include <QColorDialog>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QDataStream>
#include <QTextStream>
#include <sys/stat.h>
#include <QThread>

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
    char* data = (char *)malloc(dataLength+9);
    char* datahead = data;
    datahead = encodeElement(datahead, protocolId, PROTOCOL_ID_SIZE);
    datahead = encodeElement(datahead, account, ACCOUNT_SIZE);
    datahead = encodeElement(datahead, dataType, DATA_TYPE_SIZE);
    datahead = encodeElement(datahead, dataLength, DATA_SIZE);
    printf("data packed\n");
    if (dataLength!=0) strcpy(datahead, msg);
    return data;
}



ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    m_log = new LogWidget;
    m_log->show();
    // 注意，这个信号槽的作用就是激活主窗口的，我们已经让主窗口不可以自动打开，
    // 必须通过登录窗口中登录按钮发出的信号槽的信号才能打开
    connect(m_log,SIGNAL(login()),this,SLOT(show()));
    connect(m_log,SIGNAL(login()),this,SLOT(slot_sendloginmessage()));
    // do SY things
    setAttribute(Qt::WA_DeleteOnClose);//设置关闭窗口是自动释放内存
    //this->setStyleSheet(QString("background-color:#FFFFF;"));//设置背景颜色为白色。和标题栏颜色一致。
    setWindowTitle("Qt简易聊天室");
    // do other things
    connect(ui->fontCbx,&QFontComboBox::currentFontChanged,[=](const QFont &font){
        ui->msgTextEdit->setFontFamily(font.toString());
        ui->msgTextEdit->setFocus();
    });
    void (QComboBox:: * sizebtn)(const QString &text)=&QComboBox::currentTextChanged;
    connect(ui->sizeCbx,sizebtn,[=](const QString &text){
        ui->msgTextEdit->setFontPointSize(text.toDouble());
        ui->msgTextEdit->setFocus();
    });
    connect(ui->boldTBtn,&QToolButton::clicked,[=](bool checked){
        if(checked)
        {
            ui->msgTextEdit->setFontWeight(QFont::Bold);
        }
        else{
            ui->msgTextEdit->setFontWeight(QFont::Normal);
        }
    });
    connect(ui->italicTbtn,&QToolButton::clicked,[=](bool checked){
        ui->msgTextEdit->setFontItalic(checked);
        ui->msgTextEdit->setFocus();
    });
    connect(ui->underlineTBtn,&QToolButton::clicked,[=](bool checked){
        ui->msgTextEdit->setFontUnderline(checked);
        ui->msgTextEdit->setFocus();
    });
    connect(ui->clearTBtn,&QToolButton::clicked,[=](){
        ui->textBrowser->clear();
    });
    connect(ui->colorTBtn,&QToolButton::clicked,[=](){
        QColor color=QColorDialog::getColor(color,this);
        ui->msgTextEdit->setTextColor(color);
    });
    connect(ui->exitButton,&QPushButton::clicked,[=](){
        //cout << "www" << endl;
        char* str = encode(NULL, LOGOUT, (unsigned int)m_log->m_password.toInt(), TEXT, 0);
        m_socket->write(str, 8);    // Exception
        //cout << "sss" << endl;
        m_socket->waitForBytesWritten();
        this->close();
    });
}

void ClientWindow::slot_sendloginmessage()
{
    connectToServer();
    //cout << m_log->m_username.length() << endl;
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

    // 尝试连接到IP为"127.0.0.1" & 端口号为8888服务器
    // 如果想要实现局域网通信, 只需将第一个IP地址设置为“服务器”所在主机的IP地址即可
    // 如  m_socket->connectToHost("172.24.40.226", 19999);
    //m_socket->connectToHost(QHostAddress::LocalHost, 8888);
    m_socket->connectToHost("192.168.43.231", 8888);
    connect(m_socket,SIGNAL(readyRead()),this,SLOT(slot_readMessage()));   // 告诉socket, 要用slot_readMessage()去处理接收的消息.

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_btnSendMsg()));
}

void ClientWindow::slot_readMessage()   // 只会在socket接收到server消息时调用
{
    QString str = m_socket->readAll().data();
    qDebug() << str;
    ui->textBrowser->setText(ui->textBrowser->toHtml() + str+ '\n');
    //qDebug() << str ;
    //unsigned int len = m_log->m_username.length() + 1 + m_log->m_password.length() + 1 + 1;
    //QString title = str.mid(0, len);
    //QString message = str.mid(len, str.length()-len);
    //ui->textBrowser->setText(ui->textBrowser->toPlainText() + str + '\n');
    //qDebug() << str + len;
    //cout << len << endl;
    //ui->textBrowser->insertPlainText(title);
    //ui->textBrowser->setText(ui->textBrowser->toPlainText() + title);
    //ui->textBrowser->moveCursor(QTextCursor::End);
    //ui->textBrowser->setText(ui->textBrowser->toHtml() + message+ '\n');
    //ui->textBrowser->moveCursor(QTextCursor::End);
}

void ClientWindow::slot_btnSendMsg()
{
    //QString message = ui->msgTextEdit->toPlainText() ;
    QString message = ui->msgTextEdit->toHtml() ;
    std::string st = message.toStdString();
    char* MM = (char *)st.c_str();
    char* str = encode(MM, SEND, (unsigned int)m_log->m_password.toInt(), TEXT, (unsigned int)message.length());
    m_socket->write(str, strlen(MM)+8);    // Exception

    ui->msgTextEdit->clear();
    free(str);
}

ClientWindow::~ClientWindow()
{
    delete ui;
}
