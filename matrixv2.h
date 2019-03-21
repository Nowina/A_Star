#ifndef MATRIXV2_H
#define MATRIXV2_H
#include <graphnode.h>
#include <iostream>
class MatrixV2
{
private:
    GraphNode ***nodes;
    int width;
    int height;
    int size;
public:
    MatrixV2(int x, int y);
    ~MatrixV2();
    GraphNode* at(int x, int y);
    void write(int x, int y, GraphNode* newNode);
    int getSize();
};
#endif // MATRIXV2_H
