#ifndef MAPGRAPH_H
#define MAPGRAPH_H
#include <iostream>
#include <matrix.h>
#include <graphnode.h>
#include <vector.h>
#include <utilities.h>
#include <fstream>
using namespace std;

class MapGraph
{
private:
    int xSize;
    int ySize;
    Matrix<GraphNode*> *array;
    int size;
    location start, goal;
public:
    MapGraph( int xSize, int ySize) {
        this->xSize = xSize;
        this->ySize = ySize;
        array = new Matrix<GraphNode*>(xSize,ySize);
        size = array->getSize();
        for (int y = 0; y < ySize ; ++y) {
            for (int x = 0; x < xSize; ++x) {
                GraphNode *newNode = new GraphNode(x,y,true);
                array->write(x,y, newNode);
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
            if (!neighbor->isObstacle){
                neighbors->push_back(neighbor);
            }
        }
        return neighbors;
        delete neighbors;
    }

    void loadMap(string fileName){
        ifstream file;
        file.open(fileName.c_str(), ios::in);

        if (file.is_open()){
            char node;
            for (int y = 0; y < ySize; y++) {
                for (int x = 0; x < xSize; x++) {
                    file.get(node);
                    if (file.eof()){
                        break;
                    }
                    if (node == ' '){
                        getNode(x,y)->isObstacle = false;
                    }
                }
            }
            file.close();
        }

        for (int y = 0; y < ySize; y++) {
            for (int x = 0; x < xSize; x++) {
                if (getNode(x,y)->isObstacle){
                    cout<<"@";
                }
                else {
                    cout<<" ";
                }
            }
            cout<<"\n";
        }
    }
};
#endif // MAPGRAPH_H
