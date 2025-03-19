#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <memory>
#include "../util/Observable.h"
#include "settings.h"
/**
 * @class Game
 * @brief Gère la logique générale du jeu Flood-It.
 */
class Game : public Observable {
public:
    /**
     * @brief Constructeur du jeu.
     * @param rows Nombre de lignes du plateau.
     * @param cols Nombre de colonnes du plateau.
     * @param numColors Nombre total de couleurs disponibles.
     */
    Game(size_t rows, size_t cols, int numColors);

    /**
     * @brief Démarre une nouvelle partie en réinitialisant le plateau.
     */
    void startNewGame();

    /**
     * @brief Sélectionne une couleur et met à jour la zone capturée.
     * @param color La couleur sélectionnée par le joueur.
     */
    void selectColor(int color);

    /**
     * @brief Vérifie si la partie est terminée.
     * @return `true` si toutes les cellules sont de la même couleur, `false` sinon.
     */
    bool isGameOver() const;

    /**
     * @brief Obtient le nombre de tours joués.
     * @return Le nombre total de coups joués.
     */
    int getMoveCount() const;

private:
    Board board; ///< Plateau de jeu.
    int moveCount;///< Nombre de tours joués.
    Settings settings;
};

#endif // GAME_H
