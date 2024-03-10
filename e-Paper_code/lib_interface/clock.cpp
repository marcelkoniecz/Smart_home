#include "clock.h"
#include <ctime>
#include <string>  
#include <iostream> 
#include <sstream>  
#include "headers.h"



void PapClock::printClock(){
    // Cord tmpCord = getCord();
    Paint_DrawLine(105 + _cord[0],105 + _cord[1],175 + _cord[0],105 + _cord[1],BLACK,DOT_PIXEL_2X2, LINE_STYLE_SOLID);  // longer
    Paint_DrawLine(105 + _cord[0],105 + _cord[1],105 + _cord[0],155 + _cord[1], BLACK,DOT_PIXEL_3X3,LINE_STYLE_SOLID);  // shorter
    Paint_DrawCircle(105 + _cord[0],105 + _cord[1],3,BLACK,DOT_PIXEL_3X3,DRAW_FILL_FULL);                             // cicrcle inside clock
    Paint_DrawCircle(105 + _cord[0],105 + _cord[1],85,BLACK,DOT_PIXEL_2X2,DRAW_FILL_EMPTY);                       // circle outside clock
}

void PapClock::updateClock(){
    // EPD_7IN5_V2_Sleep();
    curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    std::stringstream buffer;
    buffer << tm_local->tm_hour << ":" << tm_local->tm_min;
    std::string str =buffer.str();
    std::cout << buffer.str()<<std::endl;
    // tm_local->tm_sec
    Paint_DrawCircle(105 + _cord[0],105 + _cord[1],3,WHITE,DOT_PIXEL_3X3,DRAW_FILL_FULL);
    Paint_DrawCircle(105+ _cord[0],105+ _cord[1],85,WHITE,DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
    Paint_DrawLine(105+ _cord[0],105+ _cord[1],minXTab[tm_local->tm_min]+ _cord[0],minYTab[tm_local->tm_min]+ _cord[1],WHITE,DOT_PIXEL_2X2, LINE_STYLE_SOLID);  // longer
    Paint_DrawLine(105+ _cord[0],105+ _cord[1],hrsXTab[(tm_local->tm_hour)%12]+ _cord[0],hrsYTab[(tm_local->tm_hour)%12]+ _cord[1], WHITE,DOT_PIXEL_3X3,LINE_STYLE_SOLID);  // shorter
    Paint_DrawString_EN(60+ _cord[0],210+ _cord[1],str.c_str(),&Font24 ,BLACK ,WHITE); 
}

// // void update_clock(){

// // }
