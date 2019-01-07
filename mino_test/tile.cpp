#include "tile.h"
#include "iostream"

Tile::~Tile()
{
}

Tile::Tile() :
    block({true,true,true,true}),
    tilesetIndex({0,0})
{
}

QPixmap Tile::getRepresentation() const {
    return (this->representation);
}

bool Tile::isBlocking(int x) const {
    return ((unsigned int) this->block[x]);
}

void Tile::initRepresentation(QPixmap * const tileset)
{
    this->representation = tileset->copy(QRect(this->tilesetIndex[0]*TILE_SIZE, this->tilesetIndex[1]*TILE_SIZE, TILE_SIZE, TILE_SIZE));
}

void Tile::onWalk()
{
}
