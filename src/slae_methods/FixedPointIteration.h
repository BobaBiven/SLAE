#ifndef SLAE_FIXEDPOINTITERATION
#define SLAE_FIXEDPOINTITERATION

#include "CSR_matrix.h"
#include "tools.h"

std::vector<double> FixedPointIteration(CSR const& A, std::vector<double> const& b, double tau, std::vector<double>const& x_0, double tol);



#endif
