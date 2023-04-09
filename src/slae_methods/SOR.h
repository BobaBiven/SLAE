#ifndef SLAE_SOR
#define SLAE_SOR

#include "CSR_matrix.h"
#include "tools.h"

std::vector<double> SOR(CSR const& A, std::vector<double> const& b, double tol, double w);


#endif
