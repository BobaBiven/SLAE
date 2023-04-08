#ifndef SLAE_JACOBIMETHOD
#define SLAE_JACOBIMETHOD

#include "tools.h"
#include "CSR_matrix.h"


std::vector<double>JacobiMethod(std::vector<double>const& b, CSR const& A, double tol, std::vector<double> x_0);


#endif
