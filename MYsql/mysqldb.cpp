#include "mysqldb.h"


int MYsqldb::initial(QSqlDatabase db)
{

     db = QSqlDatabase::addDatabase("QMYSQL");
           db.setHostName("192.168.43.6");
           db.setPort(3306);
           db.setUserName("root");
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
    QString sql=QString("create table %1 (ID INT PRIMARY KEY AUTO_INCREMENT,"
                        "username varchar(255),dt_value datetime,type TINYINT,text_value TEXT,image LONGBLOB );").arg(tbname);
    //type=1为文本,type=2为图片
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

int MYsqldb::inportms(QSqlDatabase db, QString tbname,QString username,QString tm ,int type,QString txt)
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

QStringList MYsqldb::exportdatallms(QSqlDatabase db, QString tbname)
{
   QSqlQuery query;
   QStringList sqlist;
   QString sl=QString("select * from %1").arg(tbname);
   if(!query.exec(sl))
   {qDebug()<<"query error :" <<query.lastError();
   }
   else{
   while(query.next()){
       if(query.value(3)==1){

   sqlist<<query.value(1).toString()<<query.value(2).toString()<<query.value(3).toString()<<query.value(4).toString();

       }
       else {
         sqlist<<query.value(1).toString()<<query.value(2).toString()<<query.value(3).toString()<<query.value(5).toStringList();
         //接受处用.toByteArray转化为二进制格式
       }
   }

  return sqlist;
   }
}

QStringList MYsqldb::exportdataulms(QSqlDatabase db, QString tbname, int num)
{

    QSqlQuery query;
    int i=0;
    QStringList sqlist;
    QString sl=QString("select * from %1").arg(tbname);
    QString dl=qApp->applicationDirPath()+"/cache";
    QDir dr(dl);
    if(!dr.exists()){
        bool ismkdir=QDir().mkdir(dl);
        if(!ismkdir)
            {
            qDebug()<<"mkdir wrong!";
            }
        }
    if(!query.exec(sl))
    {qDebug()<<"indValuequery error :" <<query.lastError();
    }
    else{
    while(query.next()){ i++;}
    qDebug()<<QString::number(i);
    int j=i-num+1;
    //sl=QString("select * from %1").arg(tbname);
    qDebug()<<QString::number(j);
    query.seek(j-2);
    while(query.next()){
        if(query.value(3)==TXT){

            sqlist<<query.value(1).toString()<<query.value(2).toString()<<query.value(3).toString()<<query.value(4).toString();

        }
        else if(query.value(3)==JPG){

            QByteArray data;
            data=query.value(5).toByteArray();
            dl=dl+"/";dl=dl+query.value(2).toString();dl=dl+".jpg";
            QFile fl(dl);
            if(!fl.open(QIODevice::ReadWrite))
            {qDebug()<<"open failed";}
            /*QImage im_save;
            if(!im_save.loadFromData(data))qDebug()<<"load image failed!";
            if(!im_save.save(dl,"JPG",100))qDebug()<<"save image failed!";*/
            QPixmap pix;
            pix.loadFromData(data,"jpg");
            pix.save(dl);
            qDebug()<<"导出";
            sqlist<<query.value(1).toString()<<query.value(2).toString()<<query.value(3).toString()<<"this user had post a image,please check out";
          //接受处用.toByteArray转化为二进制格式
        }
        else if(query.value(3)==MP3){

            QByteArray data;
            data=query.value(5).toByteArray();
            dl=dl+"/";dl=dl+query.value(2).toString();dl=dl+".mp3";
            QFile fl(dl);
            if(!fl.open(QIODevice::ReadWrite))
            {
                qDebug()<<"open failed";
            }
            else {
                fl.write(data);
                fl.close();
            }
            qDebug()<<"导出";
            sqlist<<query.value(1).toString()<<query.value(2).toString()<<query.value(3).toString()<<"this user had post a mp3,please check out";
          //接受处用.toByteArray转化为二进制格式
        }
        else {
            qDebug()<<"other type";
        }
    }


   return sqlist;
    }
}

int MYsqldb::inportpt(QSqlDatabase db, QString tbname, QString username, QString tm, int type, QString im)
{

    QFile file(im);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"open failed";
         return 0;
    }
    QByteArray data = file.readAll();
    if(data.isEmpty())
    {
        qDebug()<<"data is empty";
    }

    file.close();

    QSqlQuery query;
    QString sql=QString("insert into %1(username,dt_value,type,image) values('%2','%3','%4',?)").arg(tbname).arg(username).arg(tm).arg(type);
    query.prepare(sql);
    query.addBindValue(data);
    /*
    QString sql=QString("insert into %1(username,dt_value,type,image)");
    query.prepare(sql);
    query.bindValue(":username",username);
    query.bindValue(":dt_value",tm);
    query.bindValue(":type",type);
    query.bindValue(":image",data);
     */
    if(!query.exec())
    {
        qDebug()<<"query error :" <<query.lastError();
        return 0;
    }
    else {
        qDebug()<<"insert jpgimage successfully!";
        return 1;
    }

}


