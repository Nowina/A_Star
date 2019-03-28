#include <iostream>
#include <mapgraph.h>
#include <consoleinterface.h>
using namespace std;

int main()
{
    MapGraph* map = loadMap();
    setGoalAndStart(map);
    printMap(map);
    double timeTook = 0;
    Vector<GraphNode*> *path = map->aStarSearch(timeTook);
    printPathToFile(map,path,timeTook,"output.txt");
    delete map;
}
