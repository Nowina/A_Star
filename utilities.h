#ifndef UTILITIES_H
#define UTILITIES_H
template <class T>
struct nodeList {
    T data;
    int key;
    nodeList *next, *prev;
};
template <typename T>
struct node
{
   T data;
   node* next, *prev;
};
struct dir{
    int x;
    int y;
    dir(int x, int y):x(x),y(y){}
};

static dir dirs [8] = {
    dir(0,1),dir(1,1),dir(1,0),dir(1,-1),
    dir(0,-1),dir(-1,1),dir(-1,0),dir(-1,1)
};
#endif
