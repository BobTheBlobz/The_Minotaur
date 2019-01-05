#include "mainwindow.h"
#include "main.h"
#include "sprite.h"
#include "sprite_image.h"
#include "graphicentity.h"
#include "map.h"
#include "classfactory.h"
#include "tileempty.h"
#include "tileblock.h"
#include "character.h"
#include "iostream"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QString>

#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(0,0,500,500);

    std::cout << "debut" << std::endl;


    Character minotaur(&w);
    minotaur.getSprite()->setPos(0*TILE_SIZE, 0*TILE_SIZE);
    Sprite * test_sprite2 = new Sprite(&w, QString(PATH) + "Minotaur_running.png" ,0,2,75,{0,0,1,0});
    test_sprite2->setPos(1*TILE_SIZE, 3*TILE_SIZE);
    Sprite * test_sprite3 = new Sprite(&w, QString(PATH) + "Minotaur_running.png",0,1,200,{0,1,0,0});
    test_sprite3->setPos(2*TILE_SIZE, 3*TILE_SIZE);

    std::cout << "minos chargés" << std::endl;

    //QPixmap * pix = new QPixmap(QString(PATH) + DEFAULT_TILESET);

    QLabel label(&w);

    std::cout << "pixmap et tile" << std::endl;

    constexpr const unsigned int x = SMALL_MAP_SIZE;
    Map<x> * m = ClassFactory::makeSmallMap(QString(PATH) + DEFAULT_TILESET);

    m->setTile(1,0,Tile::type_block);
    m->setTile(1,2,Tile::type_block);
    m->setTile(3,4,Tile::type_block);
    m->setTile(2,0,Tile::type_block);
    m->setTile(4,1,Tile::type_block);

    m->updateRepresentation();

    std::cout << "map" << std::endl;

/*
    QPixmap pixmap(tile->getRepresentation());

    label.setGeometry(0,0,500,500);
    label.setPixmap(pixmap);

    std::cout << "label" << std::endl;

    label.show();
    w.show();
*/

    QGraphicsScene scene;

    scene.addItem(m->representation);

    scene.addItem(minotaur.getSprite()->representation());
    scene.addItem(test_sprite2->representation());
    scene.addItem(test_sprite3->representation());


    QGraphicsView view(&scene);
    view.show();

    minotaur.startControls();

    std::cout << "fin" << std::endl;

    return a.exec();
}
