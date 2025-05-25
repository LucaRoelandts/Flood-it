#ifndef COLORSCHOISESVIEW_H
#define COLORSCHOISESVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "../model/Colors.h"

/**
 * @class ColorsChoisesView
 * @brief Représente une interface utilisateur pour choisir les couleurs dans le jeu.
 *
 * Cette classe affiche un ensemble de boutons permettant aux utilisateurs de sélectionner une couleur
 * parmi une liste prédéfinie. Chaque bouton est associé à une couleur spécifique.
 */
class ColorsChoisesView : public QWidget {
    Q_OBJECT

private:
    QGridLayout _layout; ///< Disposition en grille pour organiser les boutons de couleur.
    std::vector<QPushButton*> _buttons; ///< Liste des boutons représentant les couleurs disponibles.

public:
    /**
     * @brief Constructeur principal de ColorsChoisesView.
     * @param colors Liste des couleurs disponibles pour les boutons.
     * @param parent Widget parent (optionnel).
     */
    explicit ColorsChoisesView(const std::vector<Colors>& colors, QWidget* parent = nullptr);

    /**
     * @brief Constructeur par défaut.
     * @param parent Widget parent (optionnel).
     */
    ColorsChoisesView(QWidget* parent = nullptr);

    /**
     * @brief Récupère les boutons représentant les couleurs.
     * @return Un vecteur contenant des pointeurs vers les boutons.
     */
    std::vector<QPushButton*> getButtons();
};

#endif // COLORSCHOISESVIEW_H
