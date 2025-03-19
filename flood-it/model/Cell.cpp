#include "Cell.h"

Cell::Cell(size_t& r,size_t& col,Colors color):
    _row(r),
    _col(col),
    _color(color)
{}

Colors Cell::getColor() const {
    return _color;
}

size_t Cell::getCol() const{
    return _col;
}
size_t Cell::getRow() const{
    return _row;
}
void Cell::setColor(Colors newColor){
    this->_color=newColor;
}
