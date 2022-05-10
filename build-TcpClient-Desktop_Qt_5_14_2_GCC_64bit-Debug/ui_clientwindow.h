/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontCbx;
    QComboBox *sizeCbx;
    QToolButton *boldTBtn;
    QToolButton *italicTbtn;
    QToolButton *underlineTBtn;
    QToolButton *colorTBtn;
    QToolButton *clearTBtn;
    QTextEdit *msgTextEdit;
    QSplitter *splitter;
    QTextBrowser *textBrowser;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *exitButton;
    QMenuBar *menubar;
    QMenu *menuClient;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName(QString::fromUtf8("ClientWindow"));
        ClientWindow->resize(761, 544);
        centralwidget = new QWidget(ClientWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(620, 0, 120, 450));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 300, 600, 50));
        frame->setFrameShape(QFrame::Box);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fontCbx = new QFontComboBox(frame);
        fontCbx->setObjectName(QString::fromUtf8("fontCbx"));

        horizontalLayout->addWidget(fontCbx);

        sizeCbx = new QComboBox(frame);
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->setObjectName(QString::fromUtf8("sizeCbx"));

        horizontalLayout->addWidget(sizeCbx);

        boldTBtn = new QToolButton(frame);
        boldTBtn->setObjectName(QString::fromUtf8("boldTBtn"));
        boldTBtn->setCheckable(true);

        horizontalLayout->addWidget(boldTBtn);

        italicTbtn = new QToolButton(frame);
        italicTbtn->setObjectName(QString::fromUtf8("italicTbtn"));
        italicTbtn->setCheckable(true);

        horizontalLayout->addWidget(italicTbtn);

        underlineTBtn = new QToolButton(frame);
        underlineTBtn->setObjectName(QString::fromUtf8("underlineTBtn"));
        underlineTBtn->setCheckable(true);

        horizontalLayout->addWidget(underlineTBtn);

        colorTBtn = new QToolButton(frame);
        colorTBtn->setObjectName(QString::fromUtf8("colorTBtn"));
        colorTBtn->setCheckable(true);

        horizontalLayout->addWidget(colorTBtn);

        clearTBtn = new QToolButton(frame);
        clearTBtn->setObjectName(QString::fromUtf8("clearTBtn"));

        horizontalLayout->addWidget(clearTBtn);

        msgTextEdit = new QTextEdit(centralwidget);
        msgTextEdit->setObjectName(QString::fromUtf8("msgTextEdit"));
        msgTextEdit->setGeometry(QRect(20, 350, 600, 100));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(20, 0, 600, 300));
        splitter->setOrientation(Qt::Horizontal);
        textBrowser = new QTextBrowser(splitter);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        splitter->addWidget(textBrowser);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 460, 602, 30));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(81);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(81, 0, 81, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        exitButton = new QPushButton(widget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout_2->addWidget(exitButton);

        ClientWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClientWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 761, 28));
        menuClient = new QMenu(menubar);
        menuClient->setObjectName(QString::fromUtf8("menuClient"));
        ClientWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ClientWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ClientWindow->setStatusBar(statusbar);

        menubar->addAction(menuClient->menuAction());

        retranslateUi(ClientWindow);

        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClientWindow)
    {
        ClientWindow->setWindowTitle(QCoreApplication::translate("ClientWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ClientWindow", "Username:", nullptr));
        sizeCbx->setItemText(0, QCoreApplication::translate("ClientWindow", "5", nullptr));
        sizeCbx->setItemText(1, QCoreApplication::translate("ClientWindow", "6", nullptr));
        sizeCbx->setItemText(2, QCoreApplication::translate("ClientWindow", "7", nullptr));
        sizeCbx->setItemText(3, QCoreApplication::translate("ClientWindow", "8", nullptr));
        sizeCbx->setItemText(4, QCoreApplication::translate("ClientWindow", "9", nullptr));
        sizeCbx->setItemText(5, QCoreApplication::translate("ClientWindow", "10", nullptr));
        sizeCbx->setItemText(6, QCoreApplication::translate("ClientWindow", "11", nullptr));
        sizeCbx->setItemText(7, QCoreApplication::translate("ClientWindow", "12", nullptr));
        sizeCbx->setItemText(8, QCoreApplication::translate("ClientWindow", "13", nullptr));
        sizeCbx->setItemText(9, QCoreApplication::translate("ClientWindow", "14", nullptr));
        sizeCbx->setItemText(10, QCoreApplication::translate("ClientWindow", "15", nullptr));

#if QT_CONFIG(tooltip)
        boldTBtn->setToolTip(QCoreApplication::translate("ClientWindow", "Bold", nullptr));
#endif // QT_CONFIG(tooltip)
        boldTBtn->setText(QCoreApplication::translate("ClientWindow", "B", nullptr));
#if QT_CONFIG(tooltip)
        italicTbtn->setToolTip(QCoreApplication::translate("ClientWindow", "Incline", nullptr));
#endif // QT_CONFIG(tooltip)
        italicTbtn->setText(QCoreApplication::translate("ClientWindow", "I", nullptr));
#if QT_CONFIG(tooltip)
        underlineTBtn->setToolTip(QCoreApplication::translate("ClientWindow", "Underline", nullptr));
#endif // QT_CONFIG(tooltip)
        underlineTBtn->setText(QCoreApplication::translate("ClientWindow", "U", nullptr));
#if QT_CONFIG(tooltip)
        colorTBtn->setToolTip(QCoreApplication::translate("ClientWindow", "Colour", nullptr));
#endif // QT_CONFIG(tooltip)
        colorTBtn->setText(QCoreApplication::translate("ClientWindow", "Col", nullptr));
#if QT_CONFIG(tooltip)
        clearTBtn->setToolTip(QCoreApplication::translate("ClientWindow", "Clear", nullptr));
#endif // QT_CONFIG(tooltip)
        clearTBtn->setText(QCoreApplication::translate("ClientWindow", "C", nullptr));
        pushButton->setText(QCoreApplication::translate("ClientWindow", "send", nullptr));
        label->setText(QCoreApplication::translate("ClientWindow", " Member Online:", nullptr));
        exitButton->setText(QCoreApplication::translate("ClientWindow", "exit", nullptr));
        menuClient->setTitle(QCoreApplication::translate("ClientWindow", "Client", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
