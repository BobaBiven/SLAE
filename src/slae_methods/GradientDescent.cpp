#include "GradientDescent.h"

std::vector<double> grad_desc(std::vector<double>const& b, CSR const& A, double tol, std::vector<double>const& x_0){

    std::vector<double> x = x_0;
    std::vector<double> r = A * x - b;
    double a;

    while (find_module(r) > tol){
        a = DotProduct(r, r) / DotProduct(r, A * r);
        x = x - a * r;
        r = A * x - b;
    }
    return x;
}

