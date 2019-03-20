#include <iostream>
#include <mapgraph.h>
#include <consoleinterface.h>
using namespace std;

int main()
{
    MapGraph* map = loadMap();
    printMap(map);
    setGoalAndStart(map);
    printMap(map);
    Vector<GraphNode*> path = map->aStarSearch();
    printPath(map,path);
    delete map;
}
