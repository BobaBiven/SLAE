#include "FixedPointIteration.h"
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

    while (find_module(r) > tol){
        for (size_t i = 0; i < roots.size(); ++i){
            x = x - 1 / roots[i] * r;
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

    std::vector<int> order(n);
    order[0] = 1;
    for (int i = 1; i < n; i = i * 2){
        for(int j = 0; j < i; ++j){
            order[n * (j * 2 + 1) / (2 * i)] = 2 * i  + 1 - order[n * 2 * j / (2 * i)];
        }
    }

    for (int i = 0; i < n; ++i) {
        roots[i] = 2 / ((l_max + l_min) + (l_max - l_min) * roots[order[i] - 1]);
    }

    return roots;
}



