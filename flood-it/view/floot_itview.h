#ifndef FLOOT_ITVIEW_H
#define FLOOT_ITVIEW_H


#include <QHBoxLayout>
#include "ColorsChoisesView.h"
#include "boardview.h"
class Floot_ItView : public QWidget
{
    Q_OBJECT

    ColorsChoisesView *_colorChoisesView;
    BoardView *_boardview;
    Game& _game;
    Settings _settings;
    QHBoxLayout _layout;

public:
    explicit Floot_ItView(Settings& s,Game& game,QWidget *parent=nullptr);
    ~Floot_ItView() override;

    void refresh();
    std::vector<QPushButton *> getColorsButtons();

};

#endif // FLOOT_ITVIEW_H
