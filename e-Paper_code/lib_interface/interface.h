
#ifndef INTERFACE_H
#define INTERFACE_H
#include <memory>

#include "headers.h"
#include "clock.h"
#include "date.h"
#include "timeWidget.h"
#include "pot.h"

//In the future could be added other e-paper displays
enum e_PaperDisplay{
    DIS_7in5_V2
};

class Interface{

    UBYTE *_blackImage;

    // std::unique_ptr<PapClock> _clock;
    // std::unique_ptr<Date> _date;
    std::unique_ptr<TimeWidget> _timeWidget;
    std::array<std::unique_ptr<Pot>, 4> _potWidgets;
    bool _displayInit = false; 
    //Data
    //Graphs - temp inside, tmp outside, moisture  in pot 
public:
    Interface(){}
    // Interface(std::unique_ptr<PapClock> ptrClock){
    //     _clock = std::move(ptrClock);

    //     // std::unique_ptr<TimeWidget> tmpWidget(std::move(ptrClock),std::move(ptrDate));
    //     // _timeWidget = std::move(tmpWidget); 
    // }
    Interface(std::unique_ptr<PapClock> ptrClock,std::unique_ptr<Date> ptrDate){
       _timeWidget = std::make_unique<TimeWidget>(std::move(ptrClock), std::move(ptrDate));
        // _timeWidget = std::move(tmpWidget); 
    }

    Interface(std::unique_ptr<PapClock> ptrClock,std::unique_ptr<Date> ptrDate,
    std::array<std::unique_ptr<Pot>, 4> potWidgets){
       _timeWidget = std::make_unique<TimeWidget>(std::move(ptrClock), std::move(ptrDate));
        _potWidgets = std::move(potWidgets);
        // _timeWidget = std::move(tmpWidget); 
    }


    int initDisplay(e_PaperDisplay display_type); // Init epaper display
    int interfaceInit();//Print all elements of interface

};

#endif //INTERFACE_H