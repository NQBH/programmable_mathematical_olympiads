#include <iostream>
#include <vector>
#include <cassert>

using Matrix2x2 = std::vector<std::vector<double>>;

Matrix2x2 mat_mul(const Matrix2x2& A, const Matrix2x2& B) {
    Matrix2x2 C = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; ++i)
        for (int k = 0; k < 2; ++k)
            for (int j = 0; j < 2; ++j)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

Matrix2x2 mat_sub(const Matrix2x2& A, const Matrix2x2& B) {
    return {
        {A[0][0] - B[0][0], A[0][1] - B[0][1]},
        {A[1][0] - B[1][0], A[1][1] - B[1][1]}
    };
}

Matrix2x2 mat_scale(const Matrix2x2& A, double s) {
    return {
        {A[0][0] * s, A[0][1] * s},
        {A[1][0] * s, A[1][1] * s}
    };
}

int main() {
    // Ma tran M trong phuong trinh: X^3 - 3X^2 + M = 0_2
    Matrix2x2 M = {{2.0, 2.0}, {2.0, 2.0}};

    // 4 nghiem ma tran tim duoc qua ly thuyet pho
    std::vector<Matrix2x2> roots = {
        {{-0.5, -0.5}, {-0.5, -0.5}}, // X_1 = -1/4 M
        {{1.0, 1.0}, {1.0, 1.0}},     // X_2 = 1/2 M
        {{1.0, -2.0}, {-2.0, 1.0}},   // X_3 = 3I - M
        {{2.5, -0.5}, {-0.5, 2.5}}    // X_4 = 3I - 1/4 M
    };

    std::cout << "Kiem chung 4 nghiem thuc cua phuong trinh X^3 - 3X^2 + M = 0_2:\n";
    for (size_t i = 0; i < roots.size(); ++i) {
        Matrix2x2 X = roots[i];
        Matrix2x2 X2 = mat_mul(X, X);
        Matrix2x2 X3 = mat_mul(X2, X);
        
        // F(X) = X^3 - 3X^2 + M
        Matrix2x2 term2 = mat_scale(X2, 3.0);
        Matrix2x2 diff = mat_sub(X3, term2);
        Matrix2x2 res = {
            {diff[0][0] + M[0][0], diff[0][1] + M[0][1]},
            {diff[1][0] + M[1][0], diff[1][1] + M[1][1]}
        };

        std::cout << "Nghiem X_" << i + 1 << ":\n";
        std::cout << "  [" << X[0][0] << ", " << X[0][1] << "]\n";
        std::cout << "  [" << X[1][0] << ", " << X[1][1] << "]\n";
        std::cout << "  Sai so tri tuyet doi F(X): " 
                  << std::abs(res[0][0]) + std::abs(res[0][1]) + std::abs(res[1][0]) + std::abs(res[1][1]) << "\n\n";
    }

    return 0;
}
