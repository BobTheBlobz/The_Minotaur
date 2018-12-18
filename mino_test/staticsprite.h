#ifndef STATICSPRITE_H
#define STATICSPRITE_H

#include <QObject>
#include <QPixmap>
#include <QPointF>
#include "graphicentity.h"

class StaticSprite : public QObject
{
    Q_OBJECT

protected:

    QPixmap spriteImage;

    QGraphicsPixmapItem * currentImage;

    int x_anim, line_anim;

public:
    explicit StaticSprite(QObject *parent = nullptr, const QString& filename = "", const int x = 0, const int y = 0);
    ~StaticSprite();

    QGraphicsPixmapItem * representation();

    QPointF getPos() const;

    void setPos(const qreal x, const qreal y);
    void setSprite(const QString& filename);
    void setLinefromSprite(const int line);
    void setImageFromSprite(const int column, const int line);
    void setNextImage();

signals:
    void draw(const QPixmap img);

public slots:
    void update();

};

#endif // STATICSPRITE_H
