#include "tools.h"

double find_module(std::vector<double>const& v){
    long double sum = 0;
    for (size_t i = 0; i < v.size(); ++i){
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


double DotProduct(std::vector<double> const& a, std::vector<double> const& b){
    double s = 0;
    for (size_t i = 0; i < a.size(); ++i){
        s += a[i] * b[i];
    }
    return s;
}


std::vector<double> operator* (std::vector<double>const& a, const double x) {
    std::vector<double> v(a.size());
    for (size_t i = 0; i < v.size(); ++i){
        v[i] = a[i] * x;
    }
    return v;
}


std::vector<double> operator*(const double x, std::vector<double>const& a) {
    return a * x;
}
