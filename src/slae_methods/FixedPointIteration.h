#ifndef SLAE_FIXEDPOINTITERATION
#define SLAE_FIXEDPOINTITERATION

#include "CSR_matrix.h"
#include <math.h>

std::vector<double> FixedPointIteration(CSR const& A, std::vector<double> const& b, double tau, std::vector<double>const& x_0, double tol);

std::vector<double>operator- (std::vector<double>const& a, std::vector<double>const& b);

std::vector<double> operator* (std::vector<double> v, double x);

double find_module(std::vector<double> v);


#endif
