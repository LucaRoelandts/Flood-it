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
