#pragma once
struct Settings
{
    int nr_particule;
    int redValue;
    int greenValue;
    int blueValue;
    int focalPointAttraction;

    Settings(int nrPart,int rVal,int gVal,int bVal,int fPointAttraction)
        :
        nr_particule(nrPart),
        redValue(rVal),
        greenValue(gVal),
        blueValue(bVal),
        focalPointAttraction(fPointAttraction)
    {}



};
