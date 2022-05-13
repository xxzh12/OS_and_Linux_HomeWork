#ifndef MYSQL_H
#define MYSQL_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QCoreApplication>
#include <QMessageBox>
#include <QString>
#include <QDateTime>
#include <QStringList>
#include <QStringListIterator>
#include <iostream>
#include <QByteArray>
#include <QFile>
#include <QDir>
#include <QSqlDatabase>
#include <QImage>
#include <QImageWriter>
#include <QPixmap>

#define TXT 1
#define JPG 2
#define PNG 3
#define MP3 4

class MYsqldb
{
public:
    MYsqldb();
    int initial(QSqlDatabase db);
    void close (QSqlDatabase db);
    int createtb (QSqlDatabase db,QString tbname);
    int cleartb (QSqlDatabase db,QString tbname);
    int importms (QSqlDatabase db, QString tbname,QString username,QString tm ,int type,QString txt);
    void IntegratedSendMsg(QString UserName, QString message);
    QStringList IntegratedGetMsg();
    int importfl (QSqlDatabase db,QString tbname,QString username,QString tm,int type,QString im);
    QStringList exportdatallms(QSqlDatabase db,QString tbname);
    QStringList exportdataulms (QSqlDatabase db,QString tbname,int num);

    ~MYsqldb();
};



#endif // MYSQL_H
