/*THINGS TO ADD:
PARTICLE MOVEMENT TO USE SPEED INSTEAD OF ++///check
IMPLEMENT THE SLIDER
IMPLEMENT A PARTICLE COUNTER
USE DYNAMIC MEMORY
USE VEC2 CLASS//check
MAKE THEM reflect FAST AFTER TOUCHING THE POINT

*/
#include "CFactor.h"
#include <vector>
#include <random>
#include <cmath>
#include "Particle.h"
#include "focalPoint.h"
#include <algorithm>
#include <initializer_list>
using namespace std;
//aici dau numar fix
// to be changed after i add the sliding bar
int nr_particule=75000;
int g=255;
int b=255;
int r=0;
const int atractie=1000;//forta de atractie a fp ului,care va i reglata din slider

std::vector<Particle>particule;
focalPoint f(demo.GetMouseX(),demo.GetMouseY(),atractie);


void Start()
{

    std::default_random_engine generator;
    std::uniform_int_distribution<int> Xdistribution(0,2*ScreenWidth);
    std::uniform_int_distribution<int> Ydistribution(0,2*ScreenHeight);

    while(nr_particule)
    {
        Particle p(Xdistribution(generator),Ydistribution(generator));

        particule.push_back(p);
        nr_particule--;
    }



}

void Update(float dt)
{
//   Sleep(10);
    f.Update(demo.GetMouseX(),demo.GetMouseY());
    for(int i=0; i<particule.size(); i++)
    {

        f.AtrractParticle(particule[i]);
        /*if(particule[i].touchedFPoint)   ///NOT USING THIS BUT I M KEEPING IT(THAT WHAT SHE SAID) BECAUSE IT MADE ME TOO HAPPY TO JUST DUMP IT
        {

            ///WHAT THE HELL IT WORKS!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            particule[i].ResetPosition({rand()%(2*ScreenWidth),rand()%(2*ScreenHeight)});
            particule[i].touchedFPoint=false;
        }*/
        auto DetermineDistance=[](Vec2 lhs,Vec2 rhs)->float
        {
            float deltax=(rhs.x-lhs.x)*(rhs.x-lhs.x);
            float deltay=(rhs.y-lhs.y)*(rhs.y-lhs.y);
            return sqrt(deltax+deltay);
        };

        float color=f.GetCurrentForce(particule[i]);
        float h= DetermineDistance(Vec2(0,0),Vec2(ScreenWidth,ScreenHeight));
        float d=DetermineDistance(particule[i].GetPosition(),f.GetPosition());
        float rat=d/h;//color ratio
       particule[i].changeColor(255*rat,255-g*rat,0);
    }
    Draw();
    }

void Draw()
{
    for(int i=0; i<particule.size(); i++)
        PutPixel(particule[i].GetX(),particule[i].GetY(),particule[i].getColor());

}

int main()
{
    Start();
    StartWindow();


    return 0;
}
