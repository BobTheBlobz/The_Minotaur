#include "mainwindow.h"
#include "main.h"
#include "sprite.h"
#include "sprite_image.h"
#include "graphicentity.h"
#include "map.h"
#include "classfactory.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>

#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(500,500,192,192);

    Sprite * test_sprite = new Sprite(&w, "../mino_test/Minotaur.png",0,0,200,{70,5,15,10});
    test_sprite->setPos(0*TILE_SIZE, 0*TILE_SIZE);
    Sprite * test_sprite2 = new Sprite(&w, "../mino_test/Minotaur_running.png",0,2,75,{0,0,1,0});
    test_sprite2->setPos(1*TILE_SIZE, 3*TILE_SIZE);
    Sprite * test_sprite3 = new Sprite(&w, "../mino_test/Minotaur_running.png",0,1,200,{0,1,0,0});
    test_sprite3->setPos(-1*TILE_SIZE, 3*TILE_SIZE);


    //Sprite_image * label = new Sprite_image(&w);
    //label->setGeometry(64,64,64,64);

    //w.show();
    //QObject::connect(test_sprite,SIGNAL(draw(const QPixmap)), label, SLOT(update(const QPixmap *)));

    //test_sprite->setLinefromSprite(2);

    const int x = SMALL_MAP_SIZE;
    Map<x> * m = ClassFactory::makeSmallMap(DEFAULT_TILESET);


    QGraphicsScene scene;
    scene.addItem(test_sprite->representation());
    scene.addItem(test_sprite2->representation());
    scene.addItem(test_sprite3->representation());

    QGraphicsView view(&scene);
    view.show();

    return a.exec();
}
