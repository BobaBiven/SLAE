#include "ConjugateGradient.h"
#include "tools.h"

std::vector<double> conjGrad(CSR const& A, std::vector<double>const& b, std::vector<double> const& x_0, double tol) {
    std::vector<double> x = x_0;
    std::vector<double> r = A * x - b;
    std::vector<double>d = r;
    double aa, bb;

    while (find_module(r) > tol){
        bb = DotProduct(d, r);
        aa = bb / DotProduct(d, (A * d));
        x = x - aa * d;

        d = DotProduct(r, r) / bb * d + r;

        r = A * x - b;
    }
    return x;
}
