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


#endif // COLORS_H




