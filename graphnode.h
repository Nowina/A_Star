#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include <iostream>
#include <keyvector.h>
#include <cmath>
#include <utilities.h>
using namespace std;
class GraphNode
{
private:
    int g; //g value for A*
    int h; //heuristic value
    location position;
    int d =1;
    double d2 = sqrt(2);
public:
    bool isObstacle;
    int f; //g +h
    GraphNode(int x, int y) {
        position.x = x;
        position.y= y;
        isObstacle = false;
    }
    GraphNode(int x, int y, bool isObstacle){
        position.x = x;
        position.y = y;
        this->isObstacle = isObstacle;
    }
    ~GraphNode(){}
    void calculateF(){
        f = g + h;
    }
    void setG(int newG){
        g = newG;
    }
    bool isPassable(){
        return !isObstacle;
    }
    void calculateH(location goal){
        int dx = abs(position.x - goal.x);
        int dy = abs(position.y - goal.y);
        h = d * (dx + dy) + int((d2 - 2*d))*min(dx,dy);
    }

};
#endif // GRAPHNODE_H
