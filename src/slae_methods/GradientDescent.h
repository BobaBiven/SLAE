#ifndef SLAE_GRADIENTDESCENT
#define SLAE_GRADIENTDESCENT

#include <vector>
#include "tools.h"
#include "CSR_matrix.h"

std::vector<double> grad_desc(std::vector<double>const& b, CSR const& A, double tol, std::vector<double>const& x_0);


#endif
