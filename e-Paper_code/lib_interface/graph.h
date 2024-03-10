
#ifndef GRAPH_H
#define GRAPH_H

#include "base.h"
#include <string>

class xGraph::public BaseCord{

    std::string _graphTitle;
    std::string _xAxisName;
    std::string _yAxisName;
    int _point_Number;

    public:
    xGraph(){}
    xGraph(const std::string& title, const std::string& xaxis, const std::string& yaxis):BaseCord(100,100),
     _graphTitle(title), _xAxisName(xaxis), _yAxisName(yaxis){}
    xGraph(int n_cordx, int n_cordy, int n_maxx, int n_maxy) : BaseCord(n_cordx, n_cordy, n_maxx, n_maxy){}
    xGraph(int n_maxx, int n_maxy):BaseCord(n_maxx,n_maxy){}
    void printGraph();
    void updateGraph();
    int getPointNumber(){return point_number;}

}





#endif  //GRAPH_H