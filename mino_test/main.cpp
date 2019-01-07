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
#include "engine.h"
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

    //std::cout << "debut" << std::endl;


    Character * minotaur = new Character();

    //std::cout << "mino chargé" << std::endl;

    constexpr const unsigned int x = 5;
    Map<x> * m = ClassFactory::makeCustomMap<x>(QString(PATH) + DEFAULT_TILESET);

    m->setTile(1,0,Tile::type_block);
    m->setTile(1,2,Tile::type_block);
    m->setTile(3,4,Tile::type_block);
    m->setTile(2,0,Tile::type_block);
    m->setTile(4,1,Tile::type_block);

    //std::cout << "map" << std::endl;

    QGraphicsScene * scene = new QGraphicsScene();

    //std::cout << "scene" << std::endl;
    Engine engine(&a);

    //::cout << "engine" << std::endl;
    engine.setCharacter(minotaur);
    //std::cout << "setchara" << std::endl;
    engine.setMap(m);
    //std::cout << "setmap" << std::endl;
    engine.setScene(scene);
    //std::cout << "setscene" << std::endl;
    engine.drawScene();
    //std::cout << "drawscene" << std::endl;
    engine.start();

    QGraphicsView view(engine.getScene());

    view.show();


    //std::cout << "fin" << std::endl;

    return a.exec();
}
