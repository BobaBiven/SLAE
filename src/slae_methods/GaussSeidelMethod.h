#ifndef SLAE_GAUSSSEIDELMETHOD
#define SLAE_GAUSSSEIDELMETHOD

#include "CSR_matrix.h"
#include "tools.h"

std::vector<double>GaussSeidelMethod(CSR const& A,std::vector<double>const& b,  double tol, std::vector<double>const& x_0);




#endif
