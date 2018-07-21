#include "sapermap.h"
#include <cstdlib>
#include <ctime>
#include <exception>



namespace Saper{


void Map::countMinesNeighbors()
{

    for(unsigned j=0; j < sizeX; j++)
    {
        for(unsigned k = 0; k < sizeY; k++)
        {
            if(map[j][k].isMine()) continue;
                 map[j][k].setValue(countNeighbors(j,k));
        }
    }
}


Map::Map(unsigned int x, unsigned int y) :sizeY(y), sizeX(x)
{
    for(unsigned j=0; j < x; j++)
    {
        map.push_back(std::vector< Field > () );
        for(unsigned k = 0; k < y; k++)
        {
            map[j].push_back( Field() );
        }
    }
}



void Map::setBombsOnMap(unsigned int mineNumber)
{
    int x, y;
    if(mineNumber > sizeX)
    {
        throw std::exception ("something went wrong. Too many mines");
    }

    while(mineNumber)
    {
        x = rand()% sizeX;
        y = rand()% sizeY;

        if(map[x][y].isMine()) continue;
        else map[x][y].setMine();
        mineNumber--;
    }

}
bool Map::isOutOfBound(unsigned int x, unsigned int y)
{
    if(x<0 || y<0 || x > sizeX-1 || y > sizeY-1) return true;
    return false;
}

CountMine Map::countNeighbors(unsigned int x, unsigned int y)
{
    int counter=0;
    if (!isOutOfBound(x-1, y) && map[x-1][y].isMine()) counter++;
    if (!isOutOfBound(x+1, y) && map[x+1][y].isMine()) counter++;
    if (!isOutOfBound(x, y-1) && map[x][y-1].isMine()) counter++;
    if (!isOutOfBound(x-1, y+1) && map[x-1][y+1].isMine()) counter++;
    if (!isOutOfBound(x-1, y-1) && map[x-1][y-1].isMine()) counter++;
    if (!isOutOfBound(x+1, y-1) && map[x+1][y-1].isMine()) counter++;
    if (!isOutOfBound(x+1, y+1) && map[x+1][y+1].isMine()) counter++;
    if (!isOutOfBound(x, y+1) && map[x][y+1].isMine()) counter++;

    return static_cast<CountMine>(counter);


}





}
