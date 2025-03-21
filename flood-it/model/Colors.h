#ifndef COLORS_H
#define COLORS_H


#include <vector>
#include <QColor>

enum class Colors {
    BLUE,
    GREEN,
    RED,
    YELLOW,
    MAGENTA,
    CYAN,
};

std::vector<Colors> getAllColors();
/**
 * @brief Convertit une couleur `Colors` en `QColor` utilisable par Qt.
 * @param color Couleur à convertir.
 * @return La couleur correspondante en `QColor`.
 */
inline QColor toQColor(Colors color) {
    switch (color) {
    case Colors::RED: return QColor(Qt::red);
    case Colors::GREEN: return QColor(Qt::green);
    case Colors::BLUE: return QColor(Qt::blue);
    case Colors::YELLOW: return QColor(Qt::yellow);
    case Colors::CYAN: return QColor(Qt::cyan);
    case Colors::MAGENTA: return QColor(Qt::magenta);
    default: return QColor(Qt::black);
    }
}
inline Colors toColors(QColor qcolor){
    if (qcolor == QColor(Qt::red)) return Colors::RED;
    if (qcolor == QColor(Qt::green)) return Colors::GREEN;
    if (qcolor == QColor(Qt::blue)) return Colors::BLUE;
    if (qcolor == QColor(Qt::yellow)) return Colors::YELLOW;
    if (qcolor == QColor(Qt::cyan)) return Colors::CYAN;
    if (qcolor == QColor(Qt::magenta)) return Colors::MAGENTA;

    // Par défaut, retourne une couleur par défaut (optionnel selon vos besoins)
    throw std::invalid_argument("Unknown QColor provided!");
}

#endif // COLORS_H




