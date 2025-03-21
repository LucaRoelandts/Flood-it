#include "Board.h"
#include "../util/Random.h"
#include <iostream>

int Board::getNCols() const{
    return _cols;
}
int Board::getNRows ()const{
    return _rows;
}

Board::Board(int rows, int cols, int numColors, std::vector<Colors> selectedColors):
    _rows(rows),
    _cols(cols),
    _remainingCells(rows*cols),
    _grid(rows, std::vector<Colors>(cols)),
    _colors{selectedColors}
{
    initialize();
}

void Board::captureZone(int row, int col, Colors targetColor, Colors newColor) {
    // Vérifier les limites du plateau
    if (row < 0 || row >= _rows || col < 0 || col >= _cols) {
        return;
    }
    // Vérifier si la cellule n'a pas la couleur cible
    if (_grid[row][col] != targetColor) {
        return;
    }

    _grid[row][col] = newColor; // Changer la couleur
    _remainingCells--;

    // Appel récursif pour capturer les voisins (haut, bas, gauche, droite)
    captureZone(row - 1, col, targetColor, newColor); // Haut
    captureZone(row + 1, col, targetColor, newColor); // Bas
    captureZone(row, col - 1, targetColor, newColor); // Gauche
    captureZone(row, col + 1, targetColor, newColor); // Droite
}

Colors Board::getCellColor(int row, int col) const{
    return _grid.at(row).at(col);
}
void Board::changeColor(Colors newColor){
    Colors targetColor = _grid[0][0]; // Obtenir la couleur actuelle
    captureZone(0, 0, targetColor, newColor);
}
void Board::initialize(){
    for (int i = 0; i < _grid.size(); ++i) {
        for (int j = 0; j < _grid.at(i).size(); ++j) {
            int index = Random::randInt(0, _colors.size());
            _grid.at(i).at(j) = _colors.at(index);
        }
    }

}
Colors Board::getColors(int& row, int& col){
    return _grid.at(row).at(col);
}
