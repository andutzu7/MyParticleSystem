#pragma once
struct Settings  // Where i keep track of the settings
{//Numele sunt sugestive
    int nr_particule;
    int redValue;
    int greenValue;
    int blueValue;
    int focalPointAttraction;
//constructotul la fel
    Settings(int nrPart,int rVal,int gVal,int bVal,int fPointAttraction)
        :
        nr_particule(nrPart),
        redValue(rVal),
        greenValue(gVal),
        blueValue(bVal),
        focalPointAttraction(fPointAttraction)
    {}



};
