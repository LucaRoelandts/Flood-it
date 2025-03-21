#ifndef FLOOT_ITVIEW_H
#define FLOOT_ITVIEW_H

#include <QHBoxLayout>
#include "ColorsChoisesView.h"
#include "boardview.h"

/**
 * @class Floot_ItView
 * @brief Classe représentant la vue principale de l'interface graphique du jeu Flood-It.
 *
 * Cette classe combine les éléments visuels principaux, tels que la vue des choix de couleurs et
 * le plateau de jeu, dans une disposition horizontale.
 */
class Floot_ItView : public QWidget {
    Q_OBJECT

private:
    ColorsChoisesView* _colorChoisesView; ///< Vue des choix de couleurs disponibles.
    BoardView* _boardview; ///< Vue représentant le plateau de jeu.
    Game& _game; ///< Référence au modèle de logique du jeu.
    Settings _settings; ///< Paramètres de configuration du jeu.
    QHBoxLayout _layout; ///< Disposition horizontale pour organiser les vues.

public:
    /**
     * @brief Constructeur de la classe Floot_ItView.
     * @param s Paramètres de configuration du jeu.
     * @param game Référence à l'objet Game contenant la logique du jeu.
     * @param parent Widget parent (optionnel).
     */
    explicit Floot_ItView(Settings& s, Game& game, QWidget* parent = nullptr);

    /**
     * @brief Destructeur de la classe Floot_ItView.
     */
    ~Floot_ItView() override;

    /**
     * @brief Rafraîchit la vue pour refléter l'état actuel du jeu.
     */
    void refresh();

    /**
     * @brief Récupère les boutons représentant les choix de couleurs.
     * @return Un vecteur contenant des pointeurs vers les boutons des couleurs.
     */
    std::vector<QPushButton*> getColorsButtons();
};

#endif // FLOOT_ITVIEW_H
