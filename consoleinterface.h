#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H
#include <mapgraph.h>
#include <iostream>
#include <utilities.h>
#include <graphnode.h>
#include <vector.h>
#include <fstream>
using namespace std;
MapGraph *loadMap();
void setGoalAndStart(MapGraph*&map);
void printMap(MapGraph* map);
void printPathToConsole(MapGraph * map, Vector<GraphNode*>*path, double timeTook);
void printPathToFile(MapGraph * map, Vector<GraphNode*>*path, double timeTook,string filename);
#endif // CONSOLEINTERFACE_H
