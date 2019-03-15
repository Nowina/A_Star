#include <iostream>
#include <priorityQueue.h>
#include <utilities.h>
#include <mapgraph.h>
#include <vector.h>
using namespace std;

int main()
{
    MapGraph *map = new MapGraph(14,10);
    map->loadMap("C:\\Users\\Nowina\\Documents\\STUDIA\\ZAP2\\A_STAR\\test.map");
    map->printMap();
    delete map;
}
