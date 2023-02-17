#include "CSR_matrix.h"

CSR::CSR(std::vector<double> val, std::vector<int> col, std::vector<int> row): c_num(col.size()), r_num(row.size()){
		values = val;
		cols = col;
		rows = row;

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



