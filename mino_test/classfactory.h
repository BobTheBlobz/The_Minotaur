#ifndef CLASSFACTORY_H
#define CLASSFACTORY_H

#include "main.h"
#include "map.h"


class ClassFactory
{
public:
    ClassFactory();

    template<int T> static Map<T> * makeCustomMap(QString tile = QString(PATH) + DEFAULT_TILESET)
    {
        Map<T> * mapPtr;
        mapPtr = new Map<T>(tile);
        return mapPtr;
    }

    static Map<SMALL_MAP_SIZE> * makeSmallMap(QString tile = QString(PATH) + DEFAULT_TILESET);
    static Map<MEDIUM_MAP_SIZE> * makeMediumMap(QString tile = QString(PATH) + DEFAULT_TILESET);
    static Map<LARGE_MAP_SIZE> * makeLargeMap(QString tile = QString(PATH) + DEFAULT_TILESET);
};

#endif // CLASSFACTORY_H
