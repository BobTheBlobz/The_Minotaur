#ifndef CHARACTER_H
#define CHARACTER_H

#include <QWidget>
#include <QKeyEvent>
#include "sprite.h"
#include "staticsprite.h"

class Character : public QWidget
{
    Q_OBJECT

private:
    enum STATE {state_run, state_stop};
    enum DIRECTION {dir_down = 0, dir_right = 1, dir_left = 2, dir_up = 3};

    unsigned int x_pix;
    unsigned int y_pix;
    unsigned int x_map;
    unsigned int y_map;
    STATE state;
    DIRECTION direction;

    Sprite * characterSprite;

    float speed;

public:
    explicit Character(QWidget *parent = nullptr);

    Sprite * getSprite() const;

    void startControls();
    void stopControls();

    void go(DIRECTION dir);

    void setDirection(DIRECTION dir);
    void setState(STATE state);

    void keyPressEvent(QKeyEvent * event);

signals:

public slots:

};

#endif // CHARACTER_H
