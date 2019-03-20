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
    const int d =1;
    const double d2 = sqrt(2);
    int diagonalDistance (location location){
        int dx = abs(position.x - location.x);
        int dy = abs(position.y - location.y);
        int cost = d * (dx + dy) + int((d2 - 2*d))*min(dx,dy);
        return cost;
    }
public:
    GraphNode* parent;
    bool isObstacle;
    int f; //g +h
    GraphNode(int x, int y) {
        position.x = x;
        position.y= y;
        g = 0;
        h = 0;
        f = 0;
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
    void addToG(int newG){
        g += newG;
    }
    void setG(int newG){
        g = newG;
    }
    int getG(){
        return g;
    }
    bool isPassable(){
        return !isObstacle;
    }
    location getPosition(){
        return position;
    }
    int calculateG(location location){
        int cost = diagonalDistance(location);
        return cost;
    }
    int calculateH(location goal){
        h = diagonalDistance(goal);
        return h;
    }
    bool operator == (GraphNode other){
        return other.getPosition() == this->getPosition();
    }

};
#endif // GRAPHNODE_H
