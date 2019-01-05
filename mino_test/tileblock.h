#ifndef TILEBLOCK_H
#define TILEBLOCK_H

#include <QPixmap>
#include "main.h"
#include "array"
#include "tile.h"

class TileBlock : public Tile
{
public:
    TileBlock(QPixmap * const tileset);
    virtual ~TileBlock();
};

#endif // TILEBLOCK_H
