#include "staticsprite.h"
#include "main.h"

StaticSprite::StaticSprite(QObject *parent, const QString& filename, const int x , const int y)
    : QObject(parent),
      spriteImage(QPixmap(TILE_SIZE*SPRITE_COLUMNS,TILE_SIZE*SPRITE_LINES)),
      x_anim(x),
      line_anim(y)
{

    this->currentImage = new QGraphicsPixmapItem();

    this->spriteImage.load(filename);

}

StaticSprite::~StaticSprite()
{
    delete(this->currentImage);
}

QGraphicsPixmapItem * StaticSprite::representation()
{
    return (this->currentImage);
}

void StaticSprite::setSprite(const QString& filename)
{
    this->spriteImage.load(filename);
}

void StaticSprite::setPos(const qreal x, const qreal y)
{
    this->currentImage->setPos(x,y);
}

QPointF StaticSprite::getPos() const
{
    return (this->currentImage->pos());
}

void StaticSprite::setLinefromSprite(const int line)
{
    this->line_anim = line;
    this->x_anim = 0;

    const QPixmap temp = spriteImage.copy(0*TILE_SIZE, line*TILE_SIZE, TILE_SIZE, TILE_SIZE);

    this->currentImage->setPixmap(temp);

}

void StaticSprite::setImageFromSprite(const int column, const int line)
{
    this->x_anim = column;
    this->line_anim = line;
    this->currentImage->setPixmap(spriteImage.copy(column*TILE_SIZE, line*TILE_SIZE, TILE_SIZE, TILE_SIZE));
}

void StaticSprite::setNextImage()
{
    this->x_anim++;
    if ( this->x_anim == SPRITE_COLUMNS)
    {
        this->x_anim = 0;
    }

    this->setImageFromSprite(this->x_anim,this->line_anim);
}

void StaticSprite::update()
{
    //emit this->draw(this->representation());
}
