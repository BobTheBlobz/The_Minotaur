#ifndef TILE_H
#define TILE_H

#include <QPixmap>
#include "main.h"
#include "array"


class Tile
{

protected:
    std::array<bool,4> block;
    std::array<int,2> tilesetIndex;
    QPixmap representation;

public:
    enum TYPE {
               type_empty,
               type_clear,
               type_block
    };

    bool virtual isBlocking(int direction) const;
    QPixmap getRepresentation() const;

    void onWalk();

    Tile();
    virtual ~Tile();
    void virtual initRepresentation(QPixmap * const tileset);
};

#endif // TILE_H
