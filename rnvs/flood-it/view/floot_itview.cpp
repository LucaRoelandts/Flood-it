#include "floot_itview.h"

Floot_ItView::Floot_ItView(Settings& s,Game& game,QWidget *parent):
    QWidget{parent},
    _layout(this),
    _boardview{nullptr},
    _colorChoisesView{nullptr},
    _game(game),
    _settings(s)

{
    _colorChoisesView=new ColorsChoisesView(_settings.colors,this);
    _boardview=new BoardView(_game,this);


    _colorChoisesView->setObjectName("ColorChoices");
    _layout.addWidget(_colorChoisesView);
    _layout.addWidget(_boardview);
    _layout.setSpacing(1);
    setLayout(&_layout);
}

Floot_ItView::~Floot_ItView(){
    delete _colorChoisesView;
    delete _boardview;
}
void Floot_ItView::refresh(){
    _boardview->printCells();
}
std::vector<QPushButton *> Floot_ItView::getColorsButtons(){
    return _colorChoisesView->getButtons();
}
