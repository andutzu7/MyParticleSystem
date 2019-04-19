#pragma once
#include "focalPoint.h"
#include "Point.h"
#include <random>
#include <cmath>
typedef olc::Pixel Color;
class Particle: public Point
{
private:
    Color c;

public:
    float speed;
    bool touchedFPoint=false;
    std::vector<Vec2>PreviouslySeedThere;//aici keep track la locuri de respawnare anterioara a unor patricule. in cazul in care nr>nrParticule,virtually every place has been occupied so i clear the vector and do the shit again
    Particle(float in_x,float in_y,float in_Speed)// to add vel
    {
        position.x=in_x;
        position.y=in_y;
        speed=in_Speed;
        PreviouslySeedThere.push_back(position);
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
    void followFocalPoint(focalPoint& p,float dt)
    {

        IncreaseSpeed();

        Vec2 direction=(p.position-position);
        direction=direction.GetNormalized();
        position+=direction*speed*dt;
        if((p.position-position).GetLength()<=1.0f)
            touchedFPoint=true;

    }
    void IncreaseSpeed()//SolutieDeTaraniDaMerge
    {

            speed+=0.5f;

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
