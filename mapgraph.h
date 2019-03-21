#ifndef MAPGRAPH_H
#define MAPGRAPH_H
#include <iostream>
#include <matrixv2.h>
#include <graphnode.h>
#include <vector.h>
#include <utilities.h>
#include <fstream>
#include <priorityQueue.h>
#include <chrono>

typedef chrono::high_resolution_clock Stoper;
using namespace std;

class MapGraph
{
private:
    int xSize;
    int ySize;
    MatrixV2 *matrix;
    int size;
    location start, goal;
public:
    MapGraph( int xSize, int ySize);
    ~MapGraph(){
        delete matrix;
    }
    GraphNode* getNode(int x, int y);
    GraphNode* getNode(location location);
    location getDimensions();
    Vector<GraphNode*>* getNeighbors(GraphNode* parent);
    void setStart(int x, int y);
    location getStart();
    location getGoal();
    void setGoal(int x, int y);
    Vector<GraphNode*> aStarSearch(double &timeTook);
    Vector<GraphNode*> reconstructPath(GraphNode* goal);
};
#endif // MAPGRAPH_H
