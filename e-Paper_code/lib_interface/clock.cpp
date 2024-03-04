#include "clock.h"
#include <ctime>
#include "headers.h"



void PapClock::printClock(){
    Paint_DrawLine(105,105,175,105,BLACK,DOT_PIXEL_2X2, LINE_STYLE_SOLID);  // longer
    Paint_DrawLine(105,105,105,155, BLACK,DOT_PIXEL_3X3,LINE_STYLE_SOLID);  // shorter
    Paint_DrawCircle(105,105,3,BLACK,DOT_PIXEL_3X3,DRAW_FILL_FULL);         // cicrcle inside clock
    Paint_DrawCircle(105,105,85,BLACK,DOT_PIXEL_2X2,DRAW_FILL_EMPTY);       // circle outside clock
}

void PapClock::updateClock(){
    EPD_7IN5_V2_Sleep();
    // curr_time = time(NULL);
    // tm *tm_local = localtime(&curr_time);
    // std::cout << "Current local time : " << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec;
    // // Paint_DrawRectangle(30,190,190,230,WHITE,DOT_PIXEL_1X1,DRAW_FILL_FULL);
    // // Paint_ClearWindows(0,0,400,400,WHITE);
    // Paint_DrawCircle(105,105,85,BLACK,DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
    // Paint_DrawLine(105,105,minXTab[tm_local->tm_min],minYTab[tm_local->tm_min],BLACK,DOT_PIXEL_2X2, LINE_STYLE_SOLID);  // longer
    // Paint_DrawLine(105,105,hrsXTab[(tm_local->tm_hour)%12],hrsYTab[(tm_local->tm_hour)%12], BLACK,DOT_PIXEL_3X3,LINE_STYLE_SOLID);  // shorter
    
}

// // void update_clock(){

// // }

// . 104, 112, 119, 126, 133, 140, 146, 151, 157, 161, 165, 168, 171, 173, 174, 175, 174, 173, 171, 168, 165, 161, 157, 151, 146, 140, 133, 126, 119, 112, 105, 97, 90, 83, 76, 70, 63, 58, 52, 48, 44, 41, 38, 36, 35, 35, 35, 36, 38, 41, 44, 48, 52, 58, 63, 70, 76, 83, 90, 97, 
// . 35, 35, 36, 38, 41, 44, 48, 52, 58, 63, 69, 76, 83, 90, 97, 104, 112, 119, 126, 133, 140, 146, 151, 157, 161, 165, 168, 171, 173, 174, 175, 174, 173, 171, 168, 165, 161, 157, 151, 146, 139, 133, 126, 119, 112, 105, 97, 90, 83, 76, 70, 63, 58, 52, 48, 44, 41, 38, 36, 35, 
// [2.   2.25 2.5  2.75 3.  ]


// ** Process exited - Return Code: 0 **
// Press Enter to exit terminal


// ** Process exited - Return Code: 0 **
// Press Enter to exit terminal