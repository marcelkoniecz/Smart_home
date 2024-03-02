
#ifndef INTERFACE_H
#define INTERFACE_H

#include "clock.h"
#include "headers.h"
#include <memory>

//In the future could be added other e-paper displays
enum e_PaperDisplay{
    DIS_7in5_V2
};

class Interface{

    UBYTE *_blackImage;
    std::unique_ptr<PapClock> _clock; 
    //Data
    //Graphs - temp inside, tmp outside, moisture  in pot 
public:
    Interface(){}
    Interface(std::unique_ptr<PapClock> ptrClock){
        _clock = std::move(ptrClock);
    }


    int initDisplay(e_PaperDisplay display_type) // Init epaper display
    {
        if(display_type == DIS_7in5_V2 ){
            std::cout<<"Module initalization"<<std::endl;
            if(DEV_Module_Init()!=0){ //Module initalize, SPI and pins
                std::cout<<"Module initalization error"<<std::endl;
                return -1;
            }
            std::cout<<"E-paper initalization and clearing"<<std::endl;
            EPD_7IN5_V2_Init();     // e-Paper register initalization
            EPD_7IN5_V2_Clear();    //e-Paper clear screen
            DEV_Delay_ms(500);

            //Calculate size and allocate memory
            UWORD Imagesize = ((EPD_7IN5_V2_WIDTH % 8 == 0)? (EPD_7IN5_V2_WIDTH / 8 ): (EPD_7IN5_V2_WIDTH / 8 + 1)) * EPD_7IN5_V2_HEIGHT;
            _blackImage = new UBYTE[Imagesize + 1 ];
            DEV_Delay_ms(500);
            
            //Painting image
            Paint_NewImage(_blackImage, EPD_7IN5_V2_WIDTH, EPD_7IN5_V2_HEIGHT, 0, WHITE);
            EPD_7IN5_V2_Init_Fast();
            Paint_SelectImage(_blackImage); // Select paint black image
            Paint_Clear(WHITE); //Clearing screen
            
            std::cout<<"Initialization OK"<<std::endl;
            return 1;
        }

        std::cout<<"Implementaion of initialization this device is not made"<<std::endl;
        return 0;
    }


    //Print all elements of interface
    void interfaceInit(){
        std::cout<<"aa"<<std::endl;
        Paint_SelectImage(_blackImage);
        std::cout<<"aa 2"<<std::endl;
        Paint_DrawLine(105,105,175,105,BLACK,DOT_PIXEL_2X2, LINE_STYLE_SOLID);  // longer
        Paint_DrawLine(105,105,105,155, BLACK,DOT_PIXEL_4X4,LINE_STYLE_SOLID);
        std::cout<<"aa 3"<<std::endl;
        EPD_7IN5_V2_Display(_blackImage);
        std::cout<<"aa 4"<<std::endl;
    }

};

#endif //INTERFACE_H