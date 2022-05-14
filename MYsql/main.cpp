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
//声明变量
    QSqlDatabase db;
    MYsqldb x;
    QString b="trial1";
    QString strBuffer;
    QDateTime time;
    time = QDateTime::currentDateTime();
    strBuffer = time.toString("yyyy-MM-dd hh:mm:ss");
    QString unm="sleipnir";
    //int type=1;
    QString txt="hello world!";

//初始化
    x.initial(db);
    //x.createtb(db,b);
    //x.cleartb(db,b);
//导入文字信息
    x.inportms(db,b,unm,strBuffer,TXT,txt);
/*QStringList sql;
sql=x.exportdatallms(db,b);
qDebug()<<sql;
sql=x.exportdataulms(db,b,1);
qDebug()<<sql;

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

QByteArray data;
QString dl=qApp->applicationDirPath()+"/cache";
QDir dr(dl);
if(!dr.exists()){
    bool ismkdir=QDir().mkdir(dl);
    if(!ismkdir)
        {
        qDebug()<<"mkdir wrong!";
        }
    }
*/
    //导入图片
    //QString im=qApp->applicationDirPath()+"/test.jpg";
    //qDebug()<<im;

    //x.inportpt(db,b,unm,strBuffer,2,im);


    //导入音频
    QString vd=qApp->applicationDirPath()+"/1.mp3";
    qDebug()<<vd;
    x.inportpt(db,b,unm,strBuffer,MP3,vd);


    //导出图片
    QByteArray data;
    QString dl=qApp->applicationDirPath()+"/cache";
    QDir dr(dl);
    if(!dr.exists()){
        bool ismkdir=QDir().mkdir(dl);
        if(!ismkdir)
            {
            qDebug()<<"mkdir wrong!";
            }
        }

    QStringList sql;
    QString ms,tp;
    sql=x.exportdataulms(db,b,3);
    qDebug()<<"开始循环导出";
    qDebug()<<sql;
    /*int i,j=0;
    for(i=1;i<sql.count();i=i+4)
    {
    for(j=0;j<=3;j++)
    {
        if (j==1) {
           qDebug()<<sql.first();
           dl=dl+"/";dl=dl+sql.first();
           sql.removeFirst();
       }
        else if(j==2){
            tp=sql.first();
            type=tp.toInt();
            if(type==1){qDebug()<<sql.first();sql.removeFirst();}
            else if(type==2){
             qDebug()<<sql.first();sql.removeFirst();
             ms=sql.first();j=4;sql.removeFirst();
             data=ms.toLocal8Bit();
              dl=dl+".jpg";
              qDebug()<<dl;
              QFile fl(dl);
              if(!fl.open(QIODevice::WriteOnly))
              {qDebug()<<"open failed";return a.exec();}
              else {
                  fl.write(data);
                  fl.close();
              }
              sql.removeFirst();
            }
            else {
              qDebug()<<sql.first();sql.removeFirst();
            }
        }

        else {
            qDebug()<<sql.first();
            sql.removeFirst();
        }
    }

    }
    */

    //sql=x.exportdataulms(db,b,2);
    //qDebug()<<sql;
    int i,j=0;
    for(i=1;i<sql.count();i=i+4)
    {
    for(j=0;j<3;j++)
    {
//        if(j==2){
//            tp=sql.first();type=tp.toInt();
//            if(type==1){qDebug()<<sql.first();sql.removeFirst();qDebug()<<sql.first();}
//            else {
//              qDebug()<<sql.first();sql.removeFirst();
//              ms=sql.first();
//              data=ms.toLocal8Bit();
//            }
//        }
//        else {
//            qDebug()<<sql.first();
//            sql.removeFirst();
//        }
        if(j==2){
            sql.first()=("yyyy-MM-dd hh:mm:ss");
            qDebug()<<sql.first();
            sql.removeFirst();
        }
        qDebug()<<sql.first();
        sql.removeFirst();
    }

    }

    //QString dl=qApp->applicationDirPath()+"/3.jpg";
//    dl=dl+"/3.jpg";
//    QFile fl(dl);
//    if(!fl.open(QIODevice::WriteOnly))
//    {qDebug()<<"open failed";return a.exec();}
//    else {
//        fl.write(data);
//        fl.close();
//    }



    x.close(db);
    return a.exec();
}
