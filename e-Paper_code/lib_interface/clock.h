
#ifndef CLOCK_H
#define CLOCK_H

#include "base.h"
#include <ctime>

//Positions of 
static constexpr int hrsXTab[]= {
105, 130, 148, 155, 148, 130, 105, 80, 61, 55, 61, 80};
static constexpr int hrsYTab[]= {
55, 61, 79, 104, 130, 148, 155, 148, 130, 105, 80, 61};

static constexpr int minXTab[]={
104, 112, 119, 126, 133, 140, 146, 151, 157, 161, 165, 168, 171, 173, 174, 175,
174, 173, 171, 168, 165, 161, 157, 151, 146, 140, 133, 126, 119, 112, 105, 97,
90, 83, 76, 70, 63, 58, 52, 48, 44, 41, 38, 36, 35, 35, 35, 36, 38, 41, 44, 48,
52, 58, 63, 70, 76, 83, 90, 97,};

static constexpr int minYTab[]={
35, 35, 36, 38, 41, 44, 48, 52, 58, 63, 69, 76, 83, 90, 97, 104, 112, 119, 126,
133, 140, 146, 151, 157, 161, 165, 168, 171, 173, 174, 175, 174, 173, 171, 168,
165, 161, 157, 151, 146, 139, 133, 126, 119, 112, 105, 97, 90, 83, 76, 70, 63,
58, 52, 48, 44, 41, 38, 36, 35};


class PapClock : public BaseCord{

        time_t curr_time; 
    public:
        PapClock(){}
        PapClock(int n_cordx, int n_cordy, int n_maxx, int n_maxy) : BaseCord(n_cordx, n_cordy, n_maxx, n_maxy){
            curr_time = time(NULL);
        }
        PapClock(int n_maxx, int n_maxy):BaseCord(n_maxx,n_maxy){
            curr_time = time(NULL);
        }
        void printClock();
        void updateClock();
};
#endif