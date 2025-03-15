#include "../view/settingsView.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SettingsView s;
    s.show();
    return a.exec();
}
