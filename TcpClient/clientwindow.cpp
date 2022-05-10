// 程序：TcpClient
// 源文件：clientWindow.cpp

#include "clientwindow.h"
#include "ui_clientwindow.h"

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
    rd = new ReadClient;
    // 注意，这个信号槽的作用就是激活主窗口的，我们已经让主窗口不可以自动打开，
    // 必须通过登录窗口中登录按钮发出的信号槽的信号才能打开
    connect(m_log,SIGNAL(login()),this,SLOT(show()));
    connect(m_log,SIGNAL(login()),this,SLOT(slot_sendloginmessage()));
    // do SY things
    setAttribute(Qt::WA_DeleteOnClose);//设置关闭窗口是自动释放内存
    //this->setStyleSheet(QString("background-color:#FFFFF;"));//设置背景颜色为白色。和标题栏颜色一致。
    //ui->Plabel->setPixmap(QPixmap("./Images/Naruto.jpg"));
    //setAttribute基本上控件都可以用
    ui->textBrowser->setAttribute(Qt::WA_TranslucentBackground,true);
    //窗体设置透明度
    //setWindowOpacity(0.7);

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
    connect(ui->FileTBtn,&QToolButton::clicked,[=](){
        QString FileName;
        FileName=QFileDialog::getOpenFileName(this, tr("文件选取"), "", tr("Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)"));
        qDebug() << FileName;
        MYsqldb DataBase;
        QSqlDatabase db;
        QDateTime time;
        QString strBuffer;
        time = QDateTime::currentDateTime();
        strBuffer = time.toString("yyyy-MM-dd hh:mm:ss");
        DataBase.inportpt(db,"trial1",m_log->m_username,strBuffer,2,FileName);
    });
    connect(ui->exitButton,&QPushButton::clicked,[=](){
        //cout << "www" << endl;
        char* str = encode(NULL, LOGOUT, (unsigned int)m_log->m_password.toInt(), TEXT, 0);
        m_socket->write(str, 8);    // Exception
        MYsqldb DataBase;
        QString LogOutMsg;
        LogOutMsg = QString::fromLocal8Bit(str, 8);
        DataBase.IntegratedSendMsg(m_log->m_username, LogOutMsg);
        //cout << "sss" << endl;
        m_socket->waitForBytesWritten();
        this->close();
    });
    // send message signal
    // display message fuction

    connect(rd, &ReadClient::textDisplayAble,[=](){
       QString content = QString::fromStdString(rd->content);
       // ui->textBrowser->setText(ui->textBrowser->toPlainText() + "\n" + content);

       QString str = content;
       QString strBuffer;
       QDateTime time;
       time = QDateTime::currentDateTime();
       strBuffer = time.toString("yyyy-MM-dd hh:mm:ss dddd");
       //qDebug() << str;
       ui->textBrowser->setText(ui->textBrowser->toPlainText() +'\n'+strBuffer);
       ui->textBrowser->setText(ui->textBrowser->toPlainText() + str+ '\n');
    });
}

void ClientWindow::slot_sendloginmessage()
{
    MYsqldb DataBase;
    QString EncodedMessage;
    QStringList HistoryMsgList;
    int ListLength;

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

    HistoryMsgList = DataBase.IntegratedGetMsg();
    ListLength = HistoryMsgList.count();
    int i;
    for(i = 0; i < ListLength / SQL_PERIOD; i++){
        ui->textBrowser->setText(ui->textBrowser->toPlainText() + HistoryMsgList.at(4*i+USER_COUNT) + ' ');
        ui->textBrowser->setText(ui->textBrowser->toPlainText() + HistoryMsgList.at(4*i+TIME_COUNT)+ ' ');
        //ui->textBrowser->setText(ui->textBrowser->toPlainText() + HistoryMsgList.at(4*i+TYPE_COUNT)+ ' ');
        ui->textBrowser->setText(ui->textBrowser->toPlainText() + HistoryMsgList.at(4*i+MESSAGE_COUNT) +'\n');
    }

    EncodedMessage = QString::fromLocal8Bit(str, m_log->m_username.length()+8);
    DataBase.IntegratedSendMsg(m_log->m_username, EncodedMessage);
    //qDebug() << "Send Encoded Login Message" << EncodedMessage;

}



void ClientWindow::connectToServer()
{
    m_socket = new QTcpSocket(this);

    // 尝试连接到IP为"127.0.0.1" & 端口号为8888服务器
    // 如果想要实现局域网通信, 只需将第一个IP地址设置为“服务器”所在主机的IP地址即可
    // 如  m_socket->connectToHost("172.24.40.226", 19999);
    //m_socket->connectToHost(QHostAddress::LocalHost, 8888);
    // qDebug() << "192" ;
    m_socket->connectToHost("192.168.43.231", 8888);
    // qDebug() << "168" ;
    connect(m_socket,SIGNAL(readyRead()),this,SLOT(slot_readMessage()));   // 告诉socket, 要用slot_readMessage()去处理接收的消息.

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_btnSendMsg()));
}

void ClientWindow::slot_readMessage()   // 只会在socket接收到server消息时调用
{
    rd->m_socket = m_socket;
    rd->readData();
}

void ClientWindow::slot_btnSendMsg()
{
    MYsqldb DataBase;
    QString message = ui->msgTextEdit->toPlainText();
    //QString message = ui->msgTextEdit->toHtml() ;
    std::string st = message.toStdString();
    char* MM = (char *)st.c_str();
    char* str = encode(MM, SEND, (unsigned int)m_log->m_password.toInt(), TEXT, (unsigned int)message.length());
    m_socket->write(str, strlen(MM)+8);    // Exception
    // send encoded message("message") to SQL database
    message = QString::fromLocal8Bit(str, message.length()+8);
    DataBase.IntegratedSendMsg(m_log->m_username, message);
    qDebug() << message;
    ui->msgTextEdit->clear();
    free(str);
}

ClientWindow::~ClientWindow()
{
    delete ui;
}
