#ifndef SLAE_CSR_MATRIX
#define SLAE_CSR_MATRIX


#include <vector>


class CSR{
	const int c_num;
	const int r_num;
	std::vector<double> values;
	std::vector<int> cols;
	std::vector<int> rows;
public:
	CSR(std::vector<double>const &matrix, const int cols, const int rows);

	double operator()(int i, int j) const;

	std::vector<double> operator*(std::vector<double> vec) const;

	const int getColumns() const;

	const int getRows() const;

};

#endif
