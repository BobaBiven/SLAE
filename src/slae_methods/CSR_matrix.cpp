#include "CSR_matrix.h"

CSR::CSR(std::vector<double>const& matrix, const int n, const int m): c_num(n), r_num(m){
	unsigned int k = 0;
	this->rows.push_back(k);
	for (int j = 0; j < n; ++j){
		for (int i = 0; i < m; ++i){
			if (matrix[i + j * n] != 0){
				values.push_back(matrix[i + j * m]);
				cols.push_back(i);
				++k;
			}
		}
		rows.push_back(k);
	}
}

double CSR::operator()(int i, int j) const{
	for (int k = rows[i]; k < rows[i+1]; ++k){
		if (cols[k] == j){
			return values[k];
		}
	}
	return 0;
}

const int CSR::getColumns() const{
		return c_num;
	}

const int CSR::getRows() const{
		return r_num;
	}

std::vector<double> CSR::operator*(std::vector<double>const& vec) const{
	std::vector<double>res(r_num);
	for (int i = 0; i < r_num; ++i){
		for (int j = rows[i]; j < rows[i+1]; ++j){
			res[i] += values[j] * vec[cols[j]];
		}
	}
	return res;
}



