#include "FixedPointIteration.h"

std::vector<double> FixedPointIteration(CSR const& A, std::vector<double> const& b, const double tau, std::vector<double>const& x_0, const double tol){

    std::vector<double> x = x_0;
    std::vector<double> r = A * x - b;

    while (find_module(r) > tol){
        x = x - tau * (A * x - b);
        r = A * x - b;
    }
    return x;
}
