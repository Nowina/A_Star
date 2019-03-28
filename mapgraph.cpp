#include <mapgraph.h>
MapGraph::MapGraph( int xSize, int ySize) {
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
GraphNode* MapGraph::getNode(int x, int y){
    return matrix->at(x,y);
}
GraphNode* MapGraph::getNode(location location){
    return matrix->at(location.x,location.y);
}
location MapGraph::getDimensions(){
    location dim(xSize,ySize);
    return dim;
}
Vector<GraphNode*>* MapGraph::getNeighbors(GraphNode* parent){
    Vector<GraphNode*> *neighbors = new Vector<GraphNode*>;
    location position = parent->getPosition();
    int neighborX = 0;
    int neighborY = 0;
    GraphNode *neighbor;
    for (int i = 0; i < 8; ++i) {
        neighborX = position.x + dirs[i].x;
        neighborY = position.y + dirs[i].y;
        if ( !(neighborX < 0 || neighborX >= xSize || neighborY < 0 || neighborY >= ySize)){
            neighbor = getNode(neighborX,neighborY);
            if ( neighbor->isPassable() == true && neighbor->wasVisited == false ){
                if (neighbor->parent == nullptr && neighbor->getPosition() != start){
                    neighbor->parent = parent;
                }
                neighbor->wasVisited = true;
                neighbor->setG(parent->getG() + parent->calculateG(neighbor->getPosition()));
                neighbor->calculateH(goal);
                neighbor->calculateF();
                neighbors->push_back(neighbor);
            }
        }
    }
    return neighbors;
}
void MapGraph::setStart(int x, int y){ //use only after the map was loaded
    if (!getNode(x,y)->isObstacle){
        start.x = x;
        start.y = y;
    }
}
location MapGraph::getStart(){
    return start;
}
location MapGraph::getGoal(){
    return goal;
}
void MapGraph::setGoal(int x, int y){ //use only after the map was loaded
    if (!getNode(x,y)->isObstacle){
        goal.x = x;
        goal.y = y;
    }
}
Vector<GraphNode*>* MapGraph::aStarSearch(double &timeTook){
    auto t1 = Stoper::now();
    GraphNode* start = getNode(this->start);
    start->parent = nullptr;
    start->setG(0);
    start->calculateH(goal);
    start->calculateF();

    PriorityQueue<GraphNode*> open(start,0);
    KeyVector<GraphNode*> closed(start,0);
    Vector<GraphNode*> *neighbors;
    Vector<GraphNode*> *path;
    GraphNode * current;
    open.push(start, 0);
    start->wasVisited = true;
    start->inOpen = true;
    while ( !(open.isEmpty()) ) {
        current = open.top(); //get current from OPEN
        location currentLocation = current->getPosition(); //get location of current

        if (currentLocation == goal){ //check if goal reached
            path = reconstructPath(current);
            auto t2 = Stoper::now();
            timeTook = chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
            return path;
        }
        open.pop(); //remove current from OPEN
        current->inOpen = false;
        closed.push_front(current,current->getG()); //add current to CLOSED
        current->inClosed = true;
        neighbors = getNeighbors(current); //get neighbors of CURRENT

        for (int  i = 0;  i < neighbors->getSize(); i++){
            GraphNode *neighbor = neighbors->at(i)->data;
            location neighborLocation = neighbor->getPosition();
            int neighborClosedIndex = closed.getIndex(neighbor);
            if (neighbor->inClosed){
                continue;
            }
            int neighborTentativeG = current->getG() + current->calculateG(neighborLocation);
            if (!neighbor->inOpen){
                neighbor->setG(neighborTentativeG);
                neighbor->calculateF();
                open.push(neighbor,neighbor->f);
                neighbor->inOpen = true;
            }
            else if (neighborTentativeG >= closed.at(neighborClosedIndex)->data->getG()) {
                continue;
            }
        }
    }
    return path;
}
Vector<GraphNode*>* MapGraph::reconstructPath(GraphNode* goal){
    Vector<GraphNode*> *path = new Vector<GraphNode*>();
    GraphNode* current = goal;
    while (current->parent != nullptr) {
        path->push_front(current);
        current = current->parent;
    }
    return path;
}

