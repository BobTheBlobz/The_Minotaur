#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPainter>

#include "tile.h"
#include "tileempty.h"
#include "tileblock.h"

#include "main.h"


template<const unsigned int SIZE> class Map
{
private:
    QPixmap * Tileset;
    QPixmap * map_pixmap;

protected:

    static const int size;
    std::array< std::array<Tile*, SIZE> , SIZE> matrix;

public:

    Map(QString Tile = (QString(PATH) + DEFAULT_TILESET));
    ~Map();
    Map(const Map<SIZE> &m);

    void initMap();
    void updateRepresentation();
    QGraphicsPixmapItem * representation;

    Tile * tile(const unsigned int x, const unsigned int y);
    void setTile(const unsigned int x, const unsigned int y, Tile::TYPE tile);

    int getSize() const;
    std::array<Tile*, SIZE > getLine(const unsigned int x);
    std::array<Tile*, SIZE > operator[](const unsigned int x);

};


template class Map<5>;
template class Map<8>;
template class Map<11>;

#endif // MAP_H

