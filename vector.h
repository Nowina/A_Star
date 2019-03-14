#ifndef VECTOR_H
#define VECTOR_H
#include <structs.h>
#include <iostream>
using namespace std;
template<class T>
class Vector
{
private:
    unsigned int size;
    nodeList<T> *head;
    nodeList<T> *tail;
public:
    Vector(T element){
        nodeList<T> *newElement = new nodeList<T>;
        newElement->data = element;
        newElement->next = NULL;
        newElement->prev = NULL;
        head = newElement;
        tail = newElement;
        size = 1;
    }
    ~Vector(){
        nodeList<T> *temp;
        while (head != NULL){
            temp = head;
            head=head->next;
            delete temp;
        }
        delete head;
        size = 0;
    }
    unsigned int getSize(){
        return size;
    }
    nodeList<T> *push_back(T element){
        nodeList<T> *newElement = new nodeList<T>;
        newElement->data = element;
        newElement->prev = tail;
        newElement->next = NULL;
        tail->next = newElement;
        if (head == NULL){
            head = tail;
        }
        tail = newElement;
        size++;
        return newElement;
    }
    nodeList<T> *push_front(T element){
        nodeList<T> *newElement = new nodeList<T>;
        newElement->data = element;
        newElement->next = head;
        newElement->prev = NULL;
        if (head != NULL){
            head->prev = newElement;
        }
        head = newElement;
        size++;
        return head;
    }
    void printList()
    {
        if (size != 0){
            nodeList<T> *current = head;
            while (current != NULL) {
                cout<<current->data<<" ";
                current = current->next;
            }
            cout<<"\n";
        }
    }
    nodeList<T> *back(){
        return tail;
    }
    void pop_back(){
        if (size != 0){
            nodeList<T> *temp = tail;
            tail->prev= tail->prev;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            size--;
        }
    }
    void pop(){
        if (size != 0){
            nodeList<T> *temp = head;
            head->next = head->next;
            head = head->next;
            head->prev = NULL;
            delete temp;
            size--;
        }
    }
    void swapElements(unsigned int first,unsigned int second){
        nodeList<T> *left = this->at(first);
        nodeList<T> *right = this->at(second);
        T temp = left->data;
        left->data = right->data;
        right->data = temp;
    }
    nodeList<T>* at(unsigned int index){
        nodeList<T> *actual;
        unsigned int position;
        if (index <= size){
            if (index < size/2){
                position = 0;
                actual = head;
                while(position != index){
                    actual = actual->next;
                    position++;
                }
            }
            else if (index >= size/2) {
                actual = tail;
                position = size-1;
                while (position != index) {
                    actual = actual->prev;
                    position--;
                }
            }
            return actual;
        }
        else {
            return NULL;
        }
    }

    T & operator [ ] (unsigned int i){ //only to read values, = doesn't work
        return this->at(i)->data;
    }


};



#endif // VECTOR_H
