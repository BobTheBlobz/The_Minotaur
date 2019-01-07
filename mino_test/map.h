#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPainter>

#include "tile.h"
#include "tileempty.h"
#include "tileblock.h"

#include "main.h"
#include "iostream"


template<const unsigned int SIZE> class Map
{
private:
    QPixmap * Tileset;
    QPixmap * map_pixmap;

protected:

    static const int size;

public:

    std::array< std::array<Tile*, SIZE> , SIZE> matrix;

    template<const unsigned int SIZE2>
    static void copyFrom(Map<SIZE> * map1, Map<SIZE2> * map2)
    {
        if (SIZE > SIZE2)
        {
            unsigned int diff = (SIZE - SIZE2)/2;

            for(unsigned int i = 0; i<SIZE; i++)
            {
                for(unsigned int j = 0; j<SIZE; j++)
                {
                    if ((i<diff) || (j<diff) || (i>=SIZE-diff) || (j>=SIZE-diff))
                    {
                        map1->setTile(i,j, Tile::type_block);
                    }
                    else
                    {
                        map1->matrix.at(i).at(j) = map2->matrix.at(i-diff).at(j-diff);
                    }
                }
            }

            map1->startPos[0]=map2->startPos[0]+diff;
            map1->startPos[1]=map2->startPos[1]+diff;
        }
        else
        {

            for(unsigned int i = 0; i<SIZE; i++)
            {
                for(unsigned int j = 0; j<SIZE; j++)
                {
                    map1->matrix.at(i).at(j) = map2->matrix.at(i).at(j);
                }
            }

            map1->startPos=map2->startPos;
       }

    }

    std::array<unsigned int, 2> startPos;

    Map(QString Tile = (QString(PATH) + DEFAULT_TILESET), std::array<unsigned int, 2> startPos = {0,0});
    ~Map();

    template<const unsigned int SIZE2> Map(const Map<SIZE2> &m);

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
template class Map<7>;
template class Map<8>;
template class Map<9>;
template class Map<11>;

#endif // MAP_H

