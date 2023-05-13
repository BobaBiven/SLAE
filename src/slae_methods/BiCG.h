#ifndef SLAE_BCG
#define SLAE_BCG

#include "CSR_matrix.h"
#include "tools.h"

std::vector<double> BCG(CSR const& A, std::vector<double> const& b, std::vector<double> const& x_0, double tol);



#endif
