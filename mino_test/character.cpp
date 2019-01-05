#include "character.h"
#include "iostream"

Character::Character(QWidget *parent) :
    QWidget(parent),
    x_pix(0),
    y_pix(0),
    x_map(0),
    y_map(0),
    state(state_stop),
    direction(dir_down),
    characterSprite(new Sprite(this, QString(PATH) + "Minotaur.png" ,0,0,200,{70,5,15,10})),
    speed(1.0)
{
    this->setFocus();
}

Sprite * Character::getSprite() const
{
    return (this->characterSprite);
}

void Character::startControls()
{
    this->grabKeyboard();
}

void Character::stopControls()
{
    this->releaseKeyboard();
}

void Character::keyPressEvent(QKeyEvent * event)
{
    switch(event->key()){
        case Qt::Key_Down   : this->go(dir_down);   break;
        case Qt::Key_Left   : this->go(dir_left);   break;
        case Qt::Key_Right  : this->go(dir_right);  break;
        case Qt::Key_Up     : this->go(dir_up);     break;
    default : break;
    }
}

void Character::go(DIRECTION dir)
{
    std::cout << dir << std::endl;
    this->setState(state_run);
    this->setDirection(dir);
}

void Character::setDirection(DIRECTION dir)
{
    this->characterSprite->setLinefromSprite(dir);
}

void Character::setState(STATE state)
{
    switch (state){
        case (state_run) :
        {
            this->characterSprite->setSprite(QString(PATH) + RUNNING_CHARSET);
            this->characterSprite->setRandomAnims(0);
            this->characterSprite->setPeriod(SPRITE_STD_RUN_REFRESH);
            break;
        }
        case (state_stop) :
        {
            this->characterSprite->setSprite(QString(PATH) + DEFAULT_CHARSET);
            this->characterSprite->setRandomAnims(1);
            this->characterSprite->setPeriod(SPRITE_STD_REFRESH);
            break;
        }
    }
}
