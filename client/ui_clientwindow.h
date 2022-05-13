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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontCbx;
    QComboBox *sizeCbx;
    QToolButton *boldTBtn;
    QToolButton *italicTbtn;
    QToolButton *underlineTBtn;
    QToolButton *colorTBtn;
    QToolButton *FileTBtn;
    QToolButton *clearTBtn;
    QTextEdit *msgTextEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *exitButton;
    QTextBrowser *MemberBrowser;
    QTextBrowser *textBrowser;
    QFrame *frame_2;
    QFrame *frame_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *Hellolabel;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuClient;

    void setupUi(QMainWindow *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName(QString::fromUtf8("ClientWindow"));
        ClientWindow->resize(748, 595);
        ClientWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(ClientWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 300, 600, 50));
        frame->setStyleSheet(QString::fromUtf8(" border-width: 1px;\n"
"    padding: 1px;\n"
"    border-style: solid;\n"
"    border-color: darkkhaki;\n"
"    border-radius: 5px;"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(2);
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
        boldTBtn->setStyleSheet(QString::fromUtf8("color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/"));
        boldTBtn->setCheckable(true);

        horizontalLayout->addWidget(boldTBtn);

        italicTbtn = new QToolButton(frame);
        italicTbtn->setObjectName(QString::fromUtf8("italicTbtn"));
        italicTbtn->setStyleSheet(QString::fromUtf8("color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/"));
        italicTbtn->setCheckable(true);

        horizontalLayout->addWidget(italicTbtn);

        underlineTBtn = new QToolButton(frame);
        underlineTBtn->setObjectName(QString::fromUtf8("underlineTBtn"));
        underlineTBtn->setStyleSheet(QString::fromUtf8("color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/"));
        underlineTBtn->setCheckable(true);

        horizontalLayout->addWidget(underlineTBtn);

        colorTBtn = new QToolButton(frame);
        colorTBtn->setObjectName(QString::fromUtf8("colorTBtn"));
        colorTBtn->setStyleSheet(QString::fromUtf8("color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/"));
        colorTBtn->setCheckable(true);

        horizontalLayout->addWidget(colorTBtn);

        FileTBtn = new QToolButton(frame);
        FileTBtn->setObjectName(QString::fromUtf8("FileTBtn"));
        FileTBtn->setStyleSheet(QString::fromUtf8("color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/"));

        horizontalLayout->addWidget(FileTBtn);

        clearTBtn = new QToolButton(frame);
        clearTBtn->setObjectName(QString::fromUtf8("clearTBtn"));
        clearTBtn->setStyleSheet(QString::fromUtf8("color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/"));

        horizontalLayout->addWidget(clearTBtn);

        fontCbx->raise();
        sizeCbx->raise();
        italicTbtn->raise();
        underlineTBtn->raise();
        colorTBtn->raise();
        FileTBtn->raise();
        clearTBtn->raise();
        boldTBtn->raise();
        msgTextEdit = new QTextEdit(centralwidget);
        msgTextEdit->setObjectName(QString::fromUtf8("msgTextEdit"));
        msgTextEdit->setGeometry(QRect(20, 350, 600, 100));
        msgTextEdit->setStyleSheet(QString::fromUtf8(" border-width: 1px;\n"
"    padding: 1px;\n"
"    border-style: solid;\n"
"    border-color: darkkhaki;\n"
"    border-radius: 5px;"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 450, 711, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(81);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(81, 0, 81, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_2->addWidget(pushButton);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 75 11pt \"Ubuntu Condensed\";\n"
"color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/"));

        horizontalLayout_2->addWidget(label);

        exitButton = new QPushButton(layoutWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
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

        horizontalLayout_2->addWidget(exitButton);

        label->raise();
        exitButton->raise();
        pushButton->raise();
        MemberBrowser = new QTextBrowser(centralwidget);
        MemberBrowser->setObjectName(QString::fromUtf8("MemberBrowser"));
        MemberBrowser->setGeometry(QRect(620, 0, 111, 451));
        MemberBrowser->setStyleSheet(QString::fromUtf8(""));
        MemberBrowser->setFrameShape(QFrame::HLine);
        MemberBrowser->setFrameShadow(QFrame::Sunken);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(21, 1, 599, 299));
        textBrowser->setStyleSheet(QString::fromUtf8(""));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(20, 0, 601, 301));
        frame_2->setStyleSheet(QString::fromUtf8(" border-width: 1px;\n"
"    padding: 1px;\n"
"    border-style: solid;\n"
"    border-color: darkkhaki;\n"
"    border-radius: 5px;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(620, 0, 111, 451));
        frame_3->setStyleSheet(QString::fromUtf8(" border-width: 1px;\n"
"    padding: 1px;\n"
"    border-style: solid;\n"
"    border-color: darkkhaki;\n"
"    border-radius: 5px;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 509, 711, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        Hellolabel = new QLabel(horizontalLayoutWidget);
        Hellolabel->setObjectName(QString::fromUtf8("Hellolabel"));
        Hellolabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: \"KaiTI\";\n"
"    font-size: 17px;\n"
"    color: #BDC8E2;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(Hellolabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        ClientWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ClientWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ClientWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(ClientWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 748, 28));
        menuClient = new QMenu(menubar);
        menuClient->setObjectName(QString::fromUtf8("menuClient"));
        ClientWindow->setMenuBar(menubar);

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
        FileTBtn->setText(QCoreApplication::translate("ClientWindow", "F", nullptr));
#if QT_CONFIG(tooltip)
        clearTBtn->setToolTip(QCoreApplication::translate("ClientWindow", "Clear", nullptr));
#endif // QT_CONFIG(tooltip)
        clearTBtn->setText(QCoreApplication::translate("ClientWindow", "C", nullptr));
        pushButton->setText(QCoreApplication::translate("ClientWindow", "\345\217\221\351\200\201", nullptr));
        label->setText(QCoreApplication::translate("ClientWindow", " Member Online:", nullptr));
        exitButton->setText(QCoreApplication::translate("ClientWindow", "\351\200\200\345\207\272", nullptr));
        Hellolabel->setText(QString());
        menuClient->setTitle(QCoreApplication::translate("ClientWindow", "Client", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
