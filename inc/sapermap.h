#ifndef SAPERMAP_H
#define SAPERMAP_H
#include "field.h"
#include <vector>

namespace Saper
{
typedef std::vector< std::vector< Saper::Field > >  Board;

class Map
{
public:
    Map(unsigned int, unsigned int);
    Board map;
    void setBombsOnMap(unsigned int);
    void countMinesNeighbors();
private:
    const unsigned int sizeX, sizeY;
    CountMine countNeighbors(unsigned int, unsigned int);
    bool isOutOfBound(unsigned int, unsigned int);


};

}

#endif // SAPERMAP_H
