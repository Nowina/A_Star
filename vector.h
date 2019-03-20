#ifndef VECTOR_H
#define VECTOR_H
#include <utilities.h>
#include <iostream>
using namespace std;
template<class T>

class Vector
{
private:
    int size;
    node<T> *head;
    node<T> *tail;
public:
    Vector(T element){
        node<T> *newElement = new node<T>;
        newElement->data = element;
        newElement->next = NULL;
        newElement->prev = NULL;
        head = newElement;
        tail = newElement;
        size = 1;
    }
    Vector(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    ~Vector(){
        node<T> *temp;
        while (head != NULL){
            temp = head;
            head=head->next;
            delete temp;
        }
        delete head;
        size = 0;
    }
    int getSize(){
        return size;
    }
    node<T> *push_back(T element){
        if (head == NULL){
            push_front(element);
            return NULL;
        }
        else {
            node<T> *newElement = new node<T>;
            newElement->data = element;
            newElement->prev = tail;
            newElement->next = NULL;
            tail->next = newElement;
            tail = newElement;
            size++;
            return newElement;
        }

    }
    node<T> *push_front(T element){
        node<T> *newElement = new node<T>;
        newElement->data = element;
        newElement->next = head;
        newElement->prev = NULL;
        if (head != NULL){
            head->prev = newElement;
        }else{
            tail = newElement;
        }
        head = newElement;
        size++;
        return head;
    }
    void printList() //test only
    {
        if (size != 0){
            node<T> *current = head;
            while (current != NULL) {
                cout<<current->data<<" ";
                current = current->next;
            }
            cout<<"\n";
        }
    }
    node<T> *back(){
        return tail;
    }
    void pop_back(){
        if (size != 1 && size != 0){
            node<T> *temp = tail;
            tail->prev= tail->prev;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            size--;
        }else {
            remove(0);
        }
    }
    void pop(){
        if (size != 1 && size != 0){
            node<T> *temp = head;
            head->next = head->next;
            head = head->next;
            head->prev = NULL;
            delete temp;
            size--;
        }
        else {
             remove(0);
        }
    }
    void swapElements(int first, int second){
        node<T> *left = this->at(first);
        node<T> *right = this->at(second);
        T temp = left->data;
        left->data = right->data;
        right->data = temp;
    }
    node<T>* at(int index){
        node<T> *actual;
        int position;
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
    void remove(int index){
        node<T> * temp = this->at(index);
        if (head == NULL){
            return;
        }
        if (temp == head){
            head = head->next;
        }
        if (temp == tail){
            tail = tail->prev;
        }
        if (temp->next != NULL){
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL){
            temp->prev->next = temp->next;
        }
        size--;
        delete temp;
    }
    bool contains(T element, int &position){ //checks whether Vector contains given element
        if (size == 0){
            return false;
        }
        else {
            position = 0;
            bool contains = false;
            node<T> *current = head;
            while (current != NULL) {
                position++;
                if (current->data == element){
                    break;
                }
                current = current->next;
            }
            return  contains;
        }
    }

    T & operator [ ] (unsigned int i){ //only to read values, = doesn't work
        return this->at(i)->data;
    }


};
#endif // VECTOR_H
