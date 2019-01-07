#include "classfactory.h"

ClassFactory::ClassFactory()
{

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

