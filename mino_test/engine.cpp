#include "engine.h"
#include "iostream"

Engine::Engine(QObject *parent) :
    QObject(parent),
    scene(nullptr),
    timer(new QTimer()),
    character(nullptr),
    map(new Map<11>()),
    character_speed({0,0}),
    character_moving(false),
    running(false),
    period(DEFAULT_PERIOD)
{
    this->timer->setInterval(period);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(advance()));
}

void Engine::start()
{
    this->timer->start();
    this->running = true;
    this->character->startControls();
}

void Engine::stop()
{
    this->timer->stop();
    this->running = false;
}

bool Engine::isRunning() const
{
    return(running);
}

void Engine::setCharacter(Character*& cha)
{
    this->character = cha;
    QObject::connect(character, SIGNAL(character_move(int)), this, SLOT(character_move(int)));
    QObject::connect(character, SIGNAL(character_stop()), this, SLOT(character_stop()));
    QObject::connect(character, SIGNAL(character_walk_tile(unsigned int, unsigned int)), this, SLOT(character_walk_tile(unsigned int, unsigned int)));
    QObject::connect(character, SIGNAL(character_collision(unsigned int, unsigned int, int)), this, SLOT(character_collision(unsigned int, unsigned int, int)));
}

void Engine::setScene(QGraphicsScene*& scene)
{
    this->scene = scene;
}

QGraphicsScene* Engine::getScene() const
{
   return this->scene;
}


void Engine::drawScene()
{
    this->map->updateRepresentation();
    this->character->setPosMap(this->map->startPos);

    this->scene->addItem(this->map->representation);
    this->scene->addItem(this->character->getSprite()->representation());

}

void Engine::advance()
{
    if(character_moving)
    {
        std::array<unsigned int, 2> pos = this->character->getPosPix();
        this->character->setPosPix(pos[0] + (character_speed[0]), pos[1] + (character_speed[1]));
    }

    if (scene != nullptr)
    {
        scene->advance();
    }
}

void Engine::character_move(int dir)
{
    this->character_moving = true;

    switch(dir){
        case 0 : character_speed = {0,this->character->getSpeed()};     break;
        case 1 : character_speed = {this->character->getSpeed(),0};     break;
        case 2 : character_speed = {0-(this->character->getSpeed()),0}; break;
        case 3 : character_speed = {0,0-(this->character->getSpeed())}; break;
    }
}

void Engine::character_stop()
{
    this->character_moving = false;
    this->character_speed = {0,0};
}

void Engine::character_walk_tile(unsigned int x, unsigned int y)
{
    this->map->tile(x,y)->onWalk();
}

void Engine::character_collision(unsigned int x, unsigned int y, int dir)
{
    switch(dir){
        case 0 : y++; break;
        case 1 : x++; break;
    default : break;
    }
    bool flag = this->map->tile(x,y)->isBlocking(dir) ;
    if (flag)
    {
        this->character->stop();
    }
}
