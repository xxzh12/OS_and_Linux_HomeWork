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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QWidget *centralwidget;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontCbx;
    QComboBox *sizeCbx;
    QToolButton *boldTBtn;
    QToolButton *italicTbtn;
    QToolButton *underlineTBtn;
    QToolButton *clearTBtn;
    QToolButton *colorTBtn;
    QTextEdit *msgTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *exitButton;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuClient;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName(QString::fromUtf8("ClientWindow"));
        ClientWindow->resize(971, 485);
        centralwidget = new QWidget(ClientWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(70, 80, 762, 313));
        splitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(widget);
        frame->setObjectName(QString::fromUtf8("frame"));
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

        clearTBtn = new QToolButton(frame);
        clearTBtn->setObjectName(QString::fromUtf8("clearTBtn"));

        horizontalLayout->addWidget(clearTBtn);

        colorTBtn = new QToolButton(frame);
        colorTBtn->setObjectName(QString::fromUtf8("colorTBtn"));
        colorTBtn->setCheckable(true);

        horizontalLayout->addWidget(colorTBtn);


        verticalLayout->addWidget(frame);


        verticalLayout_2->addLayout(verticalLayout);

        msgTextEdit = new QTextEdit(widget);
        msgTextEdit->setObjectName(QString::fromUtf8("msgTextEdit"));

        verticalLayout_2->addWidget(msgTextEdit);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        exitButton = new QPushButton(widget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout_2->addWidget(exitButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        splitter->addWidget(widget);
        tableWidget = new QTableWidget(splitter);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        splitter->addWidget(tableWidget);
        ClientWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClientWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 971, 28));
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
        sizeCbx->setItemText(0, QCoreApplication::translate("ClientWindow", "5", nullptr));
        sizeCbx->setItemText(1, QCoreApplication::translate("ClientWindow", "6", nullptr));
        sizeCbx->setItemText(2, QCoreApplication::translate("ClientWindow", "7", nullptr));
        sizeCbx->setItemText(3, QCoreApplication::translate("ClientWindow", "8", nullptr));
        sizeCbx->setItemText(4, QCoreApplication::translate("ClientWindow", "9", nullptr));
        sizeCbx->setItemText(5, QCoreApplication::translate("ClientWindow", "10", nullptr));

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
        clearTBtn->setToolTip(QCoreApplication::translate("ClientWindow", "Clear", nullptr));
#endif // QT_CONFIG(tooltip)
        clearTBtn->setText(QCoreApplication::translate("ClientWindow", "C", nullptr));
#if QT_CONFIG(tooltip)
        colorTBtn->setToolTip(QCoreApplication::translate("ClientWindow", "Colour", nullptr));
#endif // QT_CONFIG(tooltip)
        colorTBtn->setText(QCoreApplication::translate("ClientWindow", "Col", nullptr));
        pushButton->setText(QCoreApplication::translate("ClientWindow", "send", nullptr));
        label->setText(QCoreApplication::translate("ClientWindow", " Member Online:", nullptr));
        exitButton->setText(QCoreApplication::translate("ClientWindow", "exit", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ClientWindow", "Username:", nullptr));
        menuClient->setTitle(QCoreApplication::translate("ClientWindow", "Client", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
