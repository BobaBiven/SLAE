#ifndef SLAE_TRIDIAGONALMATRIX_H
#define SLAE_TRIDIAGONALMATRIX_H

#include <vector>
#include <iostream>
#include <array>

class TridiagonalMatrix {
private:
    struct element{
        double a, b, c;
    };

public:

    std::vector<element> matrix;

    TridiagonalMatrix(std::vector<double> a, std::vector<double> b, std::vector<double> c);

    int get_size()const{return matrix.size();}

    void print();


};




#endif //SLAE_TRIDIAGONALMATRIX_H
