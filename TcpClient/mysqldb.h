#ifndef MYSQL_H
#define MYSQL_H
#include "common.h"

class MYsqldb
{
public:
    int initial(QSqlDatabase db);
    void close (QSqlDatabase db);
    int createtb (QSqlDatabase db,QString tbname);
    int cleartb (QSqlDatabase db,QString tbname);
    int importdata (QSqlDatabase db, QString tbname,QString username,QString tm ,int type ,QString txt);
    QStringList exportdatall(QSqlDatabase db,QString tbname);
    QStringList exportdataul(QSqlDatabase db,QString tbname,int num);


};



#endif // MYSQL_H
