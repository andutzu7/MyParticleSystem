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
const float GetX()
{
    return position.x;
}
const float GetY()
{
    return position.y;
}
const Vec2 GetPosition()
{
    return position;
}
void Update(float new_x,float new_y)
{
position.x=new_x;
position.y=new_y;
}
};
