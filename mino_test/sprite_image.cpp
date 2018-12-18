#include "sprite_image.h"

Sprite_image::Sprite_image(QWidget *parent):
    QLabel(parent)
{

}

void Sprite_image::update(const QPixmap * img){
    this->setPixmap(*img);
    this->show();
    this->raise();
}
