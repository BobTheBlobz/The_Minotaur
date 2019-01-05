#include "sprite.h"


Sprite::Sprite(QWidget *parent, const QString& filename, const int x , const int y, const int timer_period, RandomSpriteLineArray anim, bool randomanims)
    : StaticSprite(parent, filename, x, y),
      randomlessness(anim),
      randomanims(randomanims)
{

    this->timer = new QTimer(this);
    this->timer->setInterval(timer_period);

    QObject::connect(this->timer,SIGNAL(timeout()), this, SLOT(update()));

    this->startTimer();

    this->currentImage->setPos(x,y);

}

Sprite::~Sprite()
{}

void Sprite::setPeriod(const int period)
{
    this->timer->setInterval(period);
}

void Sprite::setNextImage()
{
    this->x_anim++;
    if ( this->x_anim == SPRITE_COLUMNS)
    {
        this->x_anim = 0;

        if (this->isRandomAnims())
        {
            this->line_anim = int (this->randomlessness.getRandomLine());
        }
    }

    this->setImageFromSprite(this->x_anim,this->line_anim);
}

void Sprite::setRandomAnims(const bool& b)
{
    this->randomanims = b;
}


bool Sprite::isRandomAnims() const
{
    return this->randomanims;
}


void Sprite::startTimer()
{
    this->timer->start();
}


void Sprite::stopTimer()
{
    this->timer->stop();
}

void Sprite::update()
{
    this->setNextImage();
    //emit this->draw(&(this->currentImage->pixmap()));
}
