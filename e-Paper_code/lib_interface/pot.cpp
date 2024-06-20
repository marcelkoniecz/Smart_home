#include "pot.h"
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include "headers.h"




void Pot::drawPotWidget(){
        // printf("%d",_cord[0]);
    Paint_DrawString_EN(_cord[0],_cord[1],"Moisture",&Font24  ,WHITE,BLACK); 
    Paint_DrawString_EN(_cord[0],_cord[1]+30,"Pot 1-24%",&Font24  ,WHITE,BLACK);
    Paint_DrawString_EN(_cord[0],_cord[1]+60,"BAT:67%",&Font24 ,WHITE,BLACK );
    // printf("xd");
}