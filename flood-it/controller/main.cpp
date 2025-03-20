#include <QApplication>
#include <iostream>
#include "../view/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    m.setFixedSize(500,500);
    m.show();
    return a.exec();

}

