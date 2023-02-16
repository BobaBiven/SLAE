#include "gtest/gtest.h"
#include "../src/slae_methods/TridiagonalMatrixAlgorithm.h"

TEST(TridiagonalMatrixAlgorithm_test, test_1){
    std::vector<double> a = {2, 5}, b = {1, 4, 7}, c = {3, 6}, d = {1, 2, 3}, x = {0, 0.5, 0};
    TridiagonalMatrix M(a, b, c);
    std::vector<double> res = solution(M, d);
    for (int i = 0; i < 3; i++){
        EXPECT_TRUE(res[i] - x[i] == 0);
    }

}


TEST(TridiagonalMatrixAlgorithm_test, test_2){
   std::vector<double> a = {7, 228}, b = {6, 9, 3}, c = {6, 2}, d = {1, 1, 1}, x = {0.424, 0.506, 0.004};
    TridiagonalMatrix M(a, b, c);
    std::vector<double> res = solution(M, d);
    for (int i = 0; i < 3; i++){
        EXPECT_TRUE(res[i] - x[i] <= 0.01);
    }
}
