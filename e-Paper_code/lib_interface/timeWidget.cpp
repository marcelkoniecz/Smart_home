#include "timeWidget.h"



void TimeWidget::updateTimewidget(){
    if(updateDate){
        _date->updateDate();
    }
    _clock->updateClock();

}

