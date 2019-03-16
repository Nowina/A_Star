#include <iostream>
#include <priorityQueue.h>
#include <utilities.h>
#include <mapgraph.h>
#include <vector.h>
#include <graphnode.h>
using namespace std;

int main()
{
    MapGraph *map = new MapGraph(14,10);
    map->loadMap("C:\\Users\\Nowina\\Documents\\STUDIA\\ZAP2\\A_STAR\\test.map");
    map->printMap();
    GraphNode* current = map->getNode(4,5);
    current->setG(4);
    Vector<GraphNode*> *neighbors = map->getNeighbors(current);
    for (int i = 0; i < neighbors->getSize(); ++i) {
        cout<<neighbors->at(i)->data->getG()<<" ";
    }
    delete map;
}
