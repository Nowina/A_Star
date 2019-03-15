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
    MatrixV2(int x, int y) {
        width = x;
        height = y;
        size = x*y;
        nodes = new GraphNode**[y];
        for (int i = 0; i < y; ++i) {
            nodes[i] = new GraphNode*[x];
        }
    }
    ~MatrixV2(){
        for (int i = 0; i < height; i++) {
            for (int j = 0; j< width; j++) {
                delete nodes[i][j];
            }
            delete nodes[i];
        }
        delete [] nodes;
    }
    GraphNode* at(int x, int y){
        return nodes[y][x];
    }
    void write(int x, int y, GraphNode* newNode){
        nodes[y][x] = newNode;
    }
    int getSize(){
        return size;
    }
};
#endif // MATRIXV2_H
