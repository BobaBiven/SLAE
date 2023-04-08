#include "gtest/gtest.h"
#include "../src/slae_methods/CSR_matrix.h"
#include <iostream>

TEST(csr_test, construction_test){
    std::vector<double> matrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    CSR A(matrix, 3, 3);

    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            std::cout << A(i, j) << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            ASSERT_TRUE(matrix[i * 3 + j] - A(i, j) == 0);
        }
    }
}

TEST(csr_test, mulitplication_test){
    std::vector<double> matrix = {1, 2, 3, 4, 5, 6, 7, 8, 9}, b = {21, 22, 1}, x;
    CSR A(matrix, 3, 3);
    x = A * b;
    std::cout << x[0] << " " << x[1] << " " << x[2];
    ASSERT_TRUE(x[0] - 68 == 0);
    ASSERT_TRUE(x[1] - 200 == 0);
    ASSERT_TRUE(x[2] - 332 == 0);

}
