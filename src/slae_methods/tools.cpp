#include "tools.h"

double find_module(std::vector<double> v){
    long double sum = 0;
    for (unsigned int i = 0; i < v.size(); ++i){
        sum += v[i] * v[i];
    }
    return sqrt(sum);
}


std::vector<double>operator- (std::vector<double>const& a, std::vector<double>const& b){
    std::vector<double> res(a.size());
    for (size_t i = 0; i < a.size(); ++i){
        res[i] = a[i] - b[i];
    }
    return res;
}

std::vector<double>operator+ (std::vector<double>const& a, std::vector<double>const& b){
    std::vector<double> res(a.size());
    for (size_t i = 0; i < a.size(); ++i){
        res[i] = a[i] + b[i];
    }
    return res;
}

std::vector<double> operator* (std::vector<double> v, double x) {
    for (unsigned int i = 0; i < v.size(); ++i){
        v[i] = v[i] * x;
    }
    return v;
}

double DotProduct(std::vector<double> const& a, std::vector<double> const& b){
    double s = 0;
    for (size_t i = 0; i < a.size(); ++i){
        s += a[i] * b[i];
    }
    return s;
}


std::vector<double> operator*(double number, std::vector<double> const& a) {
    std::vector<double> sol_vec(a.size());

    for (size_t i = 0; i < a.size(); ++i)
        sol_vec[i] = a[i]*number;
    return sol_vec;
}
