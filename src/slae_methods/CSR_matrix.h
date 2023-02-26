#ifndef SLAE_CSR_MATRIX
#define SLAE_CSR_MATRIX


#include <vector>


// What is that for???
// struct element{
// 	double value;
// 	int i;
// 	int j;
//
// 	bool operator<(const element &r) const {
// 		if (this->value < r.value){
// 			return true;
// 		}
// 		else{
// 			return false;
// 		}
// 	}
//
// };


class CSR{
	const int c_num;
	const int r_num;
	std::vector<double> values;
	std::vector<int> cols;
	std::vector<int> rows;
public:
	//3 готовых вектора
	CSR(const int cols, const int rows, std::vector<double>const &matrix);

	double operator()(int i, int j) const;

	std::vector<double> operator*(std::vector<double> vec) const;
};

#endif
