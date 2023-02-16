#include "TridiagonalMatrixAlgorithm.h"


std::vector<double>solution(TridiagonalMatrix const &A,  std::vector<double> d){
    std::vector<double>x(A.get_size());
    std::vector<double>p(A.get_size());
    std::vector<double>q(A.get_size());

    p[1] = - A.matrix[0].c / A.matrix[0].b;
    q[1] = d[0] / A.matrix[0].b;

    for (int i = 2; i < A.get_size(); i++){
        p[i] = - A.matrix[i-1].c / (A.matrix[i-1].a * p[i-1] + A.matrix[i-1].b);
        q[i] = (d[i-1] - A.matrix[i-1].a * q[i-1]) / (A.matrix[i-1].a * p[i-1] + A.matrix[i-1].b);
    }

    x[A.get_size() - 1] = (d[A.get_size() - 1] - A.matrix[A.get_size() - 1].a * q[A.get_size() - 1]) / (A.matrix[A.get_size() - 1].a * p[A.get_size() - 1] + A.matrix[A.get_size() - 1].b);

    for (int i = A.get_size() - 2; i >= 0; i--){
        x[i] = p[i+1] * x[i+1] + q[i+1];
    }
    return x;

}