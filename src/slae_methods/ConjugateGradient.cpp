#include "ConjugateGradient.h"
#include "tools.h"

std::vector<double> conjGrad(CSR const& A, std::vector<double>const& b, std::vector<double> const& x_0, double tol) {
    std::vector<double> x = x_0;
    std::vector<double> r = A * x - b;
    std::vector<double>d = r;
    double aa, bb;

    while (find_module(r) > tol){
        auto prev = DotProduct(d, r);
        aa = prev / DotProduct(d, (A * d));
        x = x - aa * d;
        r = A * x - b;
        d = DotProduct(r, r) / prev * d + r;
    }
    return x;
}
