#include "MapArray.h"

MapArray::MapArray()
{
    const static int w = Define::OUT_W / 100;
    const static int h = Define::OUT_H / 100;
    for (int i = 1; i < w * h; i++)
    {
        _mapState.push_back(Nothing);
    }
}

bool MapArray::update()
{
    enemy();
    Friend();
	return true;
}

void MapArray::draw() const
{

}

void MapArray::calculation(int _x, int _y)
{
    int x, y, i;
    
    x = _x / 100 + 1;
    y = _y / 100 + 1;

    i = x + 5 * (y - 1);

    _mapState[i] = Enemy;

    /*
    x = i % 5;
    y = i / 5 + 1;

    _x = (x - 1) * 100 + 50;
    _y = (x - 1) * 100 + 50;
    */

}

void MapArray::enemy()
{
    int  _x1 = 350, _y1 = 50;
    calculation(_x1, _y1);
}

void MapArray::Friend()
{
    int _x2 = 250, _y2 = 850;
    calculation(_x2, _y2);
}