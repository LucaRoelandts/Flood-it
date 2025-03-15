#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpinBox>
#include "../model/settings.h"

class SettingsView : public QWidget {
    Q_OBJECT

    QVBoxLayout _layout;  // Direct instance (no pointers)
    QSpinBox _widthSB;
    QSpinBox _heightSB;
    QSpinBox _nbOfColors;
    QPushButton _start;

    public:
        /**
         * Constructor.
         * @brief SettingsView constructor.
         * @param parent the parent Widget.
         */
        explicit SettingsView(QWidget *parent = nullptr);
        Settings getSettings();

    private:
        std::vector<Colors> getRandomColors(int count);
        void startTheGame();


};

#endif // SETTINGSVIEW_H
