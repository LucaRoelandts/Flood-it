#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <vector>
#include <QLabel>
#include "../model/Game.h"


/**
 * @class BoardView
 * @brief Displays the game board visually using QLabel.
 */
class BoardView : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructor.
     * @param board Reference to the Board object.
     * @param parent Parent widget.
     */
    explicit BoardView(Game& game, QWidget *parent = nullptr);

    void printCells();

private:
    QGridLayout _gridLayout; ///< Grid layout for the board
    std::vector<std::vector<QLabel*>> _cells;///< Matrix of labels representing the cells
    Game& _game;
    size_t _rows;
    size_t _cols;



};

#endif // BOARDVIEW_H
