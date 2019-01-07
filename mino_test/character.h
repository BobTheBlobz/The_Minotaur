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

    unsigned int x_pix;
    unsigned int y_pix;
    unsigned int x_map;
    unsigned int y_map;
    int state;
    int direction;

    Sprite * characterSprite;

    int speed;

    void mapPositionUpdate();

public:

    enum STATE {state_run, state_stop};
    enum DIRECTION {dir_down = 0, dir_right = 1, dir_left = 2, dir_up = 3};
    explicit Character(QWidget *parent = nullptr);

    Sprite * getSprite() const;

    void startControls();
    void stopControls();

    void go(DIRECTION dir);
    void stop();

    void setDirection(DIRECTION dir);
    void setState(STATE state);
    void setPosPix(unsigned int const x, unsigned int const y);
    void setPosMap(unsigned int const x, unsigned int const y);
    void setPosPix(const std::array<unsigned int,2> pos);
    void setPosMap(const std::array<unsigned int,2> pos);
    void setSpeed (const int spe);
    std::array<unsigned int, 2> getPosPix() const;
    std::array<unsigned int, 2> getPosMap() const;
    int getSpeed() const;

    void keyPressEvent(QKeyEvent * event);

signals:

    void character_move(int);
    void character_stop();
    void character_walk_tile(unsigned int, unsigned int);
    void character_collision(unsigned int, unsigned int, int);

public slots:

};

#endif // CHARACTER_H
