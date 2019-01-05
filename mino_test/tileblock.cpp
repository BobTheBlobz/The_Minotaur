#include "tileblock.h"

TileBlock::TileBlock(QPixmap * const tileset) :
    Tile()
{
    block = {false, false, false, false};
    tilesetIndex = {0,1};
    this->initRepresentation(tileset);
}

TileBlock::~TileBlock()
{
}
