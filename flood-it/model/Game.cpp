#include "Game.h"
Game::Game(Settings &s):
    _settings(s),
    _board(s.height,s.width,s.nbOfColors,s.colors),
    _moveCount(s.height*s.width)
{

}

bool Game::isGameOver() const {
    return _board.isCompleted();
}
int Game::getMoveCount() const{
    return _moveCount;
}

void Game::startNewGame(){
    _board.initialize();
}
void Game::selectColor(Colors& color){
    _selectedColor=color;
}
Colors Game::getColor(size_t& row,size_t& col){
    return _board.getColors(row,col);
}

size_t Game::getRows(){
    return _board.getNRows();
}
size_t Game::getCols(){
    return _board.getNCols();
}
Game::~Game(){

}
