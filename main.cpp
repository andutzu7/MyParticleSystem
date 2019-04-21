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
#include "Settings.h"
using namespace std;
///Nush unde sa le declar asa ca le scriu aici global aca o sa avem nevoie de ele oricum
std::vector<Particle>particule;//container in care tin toate particulele de pe ecran
Settings Sett(75000,255,255,255,1000);//setari initiale ale jocului
focalPoint f(demo.GetMouseX(),demo.GetMouseY(),Sett.focalPointAttraction);//unde initializez point to follow in fct de pozitia mouseului

void Start()
{
//just the usual generate random thing
    std::default_random_engine generator;
    std::uniform_int_distribution<int> Xdistribution(0,2*ScreenWidth);
    std::uniform_int_distribution<int> Ydistribution(0,2*ScreenHeight);
//aici umplem vectorul cu nr initial de particule din settings
    auto StartParticleNumber=Sett.nr_particule;
    while(StartParticleNumber)
    {
        Particle p(Xdistribution(generator),Ydistribution(generator));//generam random o pozitie

        particule.push_back(p);//o adaugam in vector
        StartParticleNumber--;//scadem din settings numarul de particule
    }



}

void Update(float dt)
{

    f.Update(demo.GetMouseX(),demo.GetMouseY());//la fiecare frame facem update la pozitia focal-poitului
    for(int i=0; i<particule.size(); i++)
    {

        f.AtrractParticle(particule[i]);
        /*if(particule[i].touchedFPoint)   ///NOT USING THIS BUT I M KEEPING IT(THAT WHAT SHE SAID) BECAUSE IT MADE ME TOO HAPPY TO JUST DUMP IT
        {

            ///WHAT THE HELL IT WORKS!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            particule[i].ResetPosition({rand()%(2*ScreenWidth),rand()%(2*ScreenHeight)});
            particule[i].touchedFPoint=false;
        }*/
        auto DetermineDistance=[](Vec2 lhs,Vec2 rhs)->float///aici calculez shadeul. lambda e pt distanta dintre 2 pct pe care o folosesc la forumula finala
        {
            float deltax=(rhs.x-lhs.x)*(rhs.x-lhs.x);
            float deltay=(rhs.y-lhs.y)*(rhs.y-lhs.y);
            return sqrt(deltax+deltay);
        };

        float h= DetermineDistance(Vec2(0,0),Vec2(ScreenWidth,ScreenHeight));//diagonala ecranului,cea mai mare distanta care poate fi gasita pe un ecran.
        float d=DetermineDistance(particule[i].GetPosition(),f.GetPosition());//apelam domnisoara lambda
        float rat=d/h;//color ratio->rezulatul e ratie care determina distanta particulei relativ la pozitia fP ului. determina o nunata in timp real

       particule[i].changeColor(Sett.redValue*rat,Sett.greenValue*rat,255-Sett.blueValue*rat*sin(rat));//just doodling around to get a nice shade
    }
    Draw();

    }

void Draw()
{
    for(int i=0; i<particule.size(); i++) //desenam particulele
        PutPixel(particule[i].GetX(),particule[i].GetY(),particule[i].getColor());
}

int main()
{

    Start();
    StartWindow();


    return 0;
}
