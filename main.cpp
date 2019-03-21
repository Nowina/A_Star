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
    double timeTook = 0;
    Vector<GraphNode*> path = map->aStarSearch(timeTook);
    printPath(map,path,timeTook);
    delete map;
}
