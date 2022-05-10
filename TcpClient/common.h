#ifndef COMMON_H
#define COMMON_H
#endif // COMMON_H

#define BASE_BUFFER_SIZE 8
// size of the protocols
#define PROTOCOL_ID_SIZE 1
#define ACCOUNT_SIZE 2
#define DATA_TYPE_SIZE 1
#define DATA_SIZE 4
// DEFINE of protocol ID
#define LOGIN 1
#define SEND 2
#define READ 3
#define NOTICE 4
#define ACK 5
#define LOGOUT 6
#define REGISTER 7
#define ONLINELIST 8
#define CLOSE 9
// DEFINE of data type
#define TEXT 1
#define IMAGE 2
#define LOGIN_SUCCESS 0
#define LOGIN_FAIL 1
#define LOGIN_EXIST 2
#define REGISTER_SUCCESS 0
#define REGISTER_FAIL 1
// DEFINE of SQLlist's format
#define SQL_PERIOD 4
#define USER_COUNT 0
#define TIME_COUNT 1
#define TYPE_COUNT 2
#define MESSAGE_COUNT 3

#define TCP_BUFSIZ 8192
#define BUF_SIZE 8192

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <QString>
#include <QStringList>
#include <QStringListIterator>
#include <QDebug>
#include <QMessageBox>
#include <QTextCodec>
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QWidget>
#include <QFile>
#include <QByteArray>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QCoreApplication>
#include <QDateTime>
#include <QFont>
#include <QColorDialog>
#include <QDataStream>
#include <QTextStream>
#include <bits/stdc++.h>
#include <QMainWindow>
#include <QWidget>
#include <QTcpSocket>
#include <QtAlgorithms>
#include <QDateTime>
#include <QPixmap>
#include <QFileDialog>
#include <QFont>
#include <QColorDialog>
#include <QMessageBox>
#include <QDataStream>
#include <QTextStream>
#include <sys/stat.h>
#include <QThread>

