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

class MYsqldb
{
public:
  int initial(QSqlDatabase db);
  void close (QSqlDatabase db);
  int createtb (QSqlDatabase db,QString tbname);
  int cleartb (QSqlDatabase db,QString tbname);
  int inportms (QSqlDatabase db, QString tbname,QString username,QString tm ,int type,QString txt);
  int inportpt (QSqlDatabase db,QString tbname,QString username,QString tm,int type,QByteArray pt);
QStringList exportdatallms(QSqlDatabase db,QString tbname);
  QStringList exportdataulms (QSqlDatabase db,QString tbname,int num);


};



#endif // MYSQL_H
