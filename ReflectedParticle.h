///!!!!!NU MAI FOLOSESC CLASA ASTA,AM GASIT O SOLUTIE MAI ELEGANTA!!!!
/*#pragma once
#include "Particle.h"
class ReflectedParticle:focalPoint
    {
        Color c{255,255,255};
        int particleLifeSpan=3;//cat de mult dureaza pana dispare
        time_t creationT,now;

        ReflectedParticle(Vec2 start_Pos)
        {
            position=start_Pos;
            time (&creationT);
        }
        //TO USE DESTRUCTOR LATER
       bool checkIfNeedsToBeDestructed()
       {
          time(&now);
          int dif=creationT-now;
          if(dif>particleLifeSpan)
            return true;
          return false;
       }
       void destructParticle()
       {
          position={9999,9999};
       }

    };
*/
