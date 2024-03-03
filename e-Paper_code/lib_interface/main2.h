#include <iostream>
// #include "../lib_interface/clock.h"
#include "clock.h"
#include "interface.h"
#include "headers.h"

int arg(){

    std::unique_ptr<PapClock> clk(new PapClock(100,200,10,20));
   
    Interface inter(std::move(clk));
    inter.initDisplay(DIS_7in5_V2);
    inter.interfaceInit();

    // printf("EPD_7IN5_V2_test Demo\r\n");
    // if(DEV_Module_Init()!=0){
    //     return -1;
    // }
    // printf("e-Paper Init and Clear...\r\n");
    // EPD_7IN5_V2_Init();

    // struct timespec start={0,0}, finish={0,0}; 
    // clock_gettime(CLOCK_REALTIME,&start);
    // EPD_7IN5_V2_Clear();
    // clock_gettime(CLOCK_REALTIME,&finish); 
    // printf("%ld S\r\n",finish.tv_sec-start.tv_sec);
    // DEV_Delay_ms(500);

    //  //Create a new image cache
    // UBYTE *BlackImage;
    // /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
    // UWORD Imagesize = ((EPD_7IN5_V2_WIDTH % 8 == 0)? (EPD_7IN5_V2_WIDTH / 8 ): (EPD_7IN5_V2_WIDTH / 8 + 1)) * EPD_7IN5_V2_HEIGHT;
    // if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    //     printf("Failed to apply for black memory...\r\n");
    //     return -1;
    // }
    // printf("Paint_NewImage\r\n");
    // Paint_NewImage(BlackImage, EPD_7IN5_V2_WIDTH, EPD_7IN5_V2_HEIGHT, 0, WHITE);

    //     printf("SelectImage:BlackImage\r\n");
    // EPD_7IN5_V2_Init_Fast();
    // Paint_SelectImage(BlackImage);
    // Paint_Clear(WHITE);

    // Paint_DrawLine(105,105,175,105,BLACK,DOT_PIXEL_2X2, LINE_STYLE_SOLID);  // longer
    // Paint_DrawLine(105,105,105,155, BLACK,DOT_PIXEL_4X4,LINE_STYLE_SOLID);

    // printf("EPD_Display\r\n");
    // EPD_7IN5_V2_Display(BlackImage);
    // DEV_Delay_ms(2000);
    // aa.print_clock();
    // while(1){}
    return 0;
    // std::cout<<"aa 2"<<std::endl;
}