#include "JacobiMethod.h"


std::vector<double>JacobiMethod(std::vector<double>const& b, CSR const& A, double tol, std::vector<double> x_0){

    std::vector<double>x = x_0;
    std::vector<double>x_1(x_0.size());
    std::vector<double>r = A * x - b;

    while(find_module(r) >= tol){
        for (size_t i = 0; i < x.size(); ++i){
            double s = 0;
            for (int j = A.get_rows()[i]; j < A.get_rows()[i+1]; ++j) {
                if (static_cast<int>(i) != A.get_cols()[j]) {
                    s += A(i, A.get_cols()[j]) * x[A.get_cols()[j]];
                }
            }
            x_1[i] = ((b[i] - s) / A(i, i));
        }
        x = x_1;
        r = A * x - b;
    }
    return x;
}


