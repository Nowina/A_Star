#ifndef VECTOR_H
#define VECTOR_H

template <class T>

class Vector
{
private:
    int capacity;
    int size;
    T *array;

public:
    Vector();

    int getSize();

    void pushBack(const T&Item);

    T back();

    void pop_back();

    T at(int index);

    T & operator [ ] (unsigned int i){
        if (i < this->size){
            return array[i];
        }
    }

};



#endif // VECTOR_H
