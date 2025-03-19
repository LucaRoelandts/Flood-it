#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>
#include "Colors.h"
struct Settings
{
    int height {10};
    int width {10};
    int nbOfColors;
    std::vector<Colors> colors;
};

#endif // SETTINGS_H
