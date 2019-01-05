#ifndef SPRITE_IMAGE_H
#define SPRITE_IMAGE_H

#include <QWidget>
#include <QLabel>
#include "main.h"

class Sprite_image : public QLabel
{
    Q_OBJECT

public:
    Sprite_image(QWidget *parent = nullptr);

public slots:
    void update(const QPixmap * img);

};

#endif // SPRITE_IMAGE_H
