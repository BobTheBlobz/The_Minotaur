#include "tileempty.h"

TileEmpty::TileEmpty(QPixmap * const tileset) :
    Tile()
{
    this->block = {false, false, false, false};
    this->tilesetIndex = {1,0};
    this->initRepresentation(tileset);
}

TileEmpty::~TileEmpty()
{
}

