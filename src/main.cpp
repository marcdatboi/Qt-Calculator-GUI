



#include "mainwindow.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow main_window;

    main_window.resize(360, 640);
    main_window.setStyleSheet("background-color: #212122");

    main_window.show();
    return a.exec();
}
