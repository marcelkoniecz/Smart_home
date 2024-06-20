#ifndef POT_H
#define POT_H

#include "base.h"

class Pot : public BaseCord
{

    int _moisture;
    int _battery;
    int _identifyNumber;

public:
    Pot() {}
    Pot(int idf, int x, int y, int resX, int resY) : BaseCord(x, y, resX, resY),
     _moisture(0), _battery(0), _identifyNumber(idf){}

    void drawPotWidget();
    // updateWidget();/
};

#endif