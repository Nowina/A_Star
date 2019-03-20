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
struct location{
    int x;
    int y;
    location(){}
    location(int x, int y):x(x),y(y){}
    bool operator==(const location other) const{
        return (x == other.x && y == other.y);
    }
    bool operator!=(const location other) const{
        return !(x == other.x && y == other.y);
    }
};

static location dirs [8] = {
    location(0,1),location(1,1),location(1,0),location(1,-1),
    location(0,-1),location(-1,1),location(-1,0),location(-1,1)
};
#endif
