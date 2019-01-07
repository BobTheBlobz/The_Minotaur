#include "tileblock.h"

TileBlock::TileBlock(QPixmap * const tileset) :
    Tile()
{
    block = {true, true, true, true};
    tilesetIndex = {0,1};
    this->initRepresentation(tileset);
}

TileBlock::~TileBlock()
{
}
