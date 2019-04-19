#pragma once //make the virtual class
#include "Vec2.h"
class Point{
public:
Vec2 position;
virtual int GetX()=0;
virtual int GetY()=0;


};

