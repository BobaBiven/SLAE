#ifndef SLAE_FIXEDPOINTITERATION
#define SLAE_FIXEDPOINTITERATION

#include "CSR_matrix.h"
#include "tools.h"

std::vector<double> FixedPointIteration(CSR const& A, std::vector<double> const& b, const double tau, std::vector<double>const& x_0, const double tol);

std::vector<double> FastFIP(CSR const& A, std::vector<double> const& b, std::vector<double>const& x_0, const double tol, const double l_min, const double l_max, unsigned int n);

std::vector<double>ChebyshevRoots(const int n, const double l_min, const double l_max);



#endif
