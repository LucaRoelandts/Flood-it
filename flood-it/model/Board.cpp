#include "Board.h"
#include <algorithm>
#include "../util/Random.h"

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
    _grid(rows,std::vector<Cell>(cols)),
    _captured(rows,std::vector<bool>(cols,false)),
    _colors{selectedColors}
{

}

void Board::captureZone(size_t& row, size_t& col, Colors targetColor, Colors newColor){
    //todo
}

Colors Board::getCellColor(size_t row, size_t col) const{
    return _grid.at(row).at(col).getColor();
}
void Board::changeColor(Colors newColor){
    //todo
}
void Board::initialize(){

    for (int i = 0; i < _grid.size(); ++i) {
        for (int j = 0; j < _grid.at(i).size(); ++j) {
            _grid.at(i).at(j).setColor(_colors.at(Random::randInt(0,_colors.size()-1)));
        }
    }
}
