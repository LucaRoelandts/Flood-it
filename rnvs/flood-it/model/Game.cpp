#include "Game.h"
Game::Game(Settings &s):
    _settings(s),
    _board(s.height,s.width,s.nbOfColors,s.colors),
    _moveCount(0)
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
    captureZone(color);
    notifyObservers();
}
Colors Game::getColor(int& row,int& col){
    return _board.getColors(row,col);
}

int Game::getRows(){
    return _board.getNRows();
}
int Game::getCols(){
    return _board.getNCols();
}
Game::~Game(){

}
void Game::captureZone(Colors& color){
    _board.changeColor(color);
    _moveCount++;
}
