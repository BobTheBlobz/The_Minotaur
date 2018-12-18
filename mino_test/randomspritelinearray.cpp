#include "randomspritelinearray.h"

#include "main.h"
#include "array"

RandomSpriteLineArray::RandomSpriteLineArray(unsigned int chanceline1,unsigned int chanceline2,unsigned int chanceline3,unsigned int chanceline4)
    : std::array<unsigned int, SPRITE_LINES>({chanceline1,chanceline2,chanceline3,chanceline4})
{
    unsigned int s=0;
    for(unsigned int i=0; i< SPRITE_LINES; i++)
        s += this->at(i);

    this->sumOfChances = s;
}

RandomSpriteLineArray::RandomSpriteLineArray(const array<unsigned int, SPRITE_LINES>& arr)
    :  std::array<unsigned int, SPRITE_LINES>(arr)
{
    unsigned int s=0;
    for(unsigned int i=0; i< SPRITE_LINES; i++)
        s += this->at(i);

    this->sumOfChances = s;
}

RandomSpriteLineArray::RandomSpriteLineArray(const RandomSpriteLineArray& arr)
    : std::array<unsigned int, SPRITE_LINES>(arr)
{
    this->sumOfChances = arr.getSumOfChances();
}

unsigned int RandomSpriteLineArray::getSumOfChances() const
{
    return this->sumOfChances;
}

unsigned int RandomSpriteLineArray::getRandomLine() const
{
    int r = int(rand() % (this->sumOfChances));
    int sum = 0;

    unsigned int line = 0;
    sum = sum + int (this->at(line));
    while (sum <= r)
    {
        line++;
        sum = sum + int (this->at(line));
    }

    return line;
}
