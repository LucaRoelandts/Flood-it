#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>
#include "Colors.h"

/**
 * @struct Settings
 * @brief Représente les paramètres de configuration d'une partie de Flood-It.
 *
 * Cette structure encapsule les dimensions du plateau, le nombre de couleurs disponibles,
 * ainsi que la palette de couleurs choisie pour le jeu.
 */
struct Settings {
    int height {10}; ///< Hauteur du plateau (par défaut : 10).
    int width {10};  ///< Largeur du plateau (par défaut : 10).
    int nbOfColors;  ///< Nombre total de couleurs disponibles.
    std::vector<Colors> colors; ///< Palette de couleurs choisie parmi l'énumération Colors.
};

#endif // SETTINGS_H
