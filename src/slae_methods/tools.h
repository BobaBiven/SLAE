#ifndef SLAE_TOOLS
#define SLAE_TOOLS

#include <vector>
#include <math.h>

double find_module(std::vector<double>const& v);


std::vector<double>operator- (std::vector<double>const& a, std::vector<double>const& b);

std::vector<double>operator+ (std::vector<double>const& a, std::vector<double>const& b);

double DotProduct(std::vector<double> const& a, std::vector<double> const& b);

std::vector<double> operator* (std::vector<double>const& a, const double x);

std::vector<double> operator*(const double x, std::vector<double>const& a);

#endif
