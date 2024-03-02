
#ifndef INTERFACE_H
#define INTERFACE_H

#include "clock.h"
#include "headers.h"

class Interface{

    UBYTE *BlackImage;
    PapClock *_clock; 
    //Data
    //Graphs
public:
    Interface(){}
    Interface(PapClock clk){}

    void interfaceInit();


};

#endif //INTERFACE_H