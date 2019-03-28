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
        int minIndex = i;

        if (left < size() && A->at(left)->key < A->at(minIndex)->key){
            minIndex = left;
        }
        if (right < size() && A->at(right)->key < A->at(minIndex)->key){
            minIndex = right;
        }

        if (minIndex != i){
            A->swapElements(i,minIndex);
            heapify_down(minIndex);
        }
    }
    void heapify_up(int i) //sorting uptree
    {
        int parent = this->parent(i);
        if (i && A->at(parent)->key > A->at(i)->key){
            A->swapElements(i,parent);
            heapify_up(parent);
        }
    }
public:
    PriorityQueue(T firstElement,int key){
        A = new KeyVector<T>(firstElement,key);
    }
    PriorityQueue(){
        A = new KeyVector<T>();
    }
    ~PriorityQueue(){
        delete A;
    }

    int size(){
        return A->getSize();
    }

    bool isEmpty(){
        return size() == 0;
    }

    void push(T newElement,int key) //instert new key to heap
    {
        A->push_back(newElement,key);
        int index = size() - 1;
        heapify_up(index);
    }
    void pop() //remove element with highest priority
    {
        if (size() != 0){
            A->swapElements(0,A->getSize()-1);
            A->pop_back();
            heapify_down(0);
        }
    }
    T at(int index){
        return A->at(index)->data;
    }
    void remove(int index){
        A->remove(index);
    }
    void changeKey(int index, int newKey){
        A->changeKey(index, newKey);
    }
    T top() //return element with highest priority
    {
        if (size() != 0){
            return A->at(0)->data;
        }
        return nullptr;
    }
    bool contains(T element, int &position){ //checks whether Vector contains given element
        return A->contains(element,position);
    }
};

#endif // HEAP_H
