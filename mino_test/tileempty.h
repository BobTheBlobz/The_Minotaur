#ifndef TILEEMPTY_H
#define TILEEMPTY_H

#include <QPixmap>
#include "main.h"
#include "array"
#include "tile.h"

class TileEmpty : public Tile
{
public:
    TileEmpty(char * tileset = DEFAULT_TILESET);


    bool isBlocking(int direction);
    QPixmap getRepresentation();
};

#endif // TILEEMPTY_H
