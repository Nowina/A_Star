#ifndef MAPGRAPH_H
#define MAPGRAPH_H
#include <iostream>
#include <matrixv2.h>
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
    MatrixV2 *matrix;
    int size;
    location start, goal;
public:
    MapGraph( int xSize, int ySize) {
        this->xSize = xSize;
        this->ySize = ySize;
        matrix = new MatrixV2(xSize,ySize);
        size = matrix->getSize();
        for (int y = 0; y < ySize ; ++y) {
            for (int x = 0; x < xSize; ++x) {
                GraphNode *newNode = new GraphNode(x,y,true);
                matrix->write(x,y,newNode);
            }
        }
    }
    ~MapGraph(){
        delete matrix;
    }
    GraphNode* getNode(int x, int y){
        return matrix->at(x,y);
    }
    Vector<GraphNode*>* getNeighbors(int x, int y){
        Vector<GraphNode*> *neighbors = new Vector<GraphNode*>;
        int neighborX = 0;
        int neighborY = 0;
        GraphNode *neighbor;
        for (int i = 0; i < 8; ++i) {
            neighborX = x + dirs[i].x;
            neighborY = y + dirs[i].y;
            if ( !(neighborX < 0 || neighborX >= xSize || neighborY < 0 || neighborY >= ySize) ){
                neighbor = getNode(neighborX,neighborY);
                if ( neighbor->isPassable() == true){
                   neighbors->push_back(neighbor);
                }
            }
        }
        return neighbors;
        delete neighbors;
    }

    void loadMap(string fileName){
        ifstream file;
        file.open(fileName.c_str(), ios::in);
        if (file.is_open()){
            string line;
            int y = 0;
            while (!file.eof()) {
                getline(file,line);
                for (unsigned int i = 0; i < line.size(); i++){
                    if (line[i] == ' '){
                        getNode(int(i),y)->isObstacle = false;
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
    void setStart(int x, int y){
        start.x = x;
        start.y = y;
    }
    void setGoal(int x, int y){
        goal.x = x;
        goal.y = y;
    }
};
#endif // MAPGRAPH_H
