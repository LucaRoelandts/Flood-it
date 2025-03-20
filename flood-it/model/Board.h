#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Colors.h"

/**
 * @class Board
 * @brief Gère le plateau de jeu et les actions associées.
 */
class Board {
public:
    /**
     * @brief Initialise le plateau avec des couleurs aléatoires.
     */
    void initialize();
    /**
     * @brief Constructeur du plateau de jeu.
     * @param rows Nombre de lignes.
     * @param cols Nombre de colonnes.
     * @param numColors Nombre total de couleurs disponibles.
     */
    Board(size_t rows, size_t cols, int numColors,std::vector<Colors> selectedColors);

    /**
     * @brief Obtient le nombre de lignes du plateau.
     * @return Nombre de lignes.
     */
    size_t getNRows() const;

    /**
     * @brief Obtient le nombre de colonnes du plateau.
     * @return Nombre de colonnes.
     */
    size_t getNCols() const;

    /**
     * @brief Obtient la couleur d'une cellule spécifique.
     * @param row Indice de la ligne.
     * @param col Indice de la colonne.
     * @return La couleur de la cellule.
     */
    Colors getCellColor(size_t row, size_t col) const;
    /**
     * @brief Vérifie si le jeu est terminé.
     * @return `true` si toutes les cellules sont capturées, `false` sinon.
     */
    bool isCompleted() const { return _remainingCells == 0; }

    /**
     * @brief Change la couleur de la zone capturée et l'étend si possible.
     * @param newColor Nouvelle couleur sélectionnée par le joueur.
     */
    void changeColor(size_t& row ,size_t& col,Colors newColor);

    Colors getColors(size_t& row,size_t& col);

private:
    size_t _rows, _cols; ///< Dimensions du plateau.
    int _numColors; ///< Nombre de couleurs possibles.
    std::vector<std::vector<Colors>> _grid; ///< Matrice représentant le plateau.
    std::vector<std::vector<bool>> _captured; ///< Indique si une cellule est capturée.
    unsigned _remainingCells;///< Nombre de cellules restant à capturer.
    std::vector<Colors> _colors;
    /**
     * @brief Étend la zone capturée en fonction de la couleur sélectionnée.
     * @param row Indice de la ligne de départ.
     * @param col Indice de la colonne de départ.
     * @param targetColor Couleur cible à capturer.
     * @param newColor Nouvelle couleur appliquée.
     */
    void captureZone(size_t& row, size_t& col, Colors newColor);
};

#endif // BOARD_H
