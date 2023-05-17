#include "gtest/gtest.h"
#include "../src/slae_methods/GS/GaussSeidelMethod.h"
#include <iostream>

TEST(GSTest, test1){
    std::vector<double> matrix = {1, 2, 3, 0, 5, 1, 2, 2, 8}, x_0(3), b = {12, 6, 12}, x;
    CSR m(matrix, 3, 3);
    x = GaussSeidelMethod(m, b, 1e-13, x_0);
    // std::cout << x[0] << " " << x[1] << " " << x[2];
    ASSERT_TRUE(x[0] - 20.0 < 0.1);
    ASSERT_TRUE(x[1] - 2.0 < 0.1);
    ASSERT_TRUE(x[2] + 4.0 < 0.1);

}

TEST(GSTest, test2){
    std::vector<double> matrix = {10, 1, 1, 2, 10, 1, 2, 2, 10}, x_0(3), b = {12, 13, 14}, x;
    CSR m(matrix, 3, 3);
    x = GaussSeidelMethod(m, b, 1e-13, x_0);
    // std::cout << x[0] << " " << x[1] << " " << x[2];
    ASSERT_TRUE(x[0] - 1.0 < 0.1);
    ASSERT_TRUE(x[1] - 1.0 < 0.1);
    ASSERT_TRUE(x[2] - 1.0 < 0.1);

}
