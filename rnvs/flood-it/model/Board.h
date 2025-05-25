#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Colors.h"

/**
 * @class Board
 * @brief Gère le plateau de jeu et les actions associées.
 */
class Board {
private:
    int _rows; ///< Nombre de lignes du plateau.
    int _cols; ///< Nombre de colonnes du plateau.
    int _numColors; ///< Nombre total de couleurs disponibles.
    std::vector<Colors> _colors; ///< Liste des couleurs disponibles.
    std::vector<std::vector<Colors>> _grid; ///< Grille représentant les cellules du plateau.
    std::vector<std::vector<bool>> _captured; ///< Matrice indiquant quelles cellules ont été capturées.

    /**
     * @brief Capture une zone adjacente de cellules ayant la même couleur.
     * @param row Indice de la ligne de départ.
     * @param col Indice de la colonne de départ.
     * @param targetColor Couleur des cellules à capturer.
     * @param newColor Nouvelle couleur appliquée aux cellules capturées.
     */
    void captureZone(int row, int col, Colors targetColor, Colors newColor);

public:
    /**
     * @brief Constructeur du plateau de jeu.
     * Initialise la grille avec des couleurs aléatoires.
     * @param rows Nombre de lignes du plateau.
     * @param cols Nombre de colonnes du plateau.
     * @param numColors Nombre total de couleurs disponibles.
     * @param selectedColors Liste des couleurs utilisables dans le jeu.
     */
    Board(int rows, int cols, int numColors, std::vector<Colors> selectedColors);

    /**
     * @brief Initialise le plateau avec des couleurs aléatoires.
     */
    void initialize();

    /**
     * @brief Obtient le nombre de lignes du plateau.
     * @return Nombre de lignes du plateau.
     */
    int getNRows() const;

    /**
     * @brief Obtient le nombre de colonnes du plateau.
     * @return Nombre de colonnes du plateau.
     */
    int getNCols() const;

    /**
     * @brief Obtient la couleur d'une cellule spécifique.
     * @param row Indice de la ligne.
     * @param col Indice de la colonne.
     * @return La couleur actuelle de la cellule.
     */
    Colors getCellColor(int row, int col) const;

    /**
     * @brief Vérifie si toutes les cellules du plateau ont été capturées.
     * @return `true` si le plateau est entièrement capturé, `false` sinon.
     */
    bool isCompleted() const;

    /**
     * @brief Change la couleur de la zone capturée et l'étend si possible.
     * @param newColor Nouvelle couleur sélectionnée par le joueur.
     */
    void changeColor(Colors newColor);

    /**
     * @brief Obtient la couleur actuelle d'une cellule.
     * @param row Indice de la ligne.
     * @param col Indice de la colonne.
     * @return Couleur de la cellule aux coordonnées spécifiées.
     */
    Colors getColors(int& row, int& col);
};

#endif // BOARD_H
