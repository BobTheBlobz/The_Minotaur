#include "map.h"

template<const unsigned int SIZE>
const int Map<SIZE>::size = SIZE;

template<const unsigned int SIZE>
Map<SIZE>::Map(QString Tile) :
    Tileset(new QPixmap(TILE_SIZE*SPRITE_COLUMNS,TILE_SIZE*SPRITE_LINES)),
    map_pixmap(new QPixmap(SIZE*TILE_SIZE, SIZE*TILE_SIZE)),
    representation(new QGraphicsPixmapItem(*map_pixmap))
{
    this->Tileset->load(Tile);
    this->initMap();
}

template<const unsigned int SIZE>
Map<SIZE>::~Map()
{
}

template<const unsigned int SIZE>
Map<SIZE>::Map(const Map<SIZE>& m)
{
    for(unsigned int i = 0; i<SIZE; i++)
    {
        for(unsigned int j = 0; j<SIZE; j++)
        {
            this->matrix.at(i).at(j) = m.matrix.at(i).at(j);
        }
    }
}

template<const unsigned int SIZE>
int Map<SIZE>::getSize() const
{
    return SIZE;
}

template<const unsigned int SIZE>
Tile * Map<SIZE>::tile(const unsigned int x, const unsigned int y)
{
    return (this->matrix.at(x).at(y));
}

template<const unsigned int SIZE>
void Map<SIZE>::setTile(const unsigned int x, const unsigned int y, Tile::TYPE tile_type)
{
    switch (tile_type)
    {
        case Tile::type_empty : matrix.at(x).at(y) = new Tile(); break;
        case Tile::type_clear : matrix.at(x).at(y) = new TileEmpty(this->Tileset); break;
        case Tile::type_block : matrix.at(x).at(y) = new TileBlock(this->Tileset); break;
    }
}

template<const unsigned int SIZE>
std::array<Tile*, SIZE > Map<SIZE>::getLine(const unsigned int x)
{
    return (this->matrix.at(x));
}

template<const unsigned int SIZE>
std::array<Tile*, SIZE > Map<SIZE>::operator[](const unsigned int x)
{
    return (this->matrix.at(x));
}

template<const unsigned int SIZE>
void Map<SIZE>::initMap()
{

    for(unsigned int i = 0; i<SIZE; i++)
    {
        for(unsigned int j = 0; j<SIZE; j++)
        {
            this->setTile(i,j, Tile::type_clear);
        }
    }

    this->updateRepresentation();
}


template<const unsigned int SIZE>
void Map<SIZE>::updateRepresentation()
{
    QPainter painter(this->map_pixmap);

    for(unsigned int i = 0; i<SIZE; i++)
    {
        for(unsigned int j = 0; j<SIZE; j++)
        {
            painter.drawPixmap(QRect(i*TILE_SIZE, j*TILE_SIZE, TILE_SIZE, TILE_SIZE), this->tile(i,j)->getRepresentation());
        }
    }

    this->representation->setPixmap(* this->map_pixmap);
}



