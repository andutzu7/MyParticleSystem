/*THINGS TO ADD:
PARTICLE MOVEMENT TO USE SPEED INSTEAD OF ++///check
MAKE THEM GO FAST AFTER TOUCHING THE POINT
USE DYNAMIC MEMORY
USE VEC2 CLASS//check
IMPLEMENT THE SLIDER
IMPLEMENT A PARTICLE COUNTER
*/
#include "CFactor.h"
#include <vector>
#include <random>
#include <cmath>
#include "Particle.h"
#include "focalPoint.h"
#include <algorithm>
#include <time.h>
#include <initializer_list>
using namespace std;
//aici dau numar fix
// to be changed after i add the sliding bar
int nr_particule=10000;
const int g=111;
const int b=255;
float initialParticleSpeed=15.0f;
std::vector<Particle>particule;
std::vector<Vec2>PreviouslySeedThere;//aici keep track la locuri de respawnare anterioara a unor patricule. in cazul in care nr>nrParticule,virtually every place has been occupied so i clear the vector and do the shit again
focalPoint f(demo.GetMouseX(),demo.GetMouseY());
#include <time.h>
time_t start,now;

void Start()
{
    time (&start);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> Xdistribution(0,ScreenWidth);
    std::uniform_int_distribution<int> Ydistribution(0,ScreenHeight);


    while(nr_particule>0)
    {
        Particle p(Xdistribution(generator),Ydistribution(generator),initialParticleSpeed);

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
        }

    }



}

void Update(float dt)
{
    Sleep(10);
    f.Update(demo.GetMouseX(),demo.GetMouseY());
    for(int i=0; i<particule.size(); i++)
    {

         if(particule[i].touchedFPoint)
        {

        time (&now);
            int dif = difftime (now,start);
            particule[i].speed=initialParticleSpeed;
     ///WHAT THE HELL IT WORKS!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        particule[i].ResetPosition({rand()%ScreenWidth,rand()%ScreenHeight});
        particule[i].touchedFPoint=false;
        }

        if(PreviouslySeedThere.size()==10000)//nr de particule to be changed
          PreviouslySeedThere.clear();
        particule[i].followFocalPoint(f,dt);
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
