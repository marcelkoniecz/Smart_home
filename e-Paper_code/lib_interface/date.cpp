#include "date.h"
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include "headers.h"

void Date::updateDate(){
    time_t curr_time; 
    curr_time = time(NULL);
    tm *tm = localtime(&curr_time);
    std::stringstream buffer;
    buffer << tm->tm_mday << " " <<months[tm->tm_mon];
    std::string str =buffer.str();
    Paint_DrawString_EN(_cord[0],_cord[1],weekday[tm->tm_wday],&Font24 ,BLACK ,WHITE);
    Paint_DrawString_EN(_cord[0],30+_cord[1],str.c_str(),&Font24 ,BLACK ,WHITE);
    Paint_DrawString_EN(_cord[0],60 +_cord[1],std::to_string((tm->tm_year+1900)).c_str(),&Font24, BLACK ,WHITE );
}
