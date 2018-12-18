#ifndef GRAPHICENTITY_H
#define GRAPHICENTITY_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "main.h"

class GraphicEntity : public QGraphicsPixmapItem
{

public:
    GraphicEntity(QGraphicsItem * parent = nullptr);

};

#endif // GRAPHICENTITY_H
