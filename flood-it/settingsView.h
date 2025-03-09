#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpinBox>

class SettingsView : public QWidget {
    Q_OBJECT

public:
    explicit SettingsView(QWidget *parent = nullptr);


private:
    QVBoxLayout _layout;  // Direct instance (no pointers)
    QSpinBox _weightSB;
    QSpinBox _heightSB;
    QSpinBox _nbOfColors;
    QPushButton _start;

    void startTheGame();
};

#endif // SETTINGSVIEW_H
