#ifndef SLAE_GAUSSSEIDELMETHOD
#define SLAE_GAUSSSEIDELMETHOD

#include "CSR_matrix.h"
#include "FixedPointIteration.h"

std::vector<double>GaussSeidelMethod(std::vector<double>const& b, CSR const& A, double tol, std::vector<double> x_0);




#endif
