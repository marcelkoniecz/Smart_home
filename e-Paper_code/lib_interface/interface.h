
#ifndef INTERFACE_H
#define INTERFACE_H
#include <memory>

#include "headers.h"
#include "clock.h"
#include "date.h"

//In the future could be added other e-paper displays
enum e_PaperDisplay{
    DIS_7in5_V2
};

class Interface{

    UBYTE *_blackImage;
    std::unique_ptr<PapClock> _clock;
    std::unique_ptr<Date> _date;
    bool _displayInit = false; 
    //Data
    //Graphs - temp inside, tmp outside, moisture  in pot 
public:
    Interface(){}
    Interface(std::unique_ptr<PapClock> ptrClock){
        _clock = std::move(ptrClock);
    }

    int initDisplay(e_PaperDisplay display_type); // Init epaper display
    int interfaceInit();//Print all elements of interface

};

#endif //INTERFACE_H