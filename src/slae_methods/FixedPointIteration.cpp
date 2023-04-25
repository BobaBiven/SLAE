#include "FixedPointIteration.h"
#include "tools.h"
//#include <fstream>
//#include <iostream>

std::vector<double> FixedPointIteration(CSR const& A, std::vector<double> const& b, const double tol, std::vector<double>const& x_0, const double tau){

    std::vector<double> x = x_0;
    std::vector<double> r = A * x - b;


    while (find_module(r) > tol){
        x = x - tau * (A * x - b);
        r = A * x - b;
    }
    return x;
}


std::vector<double> FastFIP(CSR const& A, std::vector<double> const& b, std::vector<double>const& x_0, const double tol, const double l_min, const double l_max, unsigned int n){

    std::vector<double> x = x_0;
    std::vector<double> r = A * x - b;
    std::vector<double> roots = ChebyshevRoots(n, l_min, l_max);

    //std::ofstream out;
    //out.open("./r.txt"); //

    while (find_module(r) > tol){
        //out << find_module(r) << std::endl;
        for (size_t i = 0; i < roots.size(); ++i){
            x = x - 1 / roots[i] * r;
            //std::cout << roots[i] << " ";
            r = A * x - b;
        }
    }

    return x;

}


std::vector<double>ChebyshevRoots(const int n, const double l_min, const double l_max){
    std::vector<double>roots(n);
    double c_cos = std::cos(M_PI/n);
    double c_sin = std::sin(M_PI/n);

    double si = std::sin(M_PI / (2 * n));
    roots[0] = std::cos(M_PI / (2 * n));

    for (int i = 1; i < n; ++i) {
        roots[i] = roots[i-1] * c_cos  - si * c_sin;
        si = roots[i-1] * c_sin + si * c_cos;
    }

    for (int i = 1; i < n; ++i) {
        roots[i-1] = 0.5 * (l_max + l_min + roots[i-1] * (l_max - l_min));
    }

    return roots;
}
