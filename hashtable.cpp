#include "hashtable.h"
template <class T>
HashTable<T>::HashTable(int size)
{
    this->size = size;
    table = new hashNode<T>[size];
}
template <class T>
int HashTable<T>::hash(string key){
    int hash = 0;
    for (unsigned int i = 0; i <key.length(); i++){
        hash += (int)key[i];
    }
    return hash % size;
}
