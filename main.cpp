#include <iostream>
#include <vector.h>
#include <heap.h>
#include <structs.h>
using namespace std;
class GraphNode{
public:
    int data;
    GraphNode();
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
   Vector<GraphNode*> *vector  = new Vector<GraphNode*>(node0);
   vector->push_front(node1);
   vector->push_back(node2);
   vector->push_back(node3);
   vector->push_back(node4);
   for (unsigned int i =0; i < vector->getSize(); i++){
       cout<<vector->at(i)->data->data<<" ";
   }
   delete vector;
}
