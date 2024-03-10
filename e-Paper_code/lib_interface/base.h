
#ifndef BASE_H
#define BASE_H
#include<iostream>


class Cord{
        
        int const _x;
        int const _y;
        
    public:
        Cord():_x(0),_y(0){}
        Cord(int x,int y):_x(x),_y(y){}
            
        int operator[](int index){
            switch(index){
                case 0:
                    return _x;
                    break;
                case 1:
                    return _y;
                    break;
                default:
                    return _x;  //change this
                    break;
                }
            }
};


class BaseCord{

    protected:
        Cord  _cord;
        Cord  _resCord;

    public:
        BaseCord(): _cord(Cord(0,0)), _resCord(Cord(1000,1000)){}
        BaseCord(int x, int y, int y_max, int x_max):_cord(Cord(x,y)),_resCord(Cord(x_max,y_max)){}
        BaseCord(Cord place, Cord res): _cord(place),_resCord(res){}
        void setCord(int cordx, int cordy);
        
        Cord getCord(){return _cord;}
        Cord getRes(){return _resCord;}

        int getCord(int z){return _cord[z];}
        int getRes(int z){return _resCord[z];}
};

#endif