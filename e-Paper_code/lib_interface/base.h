
#ifndef BASE_H
#define BASE_H
#include<iostream>

class BaseCord{
    int cordx;
    int cordy;
    int const maxResx;
    int const maxResy;
    // int const maxRes[2];  //[0] - max x res, [1]- max y res

public:
    BaseCord():maxResx(1000), maxResy(1000) { std::cout<<"Used Base constructor"<<std::endl; cordx = 0; cordy = 0;}
    BaseCord(int n_cordx, int n_cordy, int n_maxx, int n_maxy) : cordx(n_cordx), cordy(n_cordy), maxResx(n_maxx), maxResy(n_maxy) {}
    BaseCord(int n_maxx, int n_maxy): maxResx(n_maxx), maxResy(n_maxy) {cordx = 0; cordy = 0;}
    
    void setCord(int cordx, int cordy);
    int getCord();
    int getMaxRes();
    // void setMaxRes(int maxx, int maxy);
};

#endif