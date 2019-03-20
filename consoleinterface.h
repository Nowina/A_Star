#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H
#include <mapgraph.h>
#include <iostream>
using namespace std;
void printMap(MapGraph* map){ //TEST ONLY
    bool startFound = false;
    bool goalFound  = false;
    location mapDimensions = map->getDimensions();
    location goal = map->getGoal();
    location start = map->getStart();
    int xSize = mapDimensions.x;
    int ySize = mapDimensions.y;
    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            GraphNode * node = map->getNode(x,y);
            location nodePosition = node->getPosition();
            if (node->isObstacle){
                cout<<"@";
            }
            else if (nodePosition == goal && !goalFound) {
                cout<<"G";
                goalFound = true;
            }
            else if (nodePosition == start && !startFound){
                cout<<"S";
                startFound = true;
            }
            else {
                cout<<" ";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void printPath(MapGraph * map, Vector<GraphNode*> path){
    bool startFound = false;
    bool goalFound  = false;
    location mapDimensions = map->getDimensions();
    location goal = map->getGoal();
    location start = map->getStart();
    int xSize = mapDimensions.x;
    int ySize = mapDimensions.y;
    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            GraphNode * node = map->getNode(x,y);
            location nodePosition = node->getPosition();
            int index = 0;
            bool isOnPath = false;
            for (int i = 0; i < path.getSize(); ++i) {
                if (nodePosition == path.at(i)->data->getPosition()){
                    isOnPath = true;
                    index = i;
                }
            }
            if (node->isObstacle){
                cout<<"@";
            }
            else if (nodePosition == goal && !goalFound) {
                cout<<"G";
                goalFound = true;
            }
            else if (nodePosition == start && !startFound){
                cout<<"S";
                startFound = true;
            }
            else if (isOnPath) {
                cout<<"-";
            }
            else {
                cout<<" ";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
}
#endif // CONSOLEINTERFACE_H
