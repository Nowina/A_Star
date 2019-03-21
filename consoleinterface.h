#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H
#include <mapgraph.h>
#include <iostream>
#include <utilities.h>
#include <graphnode.h>
#include <vector.h>
using namespace std;
MapGraph *loadMap(){
    int x,y;
    string filename;
    cout<<"Set height of map: ";
    cin>>y;
    cout<<"Set width of map: ";
    cin>>x;
    MapGraph *map = new MapGraph(x,y);
    cout<<"Enter .map file name: ";
    cin>>filename;
    filename = filename+".map";
    ifstream file;
    file.open(filename.c_str(), ios::in);
    if (file.is_open()){
        string line;
        int y = 0;
        while (!file.eof()) {
            getline(file,line);
            for (unsigned int i = 0; i < line.size(); i++){
                if (line[i] == ' '){
                    map->getNode(int(i),y)->isObstacle = false;
                }
            }
            if (y == 9){
                break;
            }
            y++;
        }
        file.close();
    }
    return map;
}
void setGoalAndStart(MapGraph*&map){
    int xStart,yStart,xGoal,yGoal;
    cout<<"Set start x and y: ";
    cin>>xStart>>yStart;
    while (xStart > map->getDimensions().x || yStart > map->getDimensions().y || !map->getNode(xStart,yStart)->isPassable() ) {
        cout<<"Start cannot be outside map or on obstacle ! Enter valid numbers: "<<"\n";
        cin>>xStart>>yStart;
    }
    map->setStart(xStart,yStart);
    cout<<"Set goal x and y: ";
    cin>>xGoal>>yGoal;
    while (xGoal > map->getDimensions().x || yGoal > map->getDimensions().y || !map->getNode(xGoal,yGoal)->isPassable() ) {
        cout<<"Goal cannot be outside map or on obstacle ! Enter valid numbers: "<<"\n";
        cin>>xGoal>>yGoal;
    }
    map->setGoal(xGoal,yGoal);
}
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
void printPath(MapGraph * map, Vector<GraphNode*> path, double timeTook){
    bool startFound = false;
    bool goalFound  = false;
    location mapDimensions = map->getDimensions();
    location goal = map->getGoal();
    location start = map->getStart();
    int xSize = mapDimensions.x;
    int ySize = mapDimensions.y;
    cout<<"Path Found !!! Look at it ! :) It took me exactly: "<<timeTook<<"ms"<<"\n";
    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            GraphNode * node = map->getNode(x,y);
            location nodePosition = node->getPosition();
            bool isOnPath = false;
            for (int i = 0; i < path.getSize(); ++i) {
                if (nodePosition == path.at(i)->data->getPosition()){
                    isOnPath = true;
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
