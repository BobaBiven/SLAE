#ifndef SLAE_TOOLS
#define SLAE_TOOLS

#include <vector>
#include <math.h>

double find_module(std::vector<double> v);


std::vector<double>operator- (std::vector<double>const& a, std::vector<double>const& b);

std::vector<double>operator+ (std::vector<double>const& a, std::vector<double>const& b);


std::vector<double> operator* (std::vector<double> v, double x);

double DotProduct(std::vector<double> const& a, std::vector<double> const& b);


std::vector<double> operator*(double number, std::vector<double> const& a);

#endif
