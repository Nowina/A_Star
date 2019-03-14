#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include <iostream>
#include <keyvector.h>
#include <cmath>
using namespace std;
class GraphNode
{
private:
    int g; //g value for A*
    int h; //heuristic value
    int x; //x position
    int y; //y position
    int d;
    void calculateF(){
        f = g + h;
    }
public:
    bool isObstacle;
    GraphNode(int x, int y) {
        this->x = x;
        this->y = y;
        isObstacle = false;
    }
    GraphNode(int x, int y, bool isObstacle){
        this->x = x;
        this->y = y;
        this->isObstacle = isObstacle;
    }
    ~GraphNode(){}
    int f; //g +h

    void calculateH(int gx,int gy){ //gx,gy -> goal coordinates
        int dx = abs(x - gx);
        int dy = abs(y - gy);
        h = d * (dx + dy) + (d - 2*d)*min(dx,dy);
        calculateF();
    }

};
#endif // GRAPHNODE_H
