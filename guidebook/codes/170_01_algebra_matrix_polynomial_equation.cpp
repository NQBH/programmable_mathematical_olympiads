#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: Matrix Polynomial Equation P(A, B) = sum a_i A^i + B = 0_n
 * Target: B = g(A) => [A, B] = 0_n and Spec(B) = g(Spec(A))
 */

using Matrix = std::vector<std::vector<double>>;

Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

Matrix scale(const Matrix& A, double s) {
    int n = A.size();
    Matrix C(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] * s;
        }
    }
    return C;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Matrix A (3x3):
    Matrix A = {
        {1.0, 2.0, 0.0},
        {0.0, 2.0, 1.0},
        {0.0, 0.0, 3.0}
    };
    int n = 3;

    // Polynomial g(x) = 2*x^2 - 3*x + 4
    // B = -g(A) = -2*A^2 + 3*A - 4*I_3
    Matrix I(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) I[i][i] = 1.0;

    Matrix A2 = multiply(A, A);
    Matrix gA = add(scale(A2, 2.0), add(scale(A, -3.0), scale(I, 4.0)));
    Matrix B = scale(gA, -1.0);

    // 1. Verify that P(A, B) = 2*A^2 - 3*A + 4*I + B == 0
    Matrix P_eval = add(gA, B);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            assert(std::abs(P_eval[i][j]) < 1e-12);
        }
    }

    // 2. Verify commutativity [A, B] = A*B - B*A == 0
    Matrix AB = multiply(A, B);
    Matrix BA = multiply(B, A);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            assert(std::abs(AB[i][j] - BA[i][j]) < 1e-12);
        }
    }

    // 3. Spectral mapping: Eigenvalues of A are 1, 2, 3 (upper triangular)
    // Eigenvalues of B are -g(1), -g(2), -g(3)
    // g(1) = 2 - 3 + 4 = 3 => lambda_B1 = -3
    // g(2) = 8 - 6 + 4 = 6 => lambda_B2 = -6
    // g(3) = 18 - 9 + 4 = 13 => lambda_B3 = -13
    assert(std::abs(B[0][0] - (-3.0)) < 1e-12);
    assert(std::abs(B[1][1] - (-6.0)) < 1e-12);
    assert(std::abs(B[2][2] - (-13.0)) < 1e-12);

    std::cout << "Verification successful: P(A, B) = 0 solved; [A, B] = 0 and spectral mapping confirmed.\n";
    return 0;
}
