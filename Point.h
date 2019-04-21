#pragma once //make the virtual class
#include "Vec2.h"
class Point{///clasa virtuala din care deriva toate punctele din joc
private:///clasa e cam gresita dpdv logic pt ca nu are nici un membru privat...

public:

Vec2 position; ///positia pct
int mass;///masa pct
virtual const float GetX()=0;///gettere obisnuite
virtual const float GetY()=0;
virtual const Vec2 GetPosition()=0;

};

