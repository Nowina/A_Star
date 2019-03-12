#ifndef VECTOR_H
#define VECTOR_H
#include <structs.h>
#include <iostream>
template<class T>
class Vector
{
private:
    unsigned int size;
    nodeList<T> *head;
    nodeList<T> *tail;
public:
    Vector(){
        head=tail=NULL;
        size = 0;
    }
    ~Vector(){
        nodeList<T> *temp;
        while (head){
            temp = head->next;
            delete head;
            head = temp;
        }
        size = 0;
    }
    nodeList<T> *push_back(T element){
        nodeList<T> *actual = new nodeList<T>;
        actual->data = element;
    }
    nodeList<T> * push_front(T element){
        nodeList<T> *newElement = new nodeList<T>;
        newElement->data = element;
        newElement->next = head;
        newElement->prev = NULL;
        if (head != NULL){
            head->prev = newElement;
        }
        head = newElement;
        size++;
    }

    T & operator [ ] (unsigned int i){
        if (i < this->size){
//            return array[i];
        }
    }

};



#endif // VECTOR_H
