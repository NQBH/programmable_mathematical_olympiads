#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;
typedef vector<vector<long long>> Matrix;

// Matrix multiplication operator over the finite field F_p (mod 10^9+7)
Matrix multiply(Matrix A, Matrix B) {
    Matrix C(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 2; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                // Enforce strictly positive modular equivalence
                if (C[i][j] < 0)
                    C[i][j] += MOD;
            }
        }
    }
    return C;
}

// Binary matrix exponentiation algorithm achieving O(log n)
Matrix power(Matrix A, long long p) {
    Matrix res = {{1, 0}, {0, 1}}; // Ma tran don vi I
    while (p > 0) {
        if (p % 2 == 1)
            res = multiply(res, A);
        A = multiply(A, A);
        p /= 2;
    }
    return res;
}
