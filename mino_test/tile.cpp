#include "tile.h"

Tile::Tile(char * tileset){
    QPixmap tile = QPixmap(tileset);
    this->representation = tile.copy(tilesetIndex[0] , tilesetIndex[1], TILE_SIZE, TILE_SIZE);
}
