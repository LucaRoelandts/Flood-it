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



    _layout.addWidget(_colorChoisesView);
    _layout.addWidget(_boardview);
    _layout.setSpacing(0);
    setLayout(&_layout);
}

Floot_ItView::~Floot_ItView(){
    delete _colorChoisesView;
    delete _boardview;
}
