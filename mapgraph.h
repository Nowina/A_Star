#ifndef MAPGRAPH_H
#define MAPGRAPH_H
#include <iostream>
#include <matrix.h>
#include <graphnode.h>
#include <vector.h>
#include <utilities.h>
using namespace std;

class MapGraph
{
private:
    int xSize;
    int ySize;
    Matrix<GraphNode*> *array;
    int size;
public:
    MapGraph( int xSize, int ySize) {
        this->xSize = xSize;
        this->ySize = ySize;
        array = new Matrix<GraphNode*>(xSize,ySize);
        size = array->getSize();
        for (int i = 0; i < xSize ; ++i) {
            for (int j = 0; j < ySize; ++j) {
                GraphNode *newNode = new GraphNode(i,j,true);
                array->write(i,j, newNode);
            }
        }
    }
    ~MapGraph(){
        delete array;
    }
    GraphNode* getNode(int x, int y){
        return array->at(x,y);
    }
    Vector<GraphNode*>* getNeighbors(int x, int y){
        Vector<GraphNode*> *neighbors = new Vector<GraphNode*>;
        for (int i = 0; i < 8; ++i) {
            GraphNode * neighbor = array->at(x + dirs[i].x, y + dirs[i].y);
            if (neighbor->isPassable()){
                neighbors->push_back(neighbor);
            }
        }
        return neighbors;
    }
};
#endif // MAPGRAPH_H
