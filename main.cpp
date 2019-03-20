#include <iostream>
#include <priorityQueue.h>
#include <utilities.h>
#include <mapgraph.h>
#include <vector.h>
#include <keyvector.h>
#include <graphnode.h>
#include <consoleinterface.h>
using namespace std;

int main()
{
    MapGraph *map = new MapGraph(14,10);
    map->loadMap("C:\\Users\\Nowina\\Documents\\STUDIA\\ZAP2\\A_STAR\\test.map");
    map->setStart(0,1);
    map->setGoal(7,3);
    printMap(map);
    Vector<GraphNode*> path = map->aStarSearch();
    printPath(map,path);
    delete map;
}
