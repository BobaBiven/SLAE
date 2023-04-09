#include "GaussSeidelMethod.h"

std::vector<double>GaussSeidelMethod(CSR const& A, std::vector<double>const& b, double tol, std::vector<double>const& x_0){

    std::vector<double>x = x_0;

    //std::vector<double>x_n (x_0.size());

    std::vector<double>r = A * x - b;

    //std::vector<double>D (x_0.size());

    std::vector<int>cols = A.get_cols();
    std::vector<int>rows = A.get_rows();

    // for (size_t i = 0; i < D.size(); ++i){
    //     D[i] = 1 / A(i, i);
    // }

    while(find_module(r) > tol){


        // for (size_t i = 0; i < x.size(); ++i){
        //     double s = 0;
        //     for (size_t j = 0; j < i - 1; ++j){
        //         s+= A(i, j) * x_n[j];
        //     }
        //     for (size_t j = i + 1; j < x.size(); ++j){
        //         s+= A(i, j) * x[j];
        //     }
        //     x_n[i] = D[i] * (b[i] - s);
        // }
        // x = x_n;
        // r = A * x_n - b;


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
            x[i - 1] = d * (b[i-1] - s);
        }

    }
    return x;
}
