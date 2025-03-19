#include "settingsview.h"
#include <QDebug>
#include <QApplication>
#include "../util/Random.h"

SettingsView::SettingsView(QWidget *parent)
    : QWidget(parent),
    _layout(this),
    _widthLabel("Largeur :", this),
    _widthSB(this),
    _heightLabel("Hauteur :", this),
    _heightSB(this),
    _nbOfColorsLabel("Nombre de couleurs :", this),
    _nbOfColors(this),
    _start(this)
{
    setFixedSize(400,300);
    _layout.addWidget(&_widthLabel);
    _layout.addWidget(&_widthSB);
    _layout.addWidget(&_heightLabel);
    _layout.addWidget(&_heightSB);
    _layout.addWidget(&_nbOfColorsLabel);
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


    for (int i = 0; i < count; ++i) {
        randomColors.push_back(allColors.at(Random::randInt(0, allColors.size())));
    }

    return randomColors;
}
