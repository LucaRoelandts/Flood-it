#include "boardview.h"

BoardView::BoardView(Game& game, QWidget *parent):
    QWidget(parent),
    _game(game),
    _gridLayout(this),
    _rows(_game.getRows()),
    _cols(_game.getCols()),
    _cells()
{

    _cells.resize(_rows, std::vector<QLabel*>(_cols, nullptr));
    printCells();
    _gridLayout.setSpacing(0);
    _gridLayout.setSizeConstraint(QLayout::SetFixedSize);
    setLayout(&_gridLayout);
}

void BoardView::printCells(){
    if(!_gridLayout.isEmpty()){
        for (int row = 0; row < _rows; ++row) {
            for (int col = 0; col < _cols; ++col){
                _gridLayout.removeItem(_gridLayout.itemAtPosition(row,col));
            }

        }
    }
    for (int row = 0; row < _rows; ++row) {
        for (int col = 0; col < _cols; ++col) {
            QLabel *cellLabel = new QLabel(this);
            cellLabel->setFixedSize(40, 40);
            cellLabel->setStyleSheet(QString("background-color: %1; border: 1px solid black;")
                                        .arg(toQColor(_game.getColor(row,col)).name()));



            _cells[row][col]=cellLabel;
            _gridLayout.addWidget(cellLabel,row,col);

        }
    }
}


