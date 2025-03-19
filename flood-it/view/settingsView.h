#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QFormLayout>
#include <QLabel>
#include "../model/settings.h"

class SettingsView : public QWidget {
    Q_OBJECT

    QFormLayout _layout;
    QLabel _widthLabel;
    QSpinBox _widthSB;
    QLabel _heightLabel;
    QSpinBox _heightSB;
    QLabel _nbOfColorsLabel;
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
