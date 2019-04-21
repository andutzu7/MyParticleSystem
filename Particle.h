#pragma once
#include "Point.h"
#include <random>
#include <cmath>
#include <time.h>
#include <iostream>
typedef olc::Pixel Color;
class Particle: public Point //particula e evident derivata din punct
{
private:

public://din moment ce nu am nici o variabila privata e clar ca am grsit codul dpdv conceptual da nu mai schimb nimic momentan
    Color c;
    bool touchedFPoint=false;
    Particle(float in_x,float in_y)
    {
        mass=1;//vom considera intotdeauna masa unei particule 1 //pentru formula de la fizica
        position.x=in_x;
        position.y=in_y;
    }
    Color getColor() //getterele is sugestive
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

    void changeColor(int r,int g,int b)//si asta e clar ce face
    {
        c = Color(r,g,b);

    }
    bool operator==(Particle &other) //un operator acm inutil dar il folosesc undeva asa ca o las asa nu mare nimeni
    {
        return ((position.x==other.GetX()) && (position.y==other.GetY()));
    }

};
