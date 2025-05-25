// #include "settingsview.h"    // rnvs : comm
#include "settingsView.h"       // rnvs : ajout
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
    _nbOfColors(this)
{
    _nbOfColors.addItems({"2","3", "4", "5", "6"}); // Add predefined values
    _nbOfColors.setCurrentIndex(2);

    _layout.addWidget(&_widthLabel);
    _layout.addWidget(&_widthSB);
    _layout.addWidget(&_heightLabel);
    _layout.addWidget(&_heightSB);
    _layout.addWidget(&_nbOfColorsLabel);
    _layout.addWidget(&_nbOfColors);



}

Settings SettingsView::getSettings(){
    int nbOfColors=_nbOfColors.currentText().toInt();

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
        int index=Random::randInt(0, allColors.size());
        randomColors.push_back(allColors.at(index));
        allColors.erase(allColors.begin()+index);
    }

    return randomColors;
}
SettingsView::~SettingsView(){

}
