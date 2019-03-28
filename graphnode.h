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
    const int d = 1; //cost of horizontal/vertical movement
    const double d2 = sqrt(2); //cost of diagonal movement

    int diagonalDistance (location location);

public:
    GraphNode* parent;
    bool isObstacle;
    bool wasVisited = false;
    bool inOpen = false;
    bool inClosed = false;
    int f; //g +h
    GraphNode(int x, int y);
    GraphNode(int x, int y, bool isObstacle);
    ~GraphNode(){}
    void calculateF();
    void setG(int newG);
    int getG();
    bool isPassable();
    location getPosition();
    int calculateG(location location);
    int calculateH(location goal);
    bool operator == (GraphNode other);
};
#endif // GRAPHNODE_H
