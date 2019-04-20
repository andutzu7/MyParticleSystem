/*THINGS TO ADD:
PARTICLE MOVEMENT TO USE SPEED INSTEAD OF ++///check
IMPLEMENT THE SLIDER
IMPLEMENT A PARTICLE COUNTER
increase speed by rotating the wheel
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
int nr_particule=25000;
const int g=111;
const int b=255;
const int atractie=5000;//forta de atractie a fp ului,care va i reglata din slider

std::vector<Particle>particule;
focalPoint f(demo.GetMouseX(),demo.GetMouseY(),atractie);
time_t start,now;

void Start()
{
    time (&start);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> Xdistribution(0,2*ScreenWidth);
    std::uniform_int_distribution<int> Ydistribution(0,2*ScreenHeight);

/*
    while(nr_particule>0)
    {
        Particle p(Xdistribution(generator),Ydistribution(generator));

        if(particule.empty())
        {
            particule.push_back(p);
            nr_particule--;

        }
        bool ok=true;
        for(int i=0; i<particule.size(); i++)
        {
            if(particule[i]==p)
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            particule.push_back(p);
            nr_particule--;
            f.AtrractParticle(p);
        }
*/
while(nr_particule>0)
    {
        Particle p(Xdistribution(generator),Ydistribution(generator));

particule.push_back(p);
nr_particule--;
    }



}

void Update(float dt)
{
    Sleep(10);
    f.Update(demo.GetMouseX(),demo.GetMouseY());
    for(int i=0; i<particule.size(); i++)
    {

    f.AtrractParticle(particule[i]);
         if(particule[i].touchedFPoint)
        {

    ///WHAT THE HELL IT WORKS!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        particule[i].ResetPosition({rand()%(2*ScreenWidth),rand()%(2*ScreenHeight)});
        particule[i].touchedFPoint=false;
        }
      auto fc=[](int x1,int y1,int x2,int y2)->int
        {
            float deltax=(x2-x1)*(x2-x1);
            float deltay=(y2-y1)*(y2-y1);
            return sqrt(deltax+deltay);
        };
        int newR=fc(particule[i].GetX(),particule[i].GetY(),f.GetX(),f.GetY()); // pentru schimbatul nuantei cand se aproprie de punct
        particule[i].changeColor(newR,g,b);
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
