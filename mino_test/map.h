#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPainter>

#include "tile.h"
#include "main.h"


template<int SIZE> class Map
{
private:
    QPixmap Tileset;

protected:

    QGraphicsPixmapItem representation;
    static const int size = SIZE;
    std::array< std::array<Tile*, SIZE> , SIZE> matrix;

public:
    Map(char * Tileset = DEFAULT_TILESET);
    ~Map();
    Map(const Map& m);

    void UpdateRepresentation();

    Tile * getTile(int x,int y);
    int getSize() const;

    std::array<Tile*, SIZE > virtual getLine(int x);
    std::array<Tile*, SIZE > virtual operator[](int x);

};

#endif // MAP_H
