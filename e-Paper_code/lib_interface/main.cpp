﻿
#ifdef __cplusplus
extern "C" {
#endif
#include <stdlib.h>     //exit()
#include <signal.h>     //signal()
// #include "EPD_Test.h"   //Examples
#ifdef __cplusplus
}
#endif
#include "clock.h"
#include "date.h"
#include "interface.h"
#include "headers.h"
#include "pot.h"

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:exit\r\n");
    DEV_Module_Exit();

    exit(0);
}

int main(void)
{
    // Exception handling:ctrl + c
    signal(SIGINT, Handler);

    std::unique_ptr<PapClock> clk(new PapClock(0,0,200,250));           //only clock
    std::unique_ptr<Date> date(new Date(30,250,200,60));                //date
    std::array<std::unique_ptr<Pot>, 4> pots = {
        std::make_unique<Pot>(1, 210, 30, 300, 130),
        std::make_unique<Pot>(2, 210, 140, 300, 240),
        std::make_unique<Pot>(3, 210, 250, 300, 350),
        std::make_unique<Pot>(4, 210, 360, 300, 460)
    };
    // std::unique_ptr<TemperatureWidget> tmpInside(new TemperatureWidget(400,10,380,230))//temperature inside widget
    // std::unique_ptr<TemperatureWidget> tmpInside(new TemperatureWidget(400,10,380,230))//temperature inside widget

    // pot1->drawPotWidget();
    
    // Interface inter(std::move(clk));
    // Interface inter(std::move(clk), std::move(date));
    Interface inter(std::move(clk), std::move(date),std::move(pots));
    inter.initDisplay(DIS_7in5_V2);
   

    //Example of interface
    // int x = 100;
    // Paint_DrawString_EN(330+x,10,"Temperature in room",&Font24 ,WHITE ,BLACK);
    // Paint_DrawLine(300+x,215,680+x,215,BLACK,DOT_PIXEL_2X2,LINE_STYLE_SOLID);   //ok?
    // Paint_DrawLine(300+x,215,300+x,40,BLACK,DOT_PIXEL_2X2,LINE_STYLE_SOLID);
    // Paint_DrawString_EN(425+x, 220, "Time",&Font20,WHITE,BLACK);


    // Paint_DrawString_EN(330+x,250,"Temperature outside",&Font24 ,WHITE ,BLACK);
    // Paint_DrawLine(300+x,455,680+x,455,BLACK,DOT_PIXEL_2X2,LINE_STYLE_SOLID); // ok
    // Paint_DrawLine(300+x,455,300+x,280,BLACK,DOT_PIXEL_2X2,LINE_STYLE_SOLID);
    // Paint_DrawString_EN(425+x, 460, "Time",&Font20,WHITE,BLACK);

    // Paint_DrawString_EN(210,30,"Moisture",&Font24 ,WHITE ,BLACK); 
    // Paint_DrawString_EN(210,60,"Pot 1:24%",&Font24 ,WHITE ,BLACK);
    // // Paint_DrawString_EN(240,90,"24 %",&Font24 ,WHITE ,BLACK);
    // Paint_DrawString_EN(210,90,"BAT:67%",&Font24 ,WHITE ,BLACK);

    // Paint_DrawString_EN(210,140,"Moisture",&Font24 ,WHITE ,BLACK); 
    // Paint_DrawString_EN(210,170,"Pot 2:24%",&Font24 ,WHITE ,BLACK);
    // // Paint_DrawString_EN(240,90,"24 %",&Font24 ,WHITE ,BLACK);
    // Paint_DrawString_EN(210,200,"BAT:33%",&Font24 ,WHITE ,BLACK);


    // Paint_DrawString_EN(210,250,"Moisture",&Font24 ,WHITE ,BLACK); 
    // Paint_DrawString_EN(210,280,"Pot 3:24%",&Font24 ,WHITE ,BLACK);
    // // Paint_DrawString_EN(240,90,"24 %",&Font24 ,WHITE ,BLACK);
    // Paint_DrawString_EN(210,310,"BAT:2%",&Font24 ,WHITE ,BLACK);


    // Paint_DrawString_EN(210,360,"Moisture",&Font24 ,WHITE ,BLACK); 
    // Paint_DrawString_EN(210,390,"Pot 4:24%",&Font24 ,WHITE ,BLACK);
    // // Paint_DrawString_EN(240,90,"24 %",&Font24 ,WHITE ,BLACK);
    // Paint_DrawString_EN(210,420,"BAT:87%",&Font24 ,WHITE ,BLACK);
    
    // date->updateDate();
    // Paint_DrawString_EN(30,210,"10:24:35",&Font24 ,WHITE ,BLACK); 
    // Paint_DrawString_EN(30,250,"Wednesday",&Font24 ,WHITE ,BLACK);
    // Paint_DrawString_EN(30,280,"04 March",&Font24 ,WHITE ,BLACK); 
    // Paint_DrawString_EN(210,270,"Pot 1:24%",&Font24 ,WHITE ,BLACK);

    inter.interfaceInit();

    


 
    return 0;
}
