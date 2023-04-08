#include "FixedPointIteration.h"

std::vector<double> FixedPointIteration(CSR const& A, std::vector<double> const& b, double tau, std::vector<double>const& x_0, double tol){

    std::vector<double>x(x_0.size());
    x = x_0 - tau * (A * x_0 - b);

    while (find_module(b - A * x) >= tol){
        x = x - tau * (A * x - b);
    }
    return x;
}
