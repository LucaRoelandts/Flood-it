#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "../util/Observable.h"
#include "settings.h"

/**
 * @class Game
 * @brief Gère la logique générale du jeu Flood-It.
 *
 * Cette classe encapsule la logique de jeu, y compris la gestion du plateau,
 * des mouvements des joueurs et des conditions de victoire.
 */
class Game : public Observable {
private:
    Board _board;      ///< Plateau de jeu.
    int _moveCount;    ///< Nombre de tours joués.
    const Settings _settings; ///< Configuration du jeu.

    /**
     * @brief Change la couleur sélectionnée et applique la capture de la zone.
     * @param color La nouvelle couleur sélectionnée.
     */
    void captureZone(Colors& color);

public:
    /**
     * @brief Constructeur du jeu.
     * @param setting Configuration du jeu, incluant les dimensions du plateau et les couleurs.
     */
    Game(Settings& setting);

    /**
     * @brief Destructeur de la classe Game.
     */
    ~Game() override;

    /**
     * @brief Démarre une nouvelle partie en réinitialisant le plateau.
     */
    void startNewGame();

    /**
     * @brief Sélectionne une couleur et met à jour la zone capturée.
     * @param color La couleur sélectionnée par le joueur.
     */
    void selectColor(Colors& color);

    /**
     * @brief Vérifie si la partie est terminée.
     * @return `true` si toutes les cellules du plateau sont de la même couleur, `false` sinon.
     */
    bool isGameOver() const;

    /**
     * @brief Retourne le nombre de tours joués.
     * @return Le nombre total de coups joués depuis le début de la partie.
     */
    int getMoveCount() const;

    /**
     * @brief Récupère la couleur d'une cellule spécifique sur le plateau.
     * @param row Indice de la ligne.
     * @param col Indice de la colonne.
     * @return La couleur de la cellule.
     */
    Colors getColor(int& row, int& col);

    /**
     * @brief Retourne le nombre de colonnes du plateau.
     * @return Le nombre de colonnes.
     */
    int getCols();

    /**
     * @brief Retourne le nombre de lignes du plateau.
     * @return Le nombre de lignes.
     */
    int getRows();
};

#endif // GAME_H
