#include <QApplication>
#include <iostream>
#include "../view/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    m.setFixedSize(700,700);
    m.show();
    return a.exec();

}

