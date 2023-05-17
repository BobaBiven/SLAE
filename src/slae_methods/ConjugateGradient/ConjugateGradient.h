#ifndef SLAE_CONJUGATEGRADIENT
#define SLAE_CONJUGATEGRADIENT

#include "../CSR_matrix.h"
#include "../tools.h"

std::vector<double> conjGrad(CSR const& A, std::vector<double>const& b, std::vector<double> const& x_0, double tol);

#endif
