#ifndef TIME_WIDGET_H
#define TIME_WIDGET_H

#include <memory>
#include "date.h"
#include "clock.h"

class TimeWidget{

std::unique_ptr<PapClock> _clock;
std::unique_ptr<Date> _date;
bool updateDate = true;

public:
    TimeWidget(){}
    TimeWidget(std::unique_ptr<PapClock> ptrClock){
        _clock = std::move(ptrClock);
    }

    TimeWidget(std::unique_ptr<PapClock> ptrClock, std::unique_ptr<Date> ptrDate){
        _clock = std::move(ptrClock);
        _date = std::move(ptrDate);
    }
    void drawTimeWidget(){
        _clock->printClock();
    }
    void updateTimewidget();
};


#endif //TIME_WIDGET_H