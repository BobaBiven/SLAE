#include "gtest/gtest.h"
#include "../src/slae_methods/CSR_matrix.h"

TEST(csr_test, test){
    std::vector<double> matrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    CSR A(3, 3, matrix);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            EXPECT_TRUE(matrix[i * 3 + j] - A(i, j) == 0);
        }
    }
}
