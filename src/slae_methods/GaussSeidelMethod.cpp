#include "GaussSeidelMethod.h"


std::vector<double>GaussSeidelMethod(std::vector<double>const& b, CSR const& A, double tol, std::vector<double>const& x_0){

    std::vector<double>x = x_0;
    std::vector<double>x_1(x_0.size());
    std::vector<double>D(x_0.size());

    for (size_t i = 0; i < D.size(); ++i){
        D[i] = 1 / A(i, i);
    }

    while(find_module(b - A * x_1) >= tol){
        for (size_t i = 0; i < x.size(); ++i){
            double s = 0;
            for (size_t j = 0; j < i; ++j){
                s+= A(i, j) * x_1[j];
            }
            for (size_t j = i + 1; j < x.size(); ++j){
                s+= A(i, j) * x[j];
            }
            x_1[i] = D[i] * (b[i] - s);
        }
    }
    return x_1;
}
