#include "heap.h"
#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
Heap::Heap(){

}
void Heap::heapify_down(int i){
    int left = this->left(i);
    int right = this->right(i);
    int maxIndex = i;

    if (left < size() && A[left] > A[maxIndex]){
        maxIndex = left;
    }
    if (right < size() && A[right] > A[maxIndex]){
        maxIndex = right;
    }

    if (maxIndex != i){
        swap(A[i], A[maxIndex]);
        heapify_down(maxIndex);
    }
}

void Heap::heapify_up(int i){
    int parent = this->parent(i);
    if (i && A[parent] < A[i]){
        swap(A[i], A[parent]);
        heapify_up(parent);
    }
}
void Heap::push(int key){
    A.push_back(key);
    int index = size() - 1;
    heapify_up(index);
}

void Heap::pop(){
    try {
        if (size() == 0){
            throw out_of_range("index is out of range");
        }
        A[0] = A.back();
        A.pop_back();
        heapify_down(0);
    }
    catch (const out_of_range& oor){
        cout<<"\n"<< oor.what();
    }
}

int Heap::top(){
    try {
        if (size() == 0){
            throw out_of_range("index out of range");
        }
        return A.at(0);
    }
    catch(const out_of_range &oor){
        cout<<"\n"<< oor.what();
    }
}
