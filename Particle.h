#pragma once
#include "Point.h"
#include <random>
#include <cmath>
#include <iostream>
typedef olc::Pixel Color;
class Particle: public Point
{
private:
    Color c;
public:
    class ReflectedParticle
    {
        Vec2 position;
        Color c;
     //   time (&now);
           // int dif = difftime (now,start);

    };
    float speed;
    bool touchedFPoint=false;
    Particle(float in_x,float in_y)
    {
        mass=1;//vom considera intotdeauna masa unei particule 1
        position.x=in_x;
        position.y=in_y;
    }
    Color getColor()
    {
        return c;
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


   void ResetPosition(Vec2 other)
    {
        position=other;
    }

    void changeColor(int r,int g,int b)
    {
        c = Color(r,g,b);

    }
    bool operator==(Particle &other)
    {
        return ((position.x==other.GetX()) && (position.y==other.GetY()));
    }

};
