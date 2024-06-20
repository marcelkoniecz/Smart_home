#include "interface.h"


int Interface::initDisplay(e_PaperDisplay display_type) // Init epaper display
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
            
            std::cout<<"Initialization OK "<<std::endl;
            _displayInit = true;
            return 1;
        }

        std::cout<<"Implementaion of initialization this device is not made"<<std::endl;
        return 0;
    }
    int Interface::interfaceInit(){

        if(_displayInit == false){
            std::cout<<"Display not initalized"<<std::endl;
            return -1;
        }

        _timeWidget->drawTimeWidget();
        for (const auto& pot : _potWidgets) {
            pot->drawPotWidget();
        }

        EPD_7IN5_V2_Display(_blackImage);
        EPD_7IN5_V2_Init_Partial();
        Paint_NewImage(_blackImage,200, 350,0,WHITE);
        Paint_SelectImage(_blackImage);
        Paint_Clear(BLACK);
        // Paint_Clear(WHITE);
        while(1){
        // EPD_7IN5_V2_Clear();
        EPD_7IN5_V2_Init_Partial();
        Paint_ClearWindows(0,0,200,350,BLACK);
        _timeWidget->updateTimewidget();
        EPD_7IN5_V2_Display_Partial(_blackImage,0,0,200+0,350+0);
        EPD_7IN5_V2_Sleep();
        DEV_Delay_ms(30000);

        // EPD_7IN5_V2_Display(_blackImage);
        }
        // EPD_7IN5_V2_Display(_blackImage);
        // Paint_DrawLine(105,105,175,105,BLACK,DOT_PIXEL_2X2, LINE_STYLE_SOLID);  // longer
        // Paint_DrawLine(105,105,105,155, BLACK,DOT_PIXEL_4X4,LINE_STYLE_SOLID);
       
        // std::cout<<"aa"<<std::endl;
        // Paint_SelectImage(_blackImage);
        // std::cout<<"aa 2"<<std::endl;
        // Paint_DrawLine(105,105,175,105,BLACK,DOT_PIXEL_2X2, LINE_STYLE_SOLID);  // longer
        // Paint_DrawLine(105,105,105,155, BLACK,DOT_PIXEL_4X4,LINE_STYLE_SOLID);
        // std::cout<<"aa 3"<<std::endl;
        // EPD_7IN5_V2_Display(_blackImage);
        // std::cout<<"aa 4"<<std::endl;
        return 1;
    }