#ifndef LOGWIDGET_H
#define LOGWIDGET_H


#include <QWidget>
#include <QMessageBox>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include <QByteArray>


namespace Ui {
class LogWidget;
}


class LogWidget : public QWidget
{
    Q_OBJECT


public:
    explicit LogWidget(QWidget *parent = nullptr);
    ~LogWidget();


    void form_init(); //格式初始化
    void func_init(); //功能初始化
    void read_json();
    void write_json();
    void message_init(QString flag1,QString flag2);


signals:
    void login(); //登录主界面信号
    void close_window();  //关闭登录界面信号


public slots:
    void btn_clear_clicked();  //重置按钮按下后触发的事件
    void btn_log_clicked();  //登录按钮按下后触发的事件


private:
    Ui::LogWidget *ui;


    QString m_username;
    QString m_password;


};
#endif // LOGWIDGET_H
