#include "CFactor.h"
#include <vector>
#include <random>
#include "Particle.h"
#include "focalPoint.h"


void Start()
{
std::default_random_engine generator;
std::uniform_int_distribution<int> Xdistribution(0,ScreenWidth);
std::uniform_int_distribution<int> Ydistribution(0,ScreenHeight);
//aici dau numar fix
// to be changed after i add the sliding bar
 int nr_particule=1000;
std::vector<Particle>particule;
while(nr_particule>0)
{
    Particle p(Xdistribution(generator),Ydistribution(generator));

    if(particule.empty())
    {
        particule.push_back(p);
        nr_particule--;

    }
    bool ok=true;
   for(int i=0;i<particule.size();i++)
   {
       if(particule[i]==p)
       {ok=false;
        break;}
   }
   if(ok)
   {
       particule.push_back(p);
       nr_particule--;
   }

}



}

void Update()
{
}

void Draw()
{

}

int main()
{
    StartWindow();
    return 0;
}
