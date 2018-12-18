#include "tileempty.h"

TileEmpty::TileEmpty(char * t) : Tile(t)
{
    this->representation = QPixmap(TILE_SIZE, TILE_SIZE);
    this->tilesetIndex = {0,0};
    this->block = {true, true, true, true};

}

bool TileEmpty::isBlocking(int direction)
{
    return block[direction];
}

QPixmap TileEmpty::getRepresentation()
{
    return(representation);
}

