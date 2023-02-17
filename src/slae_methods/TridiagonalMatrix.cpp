#include "TridiagonalMatrix.h"
#include "CSR_matrix.h"

TridiagonalMatrix::TridiagonalMatrix(std::vector<double> a, std::vector<double> b, std::vector<double> c){
    matrix = std::vector<element>(b.size());

    for (int i = 0; i < a.size(); ++i){
        matrix[i+1].a  = a[i];
    }
    for (int i = 0; i < b.size(); ++i){
        matrix[i].b  = b[i];
    }
    for (int i = 0; i < c.size(); ++i){
        matrix[i].c  = c[i];
    }
}

element TridiagonalMatrix::operator() (int i) const{
    return this->matrix[i];
}

void TridiagonalMatrix::print() {
    for(int i = 1; i < this->get_size(); i++){
        std::cout << matrix[i].a << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < this->get_size(); i++){
        std::cout << matrix[i].b << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < this->get_size() - 1; i++){
        std::cout << matrix[i].c << " ";
    }
    std::cout << std::endl;
}


