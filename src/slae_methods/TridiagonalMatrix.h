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



    TridiagonalMatrix(std::vector<double>const& a, std::vector<double>const& b, std::vector<double>const& c);

    int get_size()const{return matrix.size();}

    element const& operator() (int i) const;

    void print();


};




#endif //SLAE_TRIDIAGONALMATRIX_H
