#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: UIT VMC2025 Prob. 1 - Polynomial Operator Spectrum and Fast Exponentiation
 * Matrix A = {{-5, 4, -1}, {-2, 1, 1}, {10, -10, 6}}
 * Eigenvalues: -1, 1, 2. Diagonalizable via T = {{1, 1, 1}, {1, 2, 3}, {0, 2, 5}}
 */

using Matrix3 = std::vector<std::vector<long long>>;

Matrix3 multiply(const Matrix3& A, const Matrix3& B, long long mod) {
    Matrix3 C(3, std::vector<long long>(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int k = 0; k < 3; ++k) {
            for (int j = 0; j < 3; ++j) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

Matrix3 power_matrix(Matrix3 A, long long exp, long long mod) {
    Matrix3 res = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    while (exp > 0) {
        if (exp % 2 == 1) res = multiply(res, A, mod);
        A = multiply(A, A, mod);
        exp /= 2;
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Matrix3 A = {
        {-5, 4, -1},
        {-2, 1, 1},
        {10, -10, 6}
    };

    // Verify characteristic polynomial roots: lambda = -1, 1, 2
    // p_A(t) = t^3 - 2*t^2 - t + 2
    for (long long lambda : {-1, 1, 2}) {
        long long poly_val = lambda * lambda * lambda - 2 * lambda * lambda - lambda + 2;
        assert(poly_val == 0);
    }

    // Verify eigenvectors: A * v = lambda * v
    std::vector<long long> v1 = {1, 1, 0};  // lambda = -1
    std::vector<long long> v2 = {1, 2, 2};  // lambda = 1
    std::vector<long long> v3 = {1, 3, 5};  // lambda = 2

    // Check A * v1 = -v1
    assert(-5 * 1 + 4 * 1 - 1 * 0 == -1);
    assert(-2 * 1 + 1 * 1 + 1 * 0 == -1);
    assert(10 * 1 - 10 * 1 + 6 * 0 == 0);

    // Coordinate decomposition: p(x) = 3 + 6x + 7x^2 => v = [3, 6, 7]^T
    // v = v1 + v2 + v3: [1+1+1, 1+2+3, 0+2+5]^T = [3, 6, 7]^T
    assert(v1[0] + v2[0] + v3[0] == 3);
    assert(v1[1] + v2[1] + v3[1] == 6);
    assert(v1[2] + v2[2] + v3[2] == 7);

    // Modular check with large prime modulo 10^9 + 7
    long long MOD = 1000000007;
    // Map negative entries of A to positive mod
    Matrix3 A_mod(3, std::vector<long long>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            A_mod[i][j] = (A[i][j] % MOD + MOD) % MOD;
        }
    }

    Matrix3 A_2025 = power_matrix(A_mod, 2025, MOD);
    std::vector<long long> p_vec = {3, 6, 7};
    std::vector<long long> res_num(3, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            res_num[i] = (res_num[i] + A_2025[i][j] * p_vec[j]) % MOD;
        }
    }

    // Theoretical closed form:
    // c0 = 2^2025 mod MOD
    // c1 = (1 + 3 * 2^2025) mod MOD
    // c2 = (2 + 5 * 2^2025) mod MOD
    long long p2_2025 = 1;
    long long base = 2;
    long long exp = 2025;
    while (exp > 0) {
        if (exp % 2 == 1) p2_2025 = (p2_2025 * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }

    long long expected_c0 = p2_2025 % MOD;
    long long expected_c1 = (1 + 3 * p2_2025) % MOD;
    long long expected_c2 = (2 + 5 * p2_2025) % MOD;

    std::cout << "Computed Modular Result (mod 10^9+7):\n";
    std::cout << "  c0 = " << res_num[0] << " (Expected: " << expected_c0 << ")\n";
    std::cout << "  c1 = " << res_num[1] << " (Expected: " << expected_c1 << ")\n";
    std::cout << "  c2 = " << res_num[2] << " (Expected: " << expected_c2 << ")\n";

    assert(res_num[0] == expected_c0);
    assert(res_num[1] == expected_c1);
    assert(res_num[2] == expected_c2);

    std::cout << "Verification successful: Spectral decomposition and binary exponentiation match.\n";
    return 0;
}
