#ifndef SLAE_TRIDIAGONALMATRIX_H
#define SLAE_TRIDIAGONALMATRIX_H

#include <vector>
#include <iostream>
#include <array>

struct element{
        double a, b, c;
    };

class TridiagonalMatrix {
private:


    std::vector<element> matrix;

public:



    TridiagonalMatrix(std::vector<double> a, std::vector<double> b, std::vector<double> c);

    int get_size()const{return matrix.size();}

    element operator() (int i) const;

    void print();


};




#endif //SLAE_TRIDIAGONALMATRIX_H
