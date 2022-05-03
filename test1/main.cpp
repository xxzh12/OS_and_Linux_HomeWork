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
    //x.createtb(db,b);
    QString strBuffer;
    QDateTime time;

    time = QDateTime::currentDateTime();

    strBuffer = time.toString("yyyy-MM-dd hh:mm:ss");
QString unm="sleipnir";
int type=1;
QString txt="hello world!";
x.inprotdata(db,b,unm,strBuffer,type,txt);
QStringList sql;
sql=x.exprotdatall(db,b);
qDebug()<<sql;
sql=x.exportdataul(db,b,5);
qDebug()<<sql;
    //x.cleartb(db,b);
    x.close(db);
    return a.exec();
}
