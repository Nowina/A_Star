#ifndef MAPGRAPH_H
#define MAPGRAPH_H
#include <iostream>
#include <matrixv2.h>
#include <graphnode.h>
#include <vector.h>
#include <utilities.h>
#include <fstream>
#include <priorityQueue.h>
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
                newNode->parent = nullptr;
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
    GraphNode* getNode(location location){
        return matrix->at(location.x,location.y);
    }
    location getDimensions(){
        location dim(xSize,ySize);
        return dim;
    }
    Vector<GraphNode*>* getNeighbors(GraphNode* parent){
        Vector<GraphNode*> *neighbors = new Vector<GraphNode*>;
        location position = parent->getPosition();
        int neighborX = 0;
        int neighborY = 0;
        GraphNode *neighbor;
        for (int i = 0; i < 8; ++i) {
            neighborX = position.x + dirs[i].x;
            neighborY = position.y + dirs[i].y;
            if ( !(neighborX < 0 || neighborX >= xSize || neighborY < 0 || neighborY >= ySize) ){
                neighbor = getNode(neighborX,neighborY);
                if ( neighbor->isPassable() == true){
                    if (neighbor->parent == nullptr && neighbor->getPosition() != start){
                        neighbor->parent = parent;
                    }
                    neighbor->setG(parent->getG() + parent->calculateG(neighbor->getPosition()));
                    neighbor->calculateH(goal);
                    neighbor->calculateF();
                    neighbors->push_back(neighbor);
                }
            }
        }
        return neighbors;
    }
    void setStart(int x, int y){ //use only after the map was loaded
        if (!getNode(x,y)->isObstacle){
            start.x = x;
            start.y = y;
        }
    }
    location getStart(){
        return start;
    }
    location getGoal(){
        return goal;
    }
    void setGoal(int x, int y){ //use only after the map was loaded
        if (!getNode(x,y)->isObstacle){
            goal.x = x;
            goal.y = y;
        }
    }
    Vector<GraphNode*> aStarSearch(){
        GraphNode* start = getNode(this->start);
        start->parent = nullptr;
        start->setG(0);
        start->calculateH(goal);
        start->calculateF();

        PriorityQueue<GraphNode*> *open = new PriorityQueue<GraphNode*>(start,0);
        KeyVector<GraphNode*> *closed = new KeyVector<GraphNode*>(start,0);
        Vector<GraphNode*> *neighbors;
        Vector<GraphNode*> path;
        GraphNode * current;
        open->push(start, 0);

        while ( !(open->isEmpty()) ) {
            current = open->top(); //get current from OPEN
            current->wasVisited = true;
            location currentLocation = current->getPosition(); //get location of current

            if (currentLocation == goal){ //check if goal reached
                path = reconstructPath(current);
                delete open;
                delete closed;
                return path;
            }

            open->pop(); //remove current from OPEN
            closed->push_front(current,current->getG()); //add current to CLOSED

            neighbors = getNeighbors(current); //get neighbors of CURRENT

            for (int  i = 0;  i < neighbors->getSize(); i++){
                GraphNode *neighbor = neighbors->at(i)->data;
                location neighborLocation = neighbor->getPosition();
                int neighborOpenIndex = 0;
                int neighborClosedIndex = 0;
                bool inOpen = open->contains(neighbor,neighborOpenIndex);
                bool inClosed = closed->contains(neighbor,neighborClosedIndex);

                if (inClosed || neighbor->wasVisited){
                    continue;
                }

                int neighborTentativeG = current->getG() + current->calculateG(neighborLocation);

                if (!inOpen){
                    neighbor->setG(neighborTentativeG);
                    neighbor->calculateF();
                    open->push(neighbor,neighbor->f);
                }
                else if (neighborTentativeG >= closed->at(neighborClosedIndex)->data->getG()) {
                    continue;
                }
            }
        }
        delete open;
        delete closed;
        return path;
    }
    Vector<GraphNode*> reconstructPath(GraphNode* goal){
        Vector<GraphNode*> path;
        GraphNode* current = goal;
        while (current->parent != nullptr) {
            path.push_front(current);
            current = current->parent;
        }
        return path;
    }
};
#endif // MAPGRAPH_H
