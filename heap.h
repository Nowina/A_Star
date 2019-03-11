#ifndef HEAP_H
#define HEAP_H

#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y);

class Heap
{
private:
    vector<int> A;
    int capacity;
    int heap_size;

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return (2*i +1);
    }

    int right(int i){
        return (2*i+2);
    }

    void heapify_down(int index); //sorting a subtree with root on given index

    void heapify_up(int index); //sorting uptree
public:
    Heap();

    unsigned int size(){
        return this->A.size();
    }

    bool isEmpty(){
        return this->size() == 0;
    }

    void push(int key); //instert new key to heap

    void pop(); //remove element with highest priority

    int top(); //return element with highest priority


};

#endif // HEAP_H
