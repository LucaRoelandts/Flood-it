#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QApplication>
#include <QPushButton>
#include "floot_itview.h"
#include "SettingsView.h"
#include "../util/Observer.h"

/**
 * @class MainWindow
 * @brief Représente la fenêtre principale de l'application Flood-It.
 *
 * Cette classe combine les différentes vues et gère l'interaction entre les paramètres,
 * le jeu, et les options d'affichage.
 */
class MainWindow : public QMainWindow, public Observer {
    Q_OBJECT

private:
    Game* _game; ///< Pointeur vers l'objet Game, contenant la logique du jeu.
    Settings _currentSettings; ///< Paramètres actuels de la configuration du jeu.
    Colors _currentColor; ///< Couleur actuellement sélectionnée par l'utilisateur.
    QWidget _rootWidget; ///< Widget racine de la fenêtre principale.
    QGridLayout _rootLayout; ///< Disposition en grille pour organiser les sous-vues.
    SettingsView* _settingsView; ///< Vue pour configurer les paramètres du jeu.
    Floot_ItView* _flootitView; ///< Vue principale du jeu Flood-It.
    QPushButton* _startGameBtn; ///< Bouton pour démarrer une nouvelle partie.

public:
    /**
     * @brief Constructeur de la classe MainWindow.
     * @param parent Widget parent (optionnel).
     */
    explicit MainWindow(QWidget* parent = nullptr);

    /**
     * @brief Destructeur de la classe MainWindow.
     */
    ~MainWindow() override;

    /**
     * @brief Méthode appelée pour mettre à jour l'état de la fenêtre après un changement.
     */
    void update() override;

private:
    /**
     * @brief Initialise les composants de la fenêtre principale.
     */
    void init();

    /**
     * @brief Gestion du bouton de démarrage du jeu.
     */
    void startBtn();

    /**
     * @brief Supprime la vue des paramètres.
     */
    void delSettingsView();

    /**
     * @brief Initialise le jeu avec les paramètres actuels.
     */
    void initGame();

    /**
     * @brief Applique la sélection d'une couleur par l'utilisateur.
     * @param color Couleur sélectionnée.
     */
    void selectColor(Colors& color);

    /**
     * @brief Initialise les boutons associés aux couleurs dans l'interface.
     */
    void initColorButtons();

    /**
     * @brief Sauvegarde le score de l'utilisateur.
     * @param score Le score à sauvegarder.
     */
    void saveScore(int score);
};

#endif // MAINWINDOW_H
