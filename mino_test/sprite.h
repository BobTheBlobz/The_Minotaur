#ifndef SPRITE_H
#define SPRITE_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <QLabel>
#include "randomspritelinearray.h"
#include "staticsprite.h"

class Sprite : public StaticSprite
{
    Q_OBJECT

private:

    QTimer * timer;

    RandomSpriteLineArray randomlessness;

    bool randomanims;

public:
    explicit Sprite(QWidget *parent = nullptr, const QString& filename = "", const int x = 0, const int y = 0, const int period = SPRITE_STD_REFRESH, RandomSpriteLineArray anim = {0,0,0,0}, bool randomanims = true );
    ~Sprite();

    void setPeriod(const int = SPRITE_STD_REFRESH);
    void setNextImage();
    void setRandomAnims(const bool& b = 1);

    void getRandomLine();
    bool isRandomAnims() const;

    void startTimer();
    void stopTimer();

signals:
    void draw(const QPixmap * img);

public slots:
    void update();

};

#endif // SPRITE_H
