#include "logwidget.h"
#include "ui_logwidget.h"
#include <QIcon>

LogWidget::LogWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogWidget)
{
    ui->setupUi(this);
    setWindowTitle("聊天室登录");
    this->setWindowIcon(QIcon("./Images/Chats.png"));
    //form_init();
    func_init();
    // 开启背景设置
    this->setAutoFillBackground(true);
    // 创建调色板对象
    QPalette p = this->palette();
    // 加载图片
    QPixmap pix(":/new/prefix1/Images/login.jpg");
    // 设置图片
    p.setBrush(QPalette::Window, QBrush(pix));
    this->setPalette(p);
}


LogWidget::~LogWidget()
{
    delete ui;
}

void LogWidget::func_init()
{
    // connect
    // 触发重置按钮的信号槽连接
    connect(ui->btn_clear,SIGNAL(clicked()),this,SLOT(btn_clear_clicked()));
    // 触发登录按钮的信号槽连接
    connect(ui->btn_log,SIGNAL(clicked()),this,SLOT(btn_log_clicked()));
    // 发出信号后关闭登录窗口的信号槽连接
    connect(this,SIGNAL(close_window()),this,SLOT(close()));


    //ui->edit_pw->setEchoMode(QLineEdit::Password);//输入的时候就显示圆点
}


// 清理输入栏
void LogWidget::btn_clear_clicked()
{
    ui->edit_pw->clear();
    ui->edit_name->clear();
}




void LogWidget::btn_log_clicked()
{
    m_username = ui->edit_name->text();
    m_password = ui->edit_pw->text();
        emit(login());
        //write_json();
        emit(close_window());
}
