#pragma once
#include "focalPoint.h"
#include <utility>
#include <cmath>
typedef olc::Pixel Color;
class Particle{
private:
    Color c;
    int x;
    int y;
public:
    Particle(int in_x,int in_y)
      :
    x(in_x),
    y(in_y)
    {}
Color getColor()
{
    return c;
}
int getX() const
{
    return x;
}
int getY() const
{
    return y;
}
void followFocalPoint(focalPoint p)
{
    if(p.getX()<x)
     {
         x--;
     }
     if(p.getY()<y)
     {
        y--;
     }
     if(p.getX()>x)
     {
         x++;
     }
     if(p.getY()>y)
        y++;
}


void changeColor(int r ,int g,int b)
{
    c = Color(r,g,b);

}
bool operator==(Particle other)
{
    return ((x==other.getX()) && (y==other.getY()));
}

};
