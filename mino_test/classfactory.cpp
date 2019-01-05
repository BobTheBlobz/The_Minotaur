#include "classfactory.h"

ClassFactory::ClassFactory()
{

}

template<int T> Map<T> * ClassFactory::makeCustomMap(QString tile)
{
    Map<T> * mapPtr;
    mapPtr = new Map<T>(tile);
    return mapPtr;
}


Map<SMALL_MAP_SIZE> * ClassFactory::makeSmallMap(QString tile)
{
    return makeCustomMap<SMALL_MAP_SIZE>(tile);
}

Map<MEDIUM_MAP_SIZE> * ClassFactory::makeMediumMap(QString tile)
{
    return makeCustomMap<MEDIUM_MAP_SIZE>(tile);
}

Map<LARGE_MAP_SIZE> * ClassFactory::makeLargeMap(QString tile)
{
    return makeCustomMap<LARGE_MAP_SIZE>(tile);
}

