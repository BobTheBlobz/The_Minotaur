#ifndef RANDOMSPRITELINEARRAY_H
#define RANDOMSPRITELINEARRAY_H

#include "main.h"
#include <cstdlib>
#include "array"

class RandomSpriteLineArray: public std::array<unsigned int, SPRITE_LINES>
{
    unsigned int sumOfChances;

public:
    RandomSpriteLineArray(unsigned int chanceline1, unsigned int chanceline2, unsigned int chanceline3, unsigned int chanceline4);
    RandomSpriteLineArray(const array<unsigned int, SPRITE_LINES>& = {0,0,0,0});
    RandomSpriteLineArray(const RandomSpriteLineArray&);

    unsigned int getRandomLine() const;
    unsigned int getSumOfChances() const;


};

#endif // RANDOMSPRITELINEARRAY_H
