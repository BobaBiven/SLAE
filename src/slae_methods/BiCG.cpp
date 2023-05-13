#include "BiCG.h"
#include "tools.h"

std::vector<double> BCG(CSR const& A, std::vector<double> const& b, std::vector<double> const& x_0, double tol){
    std::vector<double> x = x_0;
    std::vector<double> r = A * x - b;
    std::vector<double> NAPAS = r, LAVANDOS = r, PACHKA, q;
    double alpha, beta, rho = DotProduct(r, NAPAS), t = DotProduct(r, NAPAS);

    auto trans = A.transpose();

    while (find_module(r) > tol && rho != 0){
        // something to be done here
    }



    return x;
}
