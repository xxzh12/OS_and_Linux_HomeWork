/********************************************************************************
** Form generated from reading UI file 'logwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWIDGET_H
#define UI_LOGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogWidget
{
public:
    QPushButton *btn_clear;
    QPushButton *btn_log;
    QGroupBox *groupBox;
    QLineEdit *edit_name;
    QLineEdit *edit_pw;
    QLabel *label_name;
    QLabel *label_pw;
    QLabel *label_title;

    void setupUi(QWidget *LogWidget)
    {
        if (LogWidget->objectName().isEmpty())
            LogWidget->setObjectName(QString::fromUtf8("LogWidget"));
        LogWidget->resize(381, 275);
        btn_clear = new QPushButton(LogWidget);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));
        btn_clear->setGeometry(QRect(50, 190, 112, 32));
        btn_clear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #ff55ff, stop: 1 #1296db);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}"));
        btn_log = new QPushButton(LogWidget);
        btn_log->setObjectName(QString::fromUtf8("btn_log"));
        btn_log->setGeometry(QRect(220, 190, 112, 32));
        btn_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #ff55ff, stop: 1 #1296db);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}"));
        groupBox = new QGroupBox(LogWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 341, 151));
        edit_name = new QLineEdit(groupBox);
        edit_name->setObjectName(QString::fromUtf8("edit_name"));
        edit_name->setGeometry(QRect(80, 30, 251, 31));
        edit_name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}"));
        edit_pw = new QLineEdit(groupBox);
        edit_pw->setObjectName(QString::fromUtf8("edit_pw"));
        edit_pw->setGeometry(QRect(80, 80, 251, 31));
        edit_pw->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}"));
        label_name = new QLabel(groupBox);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(30, 25, 112, 32));
        label_name->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:50px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"}"));
        label_pw = new QLabel(groupBox);
        label_pw->setObjectName(QString::fromUtf8("label_pw"));
        label_pw->setGeometry(QRect(16, 80, 67, 20));
        label_pw->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:50px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"}"));
        label_title = new QLabel(LogWidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(100, 10, 191, 20));
        label_title->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:50px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"}"));

        retranslateUi(LogWidget);

        QMetaObject::connectSlotsByName(LogWidget);
    } // setupUi

    void retranslateUi(QWidget *LogWidget)
    {
        LogWidget->setWindowTitle(QCoreApplication::translate("LogWidget", "Form", nullptr));
        btn_clear->setText(QCoreApplication::translate("LogWidget", "Reset", nullptr));
        btn_log->setText(QCoreApplication::translate("LogWidget", "Login", nullptr));
        groupBox->setTitle(QString());
        label_name->setText(QCoreApplication::translate("LogWidget", " Name:", nullptr));
        label_pw->setText(QCoreApplication::translate("LogWidget", " Account:", nullptr));
        label_title->setText(QCoreApplication::translate("LogWidget", "[Killer Queen]\346\235\234\347\216\213\347\224\272\350\201\212\345\244\251\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogWidget: public Ui_LogWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWIDGET_H
