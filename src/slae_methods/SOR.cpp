#include "SOR.h"
#include "tools.h"

std::vector<double> SOR(CSR const& A, std::vector<double>const& b, std::vector<double>const& x_0,  double tol, double w){

    std::vector<double>x = x_0;
    std::vector<double>r = A * x - b;
    std::vector<int>cols = A.get_cols();
    std::vector<int>rows = A.get_rows();

    while(find_module(r) > tol){

        for (size_t i = 0; i < rows.size(); ++i){
            double s = 0, d;
            int tmp = i;
            for(int j = rows[i-1]; j < rows[i]; ++i){
                if(tmp-1 != cols[j]){
                    s += x[cols[j]] * A.get_values()[j];
                }
                else{
                    d = 1 / A.get_values()[j];
                }
            }
            x[i-1] = d * (w * b[i-1] - w * s + (1 - w) * d * x[i-1]);
        }

    }
    return x;
}

