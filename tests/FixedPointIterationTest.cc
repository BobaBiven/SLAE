#include "gtest/gtest.h"
#include "../src/slae_methods/FPI/FixedPointIteration.h"
#include <iostream>

TEST(FIPtest, test1){
    std::vector<double> matrix = {1, 2, 3, 0, 5, 1, 2, 2, 8}, x_0(3), b = {12, 6, 12}, x;
    CSR m(matrix, 3, 3);
    x = FixedPointIteration(m, b, 1e-13, x_0, 0.2);
    ASSERT_TRUE(x[0] - 20.0 < 0.1);
    ASSERT_TRUE(x[1] - 2.0 < 0.1);
    ASSERT_TRUE(x[2] + 4.0 < 0.1);

}
