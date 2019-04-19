#pragma once
#include "Point.h"

class focalPoint: public Point{
private:

public:
    focalPoint(float in_x,float in_y)
    {
        position.x=in_x;
        position.y=in_y;
    }
const int GetX() const
{
    return position.x;
}
const int getY() const
{
    return position.y;
}
void Update(float new_x,float new_y)
{
position.x=new_x;
position.y=new_y;
}
};
