#pragma once //make the virtual class
#include "Vec2.h"
class Point{
public:
Vec2 position;
virtual const float GetX()=0;
virtual const float GetY()=0;
virtual const Vec2 GetPosition()=0;

};

