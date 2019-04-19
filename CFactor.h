#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>

void Update(float dt);
void Draw();
void __DrawFromMain(){Draw();} // beacuse the engine has a Draw function already
void ClearScreen();

class Example : public olc::PixelGameEngine
{
public:
    Example()
    {
        sAppName = "CFactor - powered by Fundatia iOSiF";
    }
public:
    bool OnUserCreate() override
    {
        // Called once at the start, so create things here
        return true;
    }
    bool OnUserUpdate(float fElapsedTime) override
    {
        ClearScreen();
        Update(fElapsedTime);
        __DrawFromMain();
        return true;
    }
};

Example demo;


//
const int ScreenWidth = 800;
const int ScreenHeight = 600;

void StartWindow()
{
    if (demo.Construct(ScreenWidth, ScreenHeight, 1, 1))
    {
            demo.Start();
    }
}


//COLORS
const olc::Pixel RED =  olc::Pixel(255,0,0);
const olc::Pixel GREEN =  olc::Pixel(0,255,0);
const olc::Pixel BLUE =  olc::Pixel(0,0,255);
const olc::Pixel WHITE =  olc::Pixel(255,255,255);
const olc::Pixel BLACK =  olc::Pixel(0,0,0);
const olc::Pixel GRAY =  olc::Pixel(80,80,80);
const olc::Pixel YELLOW =  olc::Pixel(255,255,0);
const olc::Pixel CYAN =  olc::Pixel(0,255,255);
const olc::Pixel MAGENTA =  olc::Pixel(255,0,255);



void PutPixel(int x, int y, olc::Pixel color)
{
    demo.Draw(x,y,color);
}

void PutPixel(int x, int y, char r, char b, char g)
{
    PutPixel(x, y, olc::Pixel(r,g,b));
}

void FillCircle(int x, int y, int radius, olc::Pixel color)
{
    demo.FillCircle(x,y,radius,color);
}

void FillRectangle(int left, int top, int right, int bottom, olc::Pixel color)
{
    demo.FillRect(left,top,right-left,bottom-top,color);
}


void ClearScreen()
{
    demo.FillRect(0,0,ScreenWidth,ScreenHeight,BLACK);
}
