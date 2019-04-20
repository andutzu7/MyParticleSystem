#pragma once
#include "Point.h"
#include "Particle.h"
class focalPoint: public Point{
private:

public:
    focalPoint(float in_x,float in_y,int in_mass)
    {
        position.x=in_x;
        position.y=in_y;
        mass=in_mass;
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
void AtrractParticle(Particle& p)
    {

     // old speed adjusting method speed+=0.5f;OLD//SolutieDeTaraniDaMerge
      //Physics shit right there below
      ///ZONA UNDE CALCULEZ DISTANTA
      Vec2 distance=position-p.position;
       ///ZONA UNDE CALCULEZ FORTA FORTA

       Vec2 force=distance;
       force.Normalize();
       float strenght=(mass*p.mass)/(distance.GetLength()*distance.GetLength());//FORMULA ATRACTIEI DE LA FIZICA G*MASS1*MASS2/DISTANTA LA PATRAT. IN CAZUL MEU NU MAI CONSIDER ATRACTIA GRAVITATIONALA ,DOAR MASELE OBIECTELOR
       force*=strenght;
      ///ZONA UNDE CALCULEZ DIRECTIA
       Vec2 direction=(position-p.position);
       direction=direction.GetNormalized();


       ///ZONA UNDE FAC UPDATE LA POZITIA PARTICULEI
      Vec2 velocity=direction;
       Vec2 acceleration=force;//formula la fizica e force/mass dar particula mea are masa unu asa ca nu ma complic
       velocity+=acceleration;

       if(p.touchedFPoint)
       {

       strenght*=rand()%ScreenWidth;//a random constant used for the pullback force
       force*=strenght;
       Vec2 acceleration=force;
       velocity-=acceleration;

       }

       p.position+=velocity;

       ///ZONA UNDE TESTEZ DACA ESTE IN ZONA FP-ului pt a respawna obiectul
       if(distance.GetLength()<=0.1f)
            p.touchedFPoint=true;


    }
float GetCurrentForce(Particle& p)
{
      ///ZONA UNDE CALCULEZ DISTANTA
      Vec2 distance=position-p.position;
      Vec2 force=distance;

        return force.GetLength();
}
};
