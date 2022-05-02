// 程序：TcpClient
// 源文件：clientWindow.cpp

#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    m_log = new LogWidget;
    m_log->show();
    // 注意，这个信号槽的作用就是激活主窗口的，我们已经让主窗口不可以自动打开，
    // 必须通过登录窗口中登录按钮发出的信号槽的信号才能打开
    setAttribute(Qt::WA_DeleteOnClose);//设置关闭窗口是自动释放内存
    this->setStyleSheet(QString("background-color:#FFFFFF;"));//设置背景颜色为白色。和标题栏颜色一致。
    setWindowTitle("Qt简易聊天室");
    connect(m_log,SIGNAL(login()),this,SLOT(show()));
    connectToServer();
    // do other things
    connect(ui->fontCbx,&QFontComboBox::currentFontChanged,[=](const QFont &font){
        ui->lineEdit->setFontFamily(font.toString());
        ui->lineEdit->setFocus();
    });
    void (QComboBox:: * sizebtn)(const QString &text)=&QComboBox::currentTextChanged;
    connect(ui->sizeCbx,sizebtn,[=](const QString &text){
        ui->lineEdit->setFontPointSize(text.toDouble());
    });
}

void ClientWindow::connectToServer()
{
    m_socket = new QTcpSocket(this);

    //连接到服务器

    // 尝试连接到IP为"127.0.0.1" & 端口号为19999服务器
    // 如果想要实现局域网通信, 只需将第一个IP地址设置为“服务器”所在主机的IP地址即可
    // 如  m_socket->connectToHost("172.24.40.226", 19999);
    m_socket->connectToHost(QHostAddress::LocalHost, 19999);

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
    QString str = ui->lineEdit->text();

    m_socket->write(str.toStdString().data());    // Exception

    ui->lineEdit->clear();
}

ClientWindow::~ClientWindow()
{
    delete ui;
}
