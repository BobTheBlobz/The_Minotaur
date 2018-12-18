#include "map.h"

template<int SIZE>
Map<SIZE>::Map(char * Tileset):
    Tileset(QPixmap(TILE_SIZE*SPRITE_COLUMNS,TILE_SIZE*SPRITE_LINES))
{
    this->Tileset.load(Tileset);
}

template<int SIZE>
Map<SIZE>::~Map()
{
}

template<int SIZE>
Map<SIZE>::Map(const Map&)
{
}

template<int SIZE>
int Map<SIZE>::getSize() const
{
    return SIZE;
}

template<int SIZE>
Tile * Map<SIZE>::getTile(int x,int y)
{
    return (this->matrix.at(x).at(y));
}

template<int SIZE>
std::array<Tile*, SIZE > Map<SIZE>::getLine(int x)
{
    return (this->matrix.at(x));
}

template<int SIZE>
std::array<Tile*, SIZE > Map<SIZE>::operator[](int x)
{
    return (this->matrix.at(x));
}

template<int SIZE>
void Map<SIZE>::UpdateRepresentation()
{
    QPainter paint = QPainter(this->representation.pixmap());
    for(int i; i<SIZE; i++)
    {
        for(int j; j<SIZE; j++)
        {
            // ICI : Faire fonctionner le Qpainter qui travaille sur la map;
            paint.drawPixmap(QRect(i*TILE_SIZE, j*TILE_SIZE, (i+1)*TILE_SIZE, (j+1)*TILE_SIZE), this->getTile(i,j)->getRepresentation());
        }
    }
}


template class Map<8>;
template class Map<5>;
template class Map<11>;
