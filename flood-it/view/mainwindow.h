#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QApplication>
#include <QPushButton>
#include "floot_itview.h"
#include "SettingsView.h"
#include "../util/Observer.h"

class MainWindow : public QMainWindow,public Observer
{
    Q_OBJECT

    Game* _game;
    Settings _currentSettings;

    QWidget _rootWidget;
    QGridLayout _rootLayout;
    SettingsView* _settingsView;
    Floot_ItView* _flootitView;
    QPushButton* _startGameBtn;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void update() override;
private:
    void init();
    void startBtn();
    void delSettingsView();
    void initGame();
};

#endif // MAINWINDOW_H
