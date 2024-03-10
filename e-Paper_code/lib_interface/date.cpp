#include "date.h"
#include <ctime>
#include "headers.h"

void Date::updateDate(){
    time_t curr_time; 
    curr_time = time(NULL);
    tm *tm = localtime(&curr_time);

    Paint_DrawString_EN(30,240,weekday[tm->tm_wday],&Font24 ,WHITE ,BLACK);
    Paint_DrawString_EN(30,270,"04 March",&Font24 ,WHITE ,BLACK);
    // Paint_DrawString_EN//year 
}
