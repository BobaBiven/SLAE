#include "FixedPointIteration.h"

std::vector<double> FixedPointIteration(CSR const& A, std::vector<double> const& b, double tau, std::vector<double>const& x_0, double tol){
    std::vector<double>x(x_0.size());
    x = x_0 - (A * x_0 - b) * tau;
    while (find_module(b - A * x) >= tol){
        x = x - (A * x - b) * tau;
    }
    return x;
}


std::vector<double>operator- (std::vector<double>const& a, std::vector<double>const& b){
    std::vector<double> res(a.size());
    for (unsigned int i = 0; i < a.size(); ++i){
        res[i] = a[i] - b[i];
    }
    return res;
}

std::vector<double> operator* (std::vector<double> v, double x) {
    for (unsigned int i = 0; i < v.size(); ++i){
        v[i] = v[i] * x;
    }
    return v;
}

double find_module(std::vector<double> v){
    long double sum = 0;
    for (unsigned int i = 0; i < v.size(); ++i){
        sum += v[i] * v[i];
    }
    return sqrt(sum);
}

