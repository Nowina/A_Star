#include <iostream>
#include <priorityQueue.h>
#include <structs.h>
using namespace std;
class GraphNode{
public:
    int data;
    GraphNode();
    ~GraphNode(){}
    GraphNode(int i){
        data = i;
    }
};
int main()
{
    GraphNode *node0 = new GraphNode(0);
    GraphNode *node1 = new GraphNode(1);
    GraphNode *node2 = new GraphNode(2);
    GraphNode *node3 = new GraphNode(3);
    GraphNode *node4 = new GraphNode(4);
    PriorityQueue<GraphNode*> *heap = new PriorityQueue<GraphNode*>(node0,0);
    heap->push(node1,2);
    heap->push(node2,1);
    cout<<heap->top()->data<<"\n";
    heap->push(node3,9);
    heap->push(node4,20);
    heap->pop();
    heap->push(node4,9);
    cout<<heap->top()->data<<"\n";
    delete heap;
    delete node0;
    delete node1;
    delete node2;
    delete node3;
    delete node4;

}
