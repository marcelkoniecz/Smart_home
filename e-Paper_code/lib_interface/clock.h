
#ifndef CLOCK_H
#define CLOCK_H

#include "base.h"
// #include "headers.h"

class PapClock : public BaseCord{

    public:
        PapClock(){}
        PapClock(int n_cordx, int n_cordy, int n_maxx, int n_maxy) : BaseCord(n_cordx, n_cordy, n_maxx, n_maxy){}
        PapClock(int n_maxx, int n_maxy):BaseCord(n_maxx,n_maxy){}
        void print_clock();
        // {
    //              //Create a new image cache
    // UBYTE *BlackImage;
    // /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
    // UWORD Imagesize = ((EPD_7IN5_V2_WIDTH % 8 == 0)? (EPD_7IN5_V2_WIDTH / 8 ): (EPD_7IN5_V2_WIDTH / 8 + 1)) * EPD_7IN5_V2_HEIGHT;
    // if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    //     printf("Failed to apply for black memory...\r\n");
    //     // return -1;
    // }
    // printf("Paint_NewImage\r\n");
    // // Paint_NewImage(BlackImage, EPD_7IN5_V2_WIDTH, EPD_7IN5_V2_HEIGHT, 0, WHITE);
    // Paint_NewImage(BlackImage, 200, 200, 0, WHITE);

    //     printf("SelectImage:BlackImage\r\n");
    // EPD_7IN5_V2_Init_Fast();
    // Paint_SelectImage(BlackImage);
    // Paint_Clear(WHITE);

    // Paint_DrawLine(105,105,175,105,BLACK,DOT_PIXEL_2X2, LINE_STYLE_SOLID);  // longer
    // Paint_DrawLine(105,105,105,155, BLACK,DOT_PIXEL_4X4,LINE_STYLE_SOLID);

    // printf("EPD_Display\r\n");
    // EPD_7IN5_V2_Display(BlackImage);
    // DEV_Delay_ms(2000);}
            
                // Paint_DrawLine(105,105,175,105,BLACK,DOT_PIXEL_2X2, LINE_STYLE_SOLID);  // longer
                // Paint_DrawLine(105,105,105,155, BLACK,DOT_PIXEL_4X4,LINE_STYLE_SOLID);}  //shorter
        void update_clock();
};
#endif