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
#include <QtWidgets/QCheckBox>
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
    QCheckBox *check_pw;
    QCheckBox *check_name;
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
        LogWidget->resize(799, 275);
        btn_clear = new QPushButton(LogWidget);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));
        btn_clear->setGeometry(QRect(240, 230, 89, 25));
        btn_log = new QPushButton(LogWidget);
        btn_log->setObjectName(QString::fromUtf8("btn_log"));
        btn_log->setGeometry(QRect(490, 230, 89, 25));
        check_pw = new QCheckBox(LogWidget);
        check_pw->setObjectName(QString::fromUtf8("check_pw"));
        check_pw->setGeometry(QRect(240, 200, 151, 23));
        check_name = new QCheckBox(LogWidget);
        check_name->setObjectName(QString::fromUtf8("check_name"));
        check_name->setGeometry(QRect(450, 200, 151, 23));
        groupBox = new QGroupBox(LogWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(240, 30, 341, 151));
        edit_name = new QLineEdit(groupBox);
        edit_name->setObjectName(QString::fromUtf8("edit_name"));
        edit_name->setGeometry(QRect(80, 30, 251, 25));
        edit_pw = new QLineEdit(groupBox);
        edit_pw->setObjectName(QString::fromUtf8("edit_pw"));
        edit_pw->setGeometry(QRect(80, 80, 251, 25));
        label_name = new QLabel(groupBox);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(10, 40, 67, 17));
        label_pw = new QLabel(groupBox);
        label_pw->setObjectName(QString::fromUtf8("label_pw"));
        label_pw->setGeometry(QRect(0, 80, 67, 17));
        label_title = new QLabel(LogWidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(370, 0, 81, 17));

        retranslateUi(LogWidget);

        QMetaObject::connectSlotsByName(LogWidget);
    } // setupUi

    void retranslateUi(QWidget *LogWidget)
    {
        LogWidget->setWindowTitle(QCoreApplication::translate("LogWidget", "Form", nullptr));
        btn_clear->setText(QCoreApplication::translate("LogWidget", "Reset", nullptr));
        btn_log->setText(QCoreApplication::translate("LogWidget", "Login", nullptr));
        check_pw->setText(QCoreApplication::translate("LogWidget", "remember name", nullptr));
        check_name->setText(QCoreApplication::translate("LogWidget", "remember pw", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LogWidget", "Login Page", nullptr));
        label_name->setText(QCoreApplication::translate("LogWidget", "Name:", nullptr));
        label_pw->setText(QCoreApplication::translate("LogWidget", "Password:", nullptr));
        label_title->setText(QCoreApplication::translate("LogWidget", "Vchatroom ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogWidget: public Ui_LogWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWIDGET_H
