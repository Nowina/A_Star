#ifndef STRUCTS_H
#define STRUCTS_H
template <class T>
struct nodeList {
    T data;
    nodeList *next, *prev;
};
#endif // STRUCTS_H
