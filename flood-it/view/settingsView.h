#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include <QWidget>
#include <QSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include "../model/settings.h"

/**
 * @class SettingsView
 * @brief Représente l'interface utilisateur pour configurer les paramètres du jeu Flood-It.
 *
 * Cette classe permet aux utilisateurs de définir la largeur, la hauteur et le nombre de couleurs
 * du plateau de jeu via une interface graphique intuitive.
 */
class SettingsView : public QWidget {
    Q_OBJECT

private:
    QFormLayout _layout; ///< Disposition en formulaire pour organiser les éléments de l'interface.
    QLabel _widthLabel; ///< Étiquette pour indiquer la largeur du plateau.
    QSpinBox _widthSB; ///< Boîte de sélection pour définir la largeur du plateau.
    QLabel _heightLabel; ///< Étiquette pour indiquer la hauteur du plateau.
    QSpinBox _heightSB; ///< Boîte de sélection pour définir la hauteur du plateau.
    QLabel _nbOfColorsLabel; ///< Étiquette pour indiquer le nombre de couleurs.
    QComboBox _nbOfColors; ///< Boîte de sélection pour choisir le nombre de couleurs disponibles.

public:
    /**
     * @brief Constructeur de SettingsView.
     * @param parent Le widget parent (optionnel).
     */
    explicit SettingsView(QWidget* parent = nullptr);

    /**
     * @brief Obtient les paramètres actuels définis par l'utilisateur.
     * @return Un objet Settings contenant les valeurs sélectionnées.
     */
    Settings getSettings();

    /**
     * @brief Destructeur de la classe SettingsView.
     */
    ~SettingsView() override;

private:
    /**
     * @brief Génère un ensemble aléatoire de couleurs.
     * @param count Nombre de couleurs à générer.
     * @return Un vecteur contenant les couleurs générées.
     */
    std::vector<Colors> getRandomColors(int count);
};

#endif // SETTINGSVIEW_H
