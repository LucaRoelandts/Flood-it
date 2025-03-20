#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    _settingsView{nullptr},
    _flootitView{nullptr},
    _rootWidget(this),
    _rootLayout(&_rootWidget),
    _startGameBtn{nullptr},
    _game{nullptr}
{
    setCentralWidget(&_rootWidget);
    _rootWidget.setLayout(&_rootLayout);
    init();
}

MainWindow::~MainWindow(){
    delete _settingsView;
    delete _startGameBtn;
    delete _flootitView;
}

void MainWindow::init(){
    _settingsView=new SettingsView(&_rootWidget);
    _startGameBtn=new QPushButton(&_rootWidget);
    QString s("start");
    _startGameBtn->setText(s);
    QObject::connect(_startGameBtn,&QPushButton::clicked,this,[this]{
        this->startBtn();
    });
    _rootLayout.addWidget(_settingsView);
    _rootLayout.addWidget(_startGameBtn);
}
void MainWindow::update(){
    //todo
}
void MainWindow::startBtn(){
    delSettingsView();
    _game=new Game(_currentSettings);

    _flootitView=new Floot_ItView(_currentSettings,*_game,this);

    _rootLayout.addWidget(_flootitView);

}
void MainWindow::delSettingsView(){
    if(_settingsView!=nullptr){
        _currentSettings=_settingsView->getSettings();
        _rootLayout.removeWidget(_settingsView);
        delete _settingsView;
        _settingsView=nullptr;

        if(_startGameBtn!=nullptr){
            _rootLayout.removeWidget(_startGameBtn);
            delete _startGameBtn;
            _startGameBtn=nullptr;
        }
    }
}
