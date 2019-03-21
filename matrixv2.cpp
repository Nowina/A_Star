#include <matrixv2.h>

MatrixV2::MatrixV2(int x, int y) {
    width = x;
    height = y;
    size = x*y;
    nodes = new GraphNode**[y];
    for (int i = 0; i < y; ++i) {
        nodes[i] = new GraphNode*[x];
    }
}
MatrixV2::~MatrixV2(){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j< width; j++) {
            delete nodes[i][j];
        }
        delete nodes[i];
    }
    delete [] nodes;
}
GraphNode* MatrixV2::at(int x, int y){
    return nodes[y][x];
}
void MatrixV2::write(int x, int y, GraphNode* newNode){
    nodes[y][x] = newNode;
}
int MatrixV2::getSize(){
    return size;
}
