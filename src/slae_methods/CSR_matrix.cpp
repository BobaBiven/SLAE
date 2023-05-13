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

CSR::CSR(std::vector<double> els, const std::vector<int>& c, const std::vector<int>& r, const int &h, const int &w) : r_num(h), c_num(w) {
	values = els;
	rows = r;
	cols = c;
};

double CSR::operator()(int i, int j) const{
	for (int k = rows[i]; k < rows[i+1]; ++k){
		if (cols[k] == j){
			return values[k];
		}
	}
	return 0;
}

std::vector<int>const& CSR::get_cols()const{
		return cols;
}

std::vector<int>const& CSR::get_rows()const{
		return rows;
}
// const int CSR::getColumns() const{
// 		return c_num;
// }
//
// const int CSR::getRows() const{
// 		return r_num;
// }

std::vector<double> CSR::operator*(std::vector<double>const& vec) const{
	std::vector<double>res(r_num);
	for (int i = 0; i < r_num; ++i){
		for (int j = rows[i]; j < rows[i+1]; ++j){
			res[i] += values[j] * vec[cols[j]];
		}
	}
	return res;
}

std::vector<double>CSR::get_values() const{
	return values;
}

CSR CSR::transpose() const {
	int Nonzero = values.size();
	std::vector<double> tmatrix_els(Nonzero);
	std::vector<int> tCols(Nonzero);
	std::vector<int> tRows(c_num + 1);
	for (int i = 0; i < Nonzero; ++i) tRows[cols[i] + 1]++;
	int S = 0;
	int tmp;
	for (int i = 1; i <= c_num; ++i) {
		tmp = tRows[i];
		tRows[i] = S;
		S += tmp;
	}
	int j1, j2, Col, RIndex, IIndex;
	double V;
	for (int i = 0; i < r_num; ++i) {
		j1 = rows[i];
		j2 = rows[i+1];
		Col = i;
		for (int j = j1; j < j2; ++j) {
			V = values[j];
			RIndex = cols[j];
			IIndex = tRows[RIndex + 1];
			tmatrix_els[IIndex] = V;
			tCols[IIndex] = Col;
			tRows[RIndex + 1]++;
		}
	}
	return CSR(tmatrix_els, tCols, tRows, r_num, c_num);
}


