#pragma once
class focalPoint{
private:
    int x;
    int y;

public:
    focalPoint(int in_x,int in_y)
    :
        x(in_x),
        y(in_y)
    {
    }
int getX() const
{
    return x;
}
int getY() const
{
    return y;
}
};
