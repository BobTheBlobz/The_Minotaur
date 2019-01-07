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
    speed(STD_CHAR_SPEED)
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
    if (this->state == state_stop)
    switch(event->key()){
        case Qt::Key_Down   :
        {
            this->direction = dir_down;
            emit character_move(dir_down);
            this->go(dir_down);
            break;
        }
        case Qt::Key_Left   :
        {
            this->direction = dir_left;
            emit character_move(dir_left);
            this->go(dir_left);
            break;
        }
        case Qt::Key_Right  :
        {
            this->direction = dir_right;
            emit character_move(dir_right);
            this->go(dir_right);
            break;
        }
        case Qt::Key_Up     :
        {
            this->direction = dir_up;
            emit character_move(dir_up);
            this->go(dir_up);
            break;
        }
        default : break;
        }
}

void Character::go(DIRECTION dir)
{
    this->setState(state_run);
    this->setDirection(dir);
    emit character_collision(x_map,y_map,dir);
}

void Character::stop()
{
    emit character_stop();
    this->setState(state_stop);
    this->x_pix = (x_map)*TILE_SIZE;
    this->y_pix = (y_map)*TILE_SIZE;
    this->characterSprite->setPos(x_pix,y_pix);
}

int Character::getSpeed() const
{
    return this->speed;
}


void Character::setSpeed(const int spe)
{
    this->speed = spe;
}

void Character::setDirection(DIRECTION dir)
{
    this->characterSprite->setLinefromSprite(dir);
}

void Character::setState(STATE state)
{
    this->state = state;
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

void Character::setPosPix(unsigned int const x, unsigned int const y)
{
    if((x_pix != x) || (y_pix != y))
    {
        this->x_pix = x;
        this->y_pix = y;
        this->x_map = (x+TILE_SIZE/2)/TILE_SIZE;
        this->y_map = (y+TILE_SIZE/2)/TILE_SIZE;
        this->characterSprite->setPos(x,y);
        this->mapPositionUpdate();
    }
}

void Character::setPosMap(unsigned int const x, unsigned int const y)
{
    if((x_map != x) || (y_map != y))
    {
        this->x_map = x;
        this->y_map = y;
        this->x_pix = x*TILE_SIZE;
        this->y_pix = y*TILE_SIZE;
        this->characterSprite->setPos(x*TILE_SIZE,y*TILE_SIZE);
        this->mapPositionUpdate();
    }
}

void Character::setPosPix(const std::array<unsigned int,2> pos)
{
    this->setPosPix(pos[0], pos[1]);
}

void Character::setPosMap(const std::array<unsigned int,2> pos)
{
    this->setPosMap(pos[0], pos[1]);
}

std::array<unsigned int, 2> Character::getPosPix() const
{
    return (std::array<unsigned int, 2>({this->x_pix, this->y_pix}));
}

std::array<unsigned int, 2> Character::getPosMap() const
{
    return (std::array<unsigned int, 2>({this->x_map, this->y_map}));
}

void Character::mapPositionUpdate()
{
    emit character_walk_tile(x_map,y_map);
    if (this->state == state_run)
    {
        unsigned int x_coll = x_pix;
        unsigned int y_coll = y_pix;
        unsigned int add = (this->speed);
        switch(this->direction){
            case 0 : y_coll+=add;     break;
            case 1 : x_coll+=add;     break;
            case 2 : x_coll-=add;     break;
            case 3 : y_coll-=add;     break;
        }
        emit character_collision(x_coll/TILE_SIZE,y_coll/TILE_SIZE, this->direction);
    }
}
