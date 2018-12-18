#ifndef TILE_H
#define TILE_H

#include <QPixmap>
#include "main.h"
#include "array"


class Tile
{

protected:
    static std::array<bool,4> block;
    static QPixmap representation;
    static const std::array<int,2> tilesetIndex;

public:
    bool virtual isBlocking(int direction) = 0;
    QPixmap virtual getRepresentation() = 0;

    Tile(char * tileset = DEFAULT_TILESET);
};

#endif // TILE_H
