#ifndef DATE_H
#define DATE_H

#include "base.h"
#include <ctime>
#include <array>

// constexpr std::array<std::pair<int,const char*>,7> weekday{{
//     {0,"Monday"}, {1,"Tuesday"}, {2,"Wednesday"},{3,"Thursday"},
//     {4,"Friday"}, {5,"Saturday"}, {6,"Sunday"},
// }};

// constexpr std::array<std::pair<int,const char*>,12> months{{
//     {0,"January"}, {1,"February"}, {2,"March"},{3,"April"},
//     {4,"May"}, {5,"Juni"}, {6,"July"},{7,"August"},
//     {8,"September"},{9,"October"},{10,"Novembre"},{11,"Decembre"},
// }};

constexpr std::array<const char*,7> weekday {
    "Monday","Tuesday","Wednesday","Thursday",
    "Friday","Saturday", "Sunday",
};

constexpr std::array<const char*,12> months{
    "January", "February", "March","April",
    "May", "Juni","July","August",
    "September","October","Novembre","Decembre",
    };

class Date: public BaseCord{


    public:
        Date(){}
        Date(int x, int y, int resX, int resY):BaseCord(x,y,resX,resY){}
        void updateDate();

};




#endif //DATE_H