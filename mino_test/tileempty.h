#ifndef TILEEMPTY_H
#define TILEEMPTY_H

#include <QPixmap>
#include "main.h"
#include "array"
#include "tile.h"

class TileEmpty : public Tile
{
public:
    TileEmpty(QPixmap * const tileset);
    virtual ~TileEmpty();
};

#endif // TILEEMPTY_H
