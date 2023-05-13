#include "GaussSeidelMethod.h"
#include <iostream>


std::vector<double>GaussSeidelMethod(CSR const& A, std::vector<double>const& b, double tol, std::vector<double>const& x_0){

    std::vector<double>x = x_0;
    std::vector<double>r = A * x - b;
    std::vector<int>cols = A.get_cols();
    std::vector<int>rows = A.get_rows();
    std::vector<double>vals = A.get_values();

    while(find_module(r) > tol){

        for (size_t i = 0; i < x.size(); ++i){
            double d;
            x[i] = b[i];
            for(int j = rows[i]; j < rows[i+1]; ++j){
                if(static_cast<int>(i) == cols[j]){
                    d =  A(i, cols[j]);
                    continue;
                }
                x[i] = x[i] - vals[j] * x[cols[j]];
            }
            x[i] = x[i] / d;

        }
        r = A * x - b;
    }

    return x;

}

