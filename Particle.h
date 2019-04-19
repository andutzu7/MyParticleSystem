#pragma once
#include "focalPoint.h"
#include <utility>
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
    Particle(int in_x,int in_y,Color col)
    {
        x=in_x;
        y=in_y;
        c=col;
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

std::pair<int, int>distanceTillFocalPoint(focalPoint p) const
{
    std::pair<int,int> pa;
    pa.first=p.getX()-x;
    pa.second=p.getY()-y;
    return pa;

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
