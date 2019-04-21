#pragma once
#include "Point.h"
#include "Particle.h"
class focalPoint: public Point{ ///tot derivata din point
private:

public:
    focalPoint(float in_x,float in_y,int in_mass)
    {
        position.x=in_x;
        position.y=in_y;
        mass=in_mass;  ///masa e forta de atractie basically
    }
const float GetX()  ///gettere obisnuite si obligatorii
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
void Update(float new_x,float new_y)  ///since we work with the mouse, in fiecare frame fac update la pozitia actuala a fp based on the mouse position/
{
position.x=new_x;
position.y=new_y;
}
void AtrractParticle(Particle& p)  //aici e big deal, atrag o particula folosind formula atractiei de la fizica.if u curious google it its eztofind
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

       if(p.touchedFPoint) ///aici arunc particulele care au atins fp ul int directia opusa fata de unde au venit
       {

       strenght*=rand()%ScreenWidth;//a random constant used for the pullback force
       force*=strenght;
       Vec2 acceleration=force;
       velocity-=acceleration;///ca sa mergem in directia opusa

       }

       p.position+=velocity; //update positionbby

       ///ZONA UNDE TESTEZ DACA ESTE IN ZONA FP-ului pt a-l reflecta obiectul
       if(distance.GetLength()<=0.1f)
            p.touchedFPoint=true;

    }

};
