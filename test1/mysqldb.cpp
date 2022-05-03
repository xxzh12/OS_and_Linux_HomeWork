#include "mysqldb.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QCoreApplication>
#include <QMessageBox>

int MYsqldb::initial(QSqlDatabase db)
{

     db = QSqlDatabase::addDatabase("QMYSQL");
           db.setHostName("192.168.59.128");
           db.setPort(3306);
           db.setUserName("sleipnir");
           db.setPassword("123456");
           db.setDatabaseName("test");
           QString s=db.connectionName();
           if(db.open())
             {
                 qDebug() << "sucess";
                 return 1;

             }
             else
             {
                  qDebug() << "failed";
                  QMessageBox::critical(0,QObject::tr("Database Error"),db.lastError().text());
                  return 0;

             }
}

void MYsqldb::close(QSqlDatabase db)
{

    db.close();
}

int MYsqldb::createtb(QSqlDatabase db,QString tbname)
{
    QSqlQuery query;
    QString sql=QString("create table %1 (ID INT PRIMARY KEY AUTO_INCREMENT,username varchar(255),dt_value datetime,type TINYINT,text_value TEXT );").arg(tbname);
    query.prepare(sql);
    if(!query.exec(sql)){
                qDebug()<<"query error :"<<query.lastError();
                return 0;
            }
            else{
                qDebug()<<"creat table successfully!";
                return 1;
            }



}

int MYsqldb::cleartb(QSqlDatabase db,QString tbname)
{
 QSqlQuery query;
 QString sql=QString("drop table %1;").arg(tbname);
 if(!query.exec(sql))
 {qDebug()<<"query error :" <<query.lastError();
     return 0;
 }
 else {
     qDebug()<<"delete table successfully!";
     return 1;
 }

}

int MYsqldb::inprotdata(QSqlDatabase db, QString tbname,QString username,QString tm ,int type,QString txt)
{

    QSqlQuery query;
QString sql=QString("insert into %1(username,dt_value,type,text_value) values('%2','%3','%4','%5')").arg(tbname).arg(username).arg(tm).arg(type).arg(txt);
if(!query.exec(sql))
{qDebug()<<"query error :" <<query.lastError();
    return 0;
}
else {
    qDebug()<<"insert data successfully!";
    return 1;
}
}

QStringList MYsqldb::exprotdatall(QSqlDatabase db, QString tbname)
{
   QSqlQuery query;
   QStringList sqlist;
   QString sl=QString("select * from %1").arg(tbname);
   if(!query.exec(sl))
   {qDebug()<<"query error :" <<query.lastError();
   }
   else{
   while(query.next()){

   sqlist<<query.value(1).toString()<<query.value(2).toString()<<query.value(3).toString()<<query.value(4).toString();
   }

  return sqlist;
   }
}

QStringList MYsqldb::exportdataul(QSqlDatabase db, QString tbname, int num)
{

    QSqlQuery query;
    int i=1;
    QStringList sqlist;
    QString sl=QString("select * from %1").arg(tbname);
    if(!query.exec(sl))
    {qDebug()<<"query error :" <<query.lastError();
    }
    else{
    while(query.next()){ i++;}
    qDebug()<<QString::number(i);
    int j=i-num+1;
    query.seek(j);
    while(query.next()){

    sqlist<<query.value(1).toString()<<query.value(2).toString()<<query.value(3).toString()<<query.value(4).toString();
    }

   return sqlist;
    }
}
