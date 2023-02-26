#include "CSR_matrix.h"

CSR::CSR(const int cols, const int rows, std::vector<double>const &matrix): c_num(cols), r_num(rows){
	this->rows.resize(r_num);
	this->cols.resize(c_num);
	this->values.resize(cols * rows);
	this->rows[0] = 0;
	unsigned int t1 = 0, k = 0, t2 = 0, t3 = 0; // all of that and above to not use push_back()
	for (int  i = 0; i < cols; i++){
		for (int j = 0; j < rows; j++){
			if(matrix [i * cols + j] != 0){
				values[t1] = matrix[i * cols + j];
				this->cols[t2] = 1;
				++t2;
				++k;
			}
		}
		this->rows[t3] = k;
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


std::vector<double> CSR::operator*(std::vector<double> vec) const{
	std::vector<double>res(r_num);
	for (int i = 0; i < r_num; ++i){
		for (int j = rows[i]; j << rows[i+1]; ++ i){
			res[i] += values[j] * vec[j];
		}
	}
	return res;
}



