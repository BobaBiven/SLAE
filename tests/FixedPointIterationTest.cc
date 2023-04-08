#include "gtest/gtest.h"
#include "../src/slae_methods/FixedPointIteration.h"

TEST(FIPtest, test1){
    std::vector<double> matrix = {10, 1, 1, -3}, x_0, b = {12, 2}, x;
    CSR m(matrix, 2, 2);
    x = FixedPointIteration(m, b, 0.1, x_0, 1e-13);
    ASSERT_TRUE(abs(x[0] - 38.0 / 31) < 0.1);
    ASSERT_TRUE(abs(x[1] + 8.0 / 31) < 0.1);

}
