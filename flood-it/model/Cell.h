#ifndef CELL_H
#define CELL_H

#include <cstddef>
#include "settings.h"

/**
 * @class Cell
 * @brief Représente une pastille colorée sur le plateau.
 */
class Cell {
public:
    /**
     * @brief Constructeur de la classe Cell.
     * @param row Position de la cellule en ligne.
     * @param col Position de la cellule en colonne.
     * @param color Couleur initiale de la cellule.
     */
    Cell(size_t& row, size_t& col, Colors color);

    Cell();

    /**
     * @brief Obtient la couleur de la cellule.
     * @return La couleur actuelle.
     */
    Colors getColor() const;

    /**
     * @brief Définit une nouvelle couleur pour la cellule.
     * @param newColor La nouvelle couleur à attribuer.
     */
    void setColor(Colors newColor);

    /**
     * @brief Obtient l'indice de la ligne.
     * @return L'indice de la ligne.
     */
    size_t getRow() const;

    /**
     * @brief Obtient l'indice de la colonne.
     * @return L'indice de la colonne.
     */
    size_t getCol() const;

private:
    size_t _row, _col; ///< Position de la cellule sur le plateau.
    Colors _color; ///< Couleur actuelle de la cellule.
};

#endif // CELL_H
