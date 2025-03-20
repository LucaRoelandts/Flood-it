#include "Board.h"
#include "../util/Random.h"
#include <iostream>
size_t Board::getNCols() const{
    return _cols;
}
size_t Board::getNRows ()const{
    return _rows;
}

Board::Board(size_t rows,size_t cols,int numColors,std::vector<Colors> selectedColors):
    _rows(rows),
    _cols(cols),
    _remainingCells(rows*cols),
    _grid(rows,std::vector<Colors>(cols)),
    _captured(rows,std::vector<bool>(cols,false)),
    _colors{selectedColors}
{
    initialize();
}

void Board::captureZone(size_t& row, size_t& col, Colors newColor){
    //todo
}

Colors Board::getCellColor(size_t row, size_t col) const{
    return _grid.at(row).at(col);
}
void Board::changeColor(size_t& startRow,size_t& startCol,Colors newColor){
    captureZone(startRow,startCol,newColor);
}
void Board::initialize(){

        for (int i = 0; i < _grid.size(); ++i) {
            for (int j = 0; j < _grid.at(i).size(); ++j) {
                int index=Random::randInt(0,_colors.size());
                _grid.at(i).at(j)=_colors.at(index);
            }
        }

}
Colors Board::getColors(size_t& row,size_t& col){
    return _grid.at(row).at(col);
}
