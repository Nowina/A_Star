#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <keyvector.h>
using namespace std;
template <class T>
class PriorityQueue
{
private:
    KeyVector<T> *A;

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return (2*i +1);
    }

    int right(int i){
        return (2*i+2);
    }

    void heapify_down(int i) //sorting a subtree with root on given index
    {
        int left = this->left(i);
        int right = this->right(i);
        int maxIndex = i;

        if (left < size() && A->at(left)->key > A->at(maxIndex)->key){
            maxIndex = left;
        }
        if (right < size() && A->at(right)->key > A->at(maxIndex)->key){
            maxIndex = right;
        }

        if (maxIndex != i){
            A->swapElements(i,maxIndex);
            heapify_down(maxIndex);
        }
    }
    void heapify_up(int i) //sorting uptree
    {
        int parent = this->parent(i);
        if (i && A->at(parent)->key < A->at(i)->key){
            A->swapElements(i,parent);
            heapify_up(parent);
        }
    }
public:
    PriorityQueue(T firstElement,int key){
        A = new KeyVector<T>(firstElement,key);
    }
    ~PriorityQueue(){
        delete A;
    }

    int size(){
        return this->A->getSize();
    }

    bool isEmpty(){
        return this->size() == 0;
    }

    void push(T newElement,int key) //instert new key to heap
    {
        A->push_back(newElement,key);
        int index = size() - 1;
        heapify_up(index);
    }
    void pop() //remove element with highest priority
    {
        try {
            if (size() == 0){
                throw out_of_range("index is out of range");
            }
            A->swapElements(0,A->getSize()-1);
            A->pop_back();
            heapify_down(0);
        }
        catch (const out_of_range& oor){
            cout<<"\n"<< oor.what();
        }
    }
    T top() //return element with highest priority
    {
        try {
            if (size() == 0){
                throw out_of_range("index out of range");
            }
            return A->at(0)->data;
        }
        catch(const out_of_range &oor){
            cout<<"\n"<< oor.what();
        }
        return NULL;
    }
};

#endif // HEAP_H
