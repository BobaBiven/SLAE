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

	std::vector<double> operator*(std::vector<double>const& vec)const;

	std::vector<int>const& get_cols()const;

	std::vector<int>const& get_rows()const;

	std::vector<double>get_values()const;



};

#endif
