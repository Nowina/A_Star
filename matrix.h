#ifndef MATRIX_H
#define MATRIX_H
template<class T>
class Matrix {
private:
    T *array;
    int width;
    int size;
public:
    Matrix( int w, int h ){
        width = w;
        array = new T[ w * h ];
        size = w*h;
    }
    ~Matrix() { delete[] array; }
    T at( int x, int y ){
        return array[ index( x, y ) ];
    }
    void write(int x, int y, T element){
        array[index(x,y)] = element;
    }
    int getSize(){
        return size;
    }
protected:
    int index( int x, int y ){
        return y + width * x;
    }
};
#endif // MATRIX_H
