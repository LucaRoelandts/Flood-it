#include "mainwindow.h"
#include <QMessageBox>
#include <fstream>
#include <ctime>
#include <filesystem>
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
    if(_game->isGameOver()){
        _game->unregisterObserver(this);
        std::string str=std::to_string(_game->getMoveCount());
        QString s(QString::fromStdString(str));
        QMessageBox::information(nullptr,"Score",s);
        saveScore(_game->getMoveCount());
        QApplication::quit();
    }
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
void MainWindow::saveScore(int score){
    std::string folder = "scores";
    std::string filePath = folder + "/scores.txt";

    // Ensure the directory exists
    if (!std::filesystem::exists(folder)) {
        std::filesystem::create_directory(folder);
    }

    // Ensure the file exists
    if (!std::filesystem::exists(filePath)) {
        std::ofstream createFile(filePath);  // Create an empty file
        createFile.close();
    }

    // Open file in append mode
    std::ofstream outFile(filePath, std::ios::app);

    if (outFile.is_open()) {
        // Get current time
        std::time_t now = std::time(nullptr);
        char timeStr[100];
        std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

        // Write score to file
        outFile << timeStr << " - " << score << std::endl;
        outFile.close();
    }
}
