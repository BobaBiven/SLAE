#ifndef SLAE_GAUSSSEIDELMETHOD
#define SLAE_GAUSSSEIDELMETHOD

#include "CSR_matrix.h"
#include "tools.h"

std::vector<double>GaussSeidelMethod(CSR const& A,std::vector<double>const& b,  double tol, std::vector<double>const& x_0);

std::vector<double>Iteration(CSR const& A, std::vector<double> b, std::vector<double>const& x_0);

std::vector<double>DownIteration(CSR const& A, std::vector<double> b, std::vector<double>const& x_0);

std::vector<double>SymmetrizedGaussSeidel(CSR const& A, std::vector<double> b, std::vector<double>const& x_0, double tol);

#endif
