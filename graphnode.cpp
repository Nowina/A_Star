#include <graphnode.h>

int GraphNode::diagonalDistance (location location){
    int dx = abs(position.x - location.x);
    int dy = abs(position.y - location.y);
    int cost = d * (dx + dy) + int((d2 - 2*d))*min(dx,dy);
    return cost;
}
GraphNode::GraphNode(int x, int y){
    {
           position.x = x;
           position.y= y;
           g = 0;
           h = 0;
           f = 0;
           isObstacle = false;
       }
}
GraphNode::GraphNode(int x, int y, bool isObstacle){
    position.x = x;
    position.y = y;
    this->isObstacle = isObstacle;
}
void GraphNode::calculateF(){
    f = g + h;
}
void GraphNode::setG(int newG){
    g = newG;
}
int GraphNode::getG(){
    return g;
}
bool GraphNode::isPassable(){
    return !isObstacle;
}
location GraphNode::getPosition(){
    return position;
}
int GraphNode::calculateG(location location){
    int cost = diagonalDistance(location);
    return cost;
}
int GraphNode::calculateH(location goal){
    h = diagonalDistance(goal);
    return h;
}
bool GraphNode::operator == (GraphNode other){
    return other.getPosition() == this->getPosition();
}
