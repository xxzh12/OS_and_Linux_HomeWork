#include "widget.h"
#include <QApplication>
#include "mysqldb.h"
#include <QString>
#include <QChar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

QSqlDatabase db;
MYsqldb x;
   x.initial(db);

    QString b="trial1";
    x.createtb(db,b);
    QString strBuffer;
    QDateTime time;
    //x.cleartb(db,b);
    time = QDateTime::currentDateTime();

    strBuffer = time.toString("yyyy-MM-dd hh:mm:ss");
QString unm="sleipnir";
int type=1;
QString txt="hello world!";
x.inportms(db,b,unm,strBuffer,type,txt);
/*QStringList sql;
sql=x.exportdatallms(db,b);
qDebug()<<sql;
sql=x.exportdataulms(db,b,1);
qDebug()<<sql;
*/
QString im=qApp->applicationDirPath()+"/1.png";
//qDebug()<<im;
QFile file(im);
if(!file.open(QIODevice::ReadOnly))
{
qDebug()<<"open failed";
 return a.exec();
}
QByteArray data = file.readAll();
if(data.isEmpty())
{
qDebug()<<"data is empty";
}
x.inportpt(db,b,unm,strBuffer,2,data);
file.close();

QStringList sql;
QString ms,tp;
sql=x.exportdataulms(db,b,2);
int i,j=0;
for(i=1;i<sql.count();i=i+4)
{
for(j=0;j<3;j++)
{
    if(j==2){
        tp=sql.first();type=tp.toInt();
        if(type==1){qDebug()<<sql.first();sql.removeFirst();qDebug()<<sql.first();}
        else {
          qDebug()<<sql.first();sql.removeFirst();
          ms=sql.first();
          data=ms.toLocal8Bit();
        }
    }
    else {
        qDebug()<<sql.first();
        sql.removeFirst();
    }
}

}

QString dl=qApp->applicationDirPath()+"/2.png";
QFile fl(dl);
if(!fl.open(QIODevice::WriteOnly))
{qDebug()<<"open failed";return a.exec();}
else {
    fl.write(data);
    fl.close();
}


    x.close(db);
    return a.exec();
}
