#include "CFactor.h"
#include <vector>
#include <random>
#include "Particle.h"
#include "focalPoint.h"
//aici dau numar fix
// to be changed after i add the sliding bar
int nr_particule=10000;
const int g=111;
const int b=11;
std::vector<Particle>particule;
focalPoint f(demo.GetMouseX(),demo.GetMouseY());
void Start()
{

std::default_random_engine generator;
std::uniform_int_distribution<int> Xdistribution(0,ScreenWidth);
std::uniform_int_distribution<int> Ydistribution(0,ScreenHeight);


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
    Sleep(10);
f.Update(demo.GetMouseX(),demo.GetMouseY());
std::cout<<demo.GetMouseX()<<" "<<demo.GetMouseY()<<std::endl;
for(int i=0;i<particule.size();i++)
{
    particule[i].followFocalPoint(f);
auto fc=[](int x1,int y1,int x2,int y2)->int
{
float deltax=(x2-x1)*(x2-x1);
    float deltay=(y2-y1)*(y2-y1);
    return sqrt(deltax+deltay);};
    int newR=fc(particule[i].getX(),particule[i].getY(),f.getX(),f.getY());
    particule[i].changeColor(newR,g,b);
}
Draw();
}

void Draw()
{
for(int i=0;i<particule.size();i++)
    PutPixel(particule[i].getX(),particule[i].getY(),particule[i].getColor());

}

int main()
{
    Start();
    StartWindow();


    return 0;
}
