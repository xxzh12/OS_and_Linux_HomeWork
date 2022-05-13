#include "clientwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientWindow w;
    // 这边把主窗口的show()函数，这样主窗口就不会自动打开，
    // 必须通过登录窗口发出的信号，才能启动主窗口的show()函数。
    //w.show();
    return a.exec();
}
