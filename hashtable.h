#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <utilities.h>
#include <string>
using namespace std;
template <class T>
class HashTable
{
private:
    int size;
    int hash(string key);
    hashNode<T> *table;
public:
    HashTable(int size);
    ~HashTable(){
        delete [] table;
    }
};

#endif // HASHTABLE_H
