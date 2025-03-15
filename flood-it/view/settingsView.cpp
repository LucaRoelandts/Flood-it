#include "settingsview.h"
#include <QDebug>
#include <iostream>
#include <QApplication>
#include <random>

SettingsView::SettingsView(QWidget *parent)
    : QWidget(parent),
    _layout(this),
    _widthSB(this),
    _heightSB(this),
    _nbOfColors(this),
    _start(this)
{
    setFixedSize(400,300);
    _layout.addWidget(&_widthSB);
    _layout.addWidget(&_heightSB);
    _layout.addWidget(&_nbOfColors);
    _layout.addWidget(&_start);

    QObject::connect(&_start,&QPushButton::clicked,this,&SettingsView::startTheGame);
    QString title("start");
    _start.setText(title);
}
void SettingsView::startTheGame(){

    QApplication::quit();
}

Settings SettingsView::getSettings(){
    int nbOfColors=_nbOfColors.value();

    return {
        _heightSB.value(),
        _widthSB.value(),
        nbOfColors,
        {getRandomColors(nbOfColors)}
    };
}

std::vector<Colors> SettingsView::getRandomColors(int count) {
    std::vector<Colors> randomColors;
    std::vector<Colors> allColors = {getAllColors()};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, allColors.size() - 1);

    for (int i = 0; i < count; ++i) {
        randomColors.push_back(allColors.at(dist(gen)));
    }

    return randomColors;
}
