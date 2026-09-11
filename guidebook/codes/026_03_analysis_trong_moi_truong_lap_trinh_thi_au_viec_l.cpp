#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
typedef vector<vector<ll>> Matrix;

// O(m^3) matrix multiplication
Matrix multiply(Matrix A, Matrix B, int m) {
    Matrix C(m, vector<ll>(m, 0));
    for (int i = 0; i < m; i++)
        for (int k = 0; k < m; k++)
            for (int j = 0; j < m; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// O(m^3 log n) binary exponentiation
Matrix power(Matrix A, ll n, int m) {
    Matrix res(m, vector<ll>(m, 0));
    for (int i = 0; i < m; i++)
        res[i][i] = 1; // Identity matrix
    while (n > 0) {
        if (n % 2 == 1)
            res = multiply(res, A, m);
        A = multiply(A, A, m);
        n /= 2;
    }
    return res;
}
