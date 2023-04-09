#include "src/slae_methods/FixedPointIteration.h"
#include "src/slae_methods/GradientDescent.h"
#include "src/slae_methods/GaussSeidelMethod.h"
#include "src/slae_methods/CSR_matrix.h"
#include "src/slae_methods/ConjugateGradient.h"
#include "src/slae_methods/tools.h"
#include <iostream>
#include <fstream>

int main(){

//     // задание 1
//     std::vector<double>matrix(289 * 289);
//
//     for (int i = 0; i < 289; ++i){
//         matrix[i * 289 + i] = 36;
//         if (i < 288){
//             matrix[i * 289 + i + 1] = 7;
//         }
//         if (i < 289 - 17){
//             matrix[i * 289 + i + 17] = 7;
//         }
//         if (i > 0){
//             matrix[i * 289 + i - 1] = 7;
//         }
//         if (i > 16){
//             matrix[i * 289 + i - 17] = 7;
//         }
//     }
//
//
//     CSR m(matrix, 289, 289);
//
//
//     std::vector<double> b(289), x_0(289), x1;
//
//     for (int i = 0; i < 289; ++i){
//         b[i] = 3;
//     }
//
//     // //lambda_max = 63.57462, lambda_min = 8.42538;
//     //x1 = FixedPointIteration(m, b, 1.0 / 63.57462, x_0, 1e-13); // пункт 1
//     //x1 = FixedPointIteration(m, b, 2.0 / (63.57462 + 8.42538), x_0, 1e-13); // пункт 2
//     //x1 = FastFIP(m, b, x_0, 1e-13, 8.42538, 63.57462, 3); // пункт 3
//     //x1 = SOR(m, b, 1e-13, x_0, ); // п4 (доделать)
//
//
//
//     std::ofstream out;
//     out.open("../kr2/task1.txt");
//
//     for (int i = 0; i < 289; i++){
//         out << x1[i] << std::endl;
//     }
//
//     out.close();
//
//
    //задание 2
    std::vector<double>m = {3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4.5}, b = {5, 5, 5, 5}, c = {4, 4, 4, 4}, x_0(4), x1, x2, x3, x4, x5;
    CSR A(m, 4, 4);
    x1 = FixedPointIteration(A, b, 2.0 * 0.9 / 4.5, x_0, 1e-13); //пункт 1
    x2 = FixedPointIteration(A, b, 2.0 / (4.5 + 3), x_0, 1e-13); //пункт 2
    x3 = grad_desc(A, b, 1e-13, x_0); //пункт 3
    //x4 = FastFIP(A, b, x_0, 1e-13, 3, 4.5, 3); //пункт 4
    x5 = conjGrad(A, b, x_0, 1e-13);
        std::ofstream out;
    out.open("../kr2/task2.txt");

    for (int i = 0; i < 4; i++){
            out << c[i] + b[i] * x1[i] + x1[i] * x1[i] * A(i, i) << " ";
    }
    out << std::endl;

    for (int i = 0; i < 4; i++){
            out << c[i] + b[i] * x2[i] + x2[i] * x2[i] * A(i, i) << " ";
    }
    out << std::endl;


    for (int i = 0; i < 4; i++){
            out << c[i] + b[i] * x3[i] + x3[i] * x3[i] * A(i, i) << " ";
    }
    out << std::endl;


    // for (int i = 0; i < 4; i++){
    //         out << c[i] + b[i] * x1[i] + x1[i] * x1[i] * A(i, i) << " ";
    // }
    // out << std::endl;

    out << "FastFIP cring" << std::endl;

    for (int i = 0; i < 4; i++){
            out << c[i] + b[i] * x5[i] + x5[i] * x5[i] * A(i, i) << " ";
    }
    out << std::endl;


    out.close();

    return 0;
}
