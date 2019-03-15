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
//            char node;
            string line;
            int y = 0;
            while (!file.eof()) {
                getline(file,line);
                for (int i = 0; i < line.size(); i++){
                    if (line[i] == ' '){
                        getNode(i,y)->isObstacle = false;
                    }
                }
                if (y == 9){
                    break;
                }
                y++;
            }
            file.close();
        }
    }
    void printMap(){
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
