#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <vector>
#include <QLabel>
#include "../model/Game.h"

/**
 * @class BoardView
 * @brief Représente l'interface visuelle du plateau de jeu Flood-It.
 *
 * Cette classe affiche le plateau de jeu de manière graphique, en utilisant des `QLabel`
 * pour représenter les cellules. Elle gère également l'organisation du plateau via un `QGridLayout`.
 */
class BoardView : public QWidget {
    Q_OBJECT

private:
    QGridLayout _gridLayout; ///< Disposition en grille du plateau.
    std::vector<std::vector<QLabel*>> _cells; ///< Matrice de labels représentant les cellules.
    Game& _game; ///< Référence au modèle de jeu.
    int _rows; ///< Nombre de lignes sur le plateau.
    int _cols; ///< Nombre de colonnes sur le plateau.

public:
    /**
     * @brief Constructeur de la classe BoardView.
     * @param game Référence à l'objet Game contenant la logique du jeu.
     * @param parent Widget parent (optionnel).
     */
    explicit BoardView(Game& game, QWidget* parent = nullptr);

    /**
     * @brief Affiche les cellules du plateau de jeu.
     *
     * Cette méthode permet d'actualiser visuellement les cellules du plateau en fonction
     * de l'état actuel du jeu.
     */
    void printCells();
};

#endif // BOARDVIEW_H
