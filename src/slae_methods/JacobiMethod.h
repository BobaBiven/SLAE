#ifndef SLAE_JACOBIMETHOD
#define SLAE_JACOBIMETHOD

#include "FixedPointIteration.h"
#include "CSR_matrix.h"
#include <vector>


std::vector<double>JacobiMethod(std::vector<double>const& b, CSR const& A, double tol, std::vector<double> x_0);


#endif
