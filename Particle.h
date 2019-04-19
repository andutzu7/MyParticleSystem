#pragma once
#include "focalPoint.h"
#include "Point.h"

typedef olc::Pixel Color;
class Particle: public Point{
private:
  Color c;
  Vec2 velocity;
public:
    Particle(float in_x,float in_y)// to add vel
{
    position.x=in_x;
    position.y=in_y;
}
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
void followFocalPoint(focalPoint& p)
{

}


void changeColor(int r ,int g,int b)
{
    c = Color(r,g,b);

}
bool operator==(Particle &other)
{
    return ((x==other.getX()) && (y==other.getY()));
}

};
