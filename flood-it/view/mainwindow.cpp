#include "mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    _settingsView{nullptr},
    _flootitView{nullptr},
    _rootWidget(this),
    _rootLayout(&_rootWidget),
    _startGameBtn{nullptr},
    _game{nullptr},
    _currentColor()
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
    _flootitView->refresh();
}
void MainWindow::startBtn(){
    delSettingsView();
    _game=new Game(_currentSettings);
    _game->registerObserver(this);
    _flootitView=new Floot_ItView(_currentSettings,*_game,this);
    initColorButtons();
    _rootLayout.addWidget(_flootitView);
    int x =4,y=5;
    _currentColor=_game->getColor(x,y);
}
void MainWindow::selectColor(Colors& color){
    _game->selectColor(color);
}
void MainWindow::initColorButtons(){
    std::vector<QPushButton *> btns=_flootitView->getColorsButtons();
    for(auto btn:btns){
        QObject::connect(btn, &QPushButton::clicked,this,[this,btn]{
             _currentColor=toColors(btn->property("associatedColor").value<QColor>());
            if(_game!=nullptr)
                _game->selectColor(_currentColor);
        });
    }
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
