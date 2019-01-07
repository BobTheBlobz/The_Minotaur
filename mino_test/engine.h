#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

#include "character.h"
#include "map.h"
#include "main.h"
#include "array"
#include "iostream"

class Engine : public QObject
{
    Q_OBJECT

private:
    QGraphicsScene * scene;
    QTimer * timer;

    Character * character;
    Map<11> * map;

    std::array<int,2> character_speed;
    bool character_moving;

    bool running;
    int period;

public:
    explicit Engine(QObject *parent = nullptr);

    void start();
    void stop();

    void setCharacter(Character*& cha);
    template<unsigned int x>
    void setMap(Map<x> *& map)
    {
        Map<11>::copyFrom(this->map, map);

    }


    void setScene(QGraphicsScene*& scene);
    QGraphicsScene* getScene() const;

    void drawScene();


    bool isRunning() const;

signals:

public slots:

    void advance();
    void character_move(int dir);
    void character_stop();
    void character_walk_tile(unsigned int, unsigned int);
    void character_collision(unsigned int, unsigned int, int);

};



#endif // ENGINE_H
