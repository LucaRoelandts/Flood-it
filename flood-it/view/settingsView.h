#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include <QWidget>
#include <QSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include "../model/settings.h"

class SettingsView : public QWidget {
    Q_OBJECT

    QFormLayout _layout;
    QLabel _widthLabel;
    QSpinBox _widthSB;
    QLabel _heightLabel;
    QSpinBox _heightSB;
    QLabel _nbOfColorsLabel;
    QComboBox _nbOfColors;

    public:
        /**
         * Constructor.
         * @brief SettingsView constructor.
         * @param parent the parent Widget.
         */
        explicit SettingsView(QWidget *parent = nullptr);
        Settings getSettings();

        ~SettingsView() override;

    private:
        std::vector<Colors> getRandomColors(int count);


};

#endif // SETTINGSVIEW_H
