#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;
typedef vector<vector<long long>> Matrix;

// Toan tu nhan ma tran tren truong huu han (mod 10^9+7)
Matrix multiply(Matrix A, Matrix B) {
    Matrix C(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 2; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                // Dam bao so du luon duong
                if (C[i][j] < 0) C[i][j] += MOD; 
            }
        }
    }
    return C;
}

// Thuat toan luy thua nhi phan O(log N)
Matrix power(Matrix A, long long p) {
    Matrix res = {{1, 0}, {0, 1}}; // Ma tran don vi I
    while (p > 0) {
        if (p % 2 == 1) res = multiply(res, A);
        A = multiply(A, A);
        p /= 2;
    }
    return res;
}


int main() {
    long long n = 10;
    Matrix T = {{1, 1}, {1, 0}}; // Fibonacci recurrence matrix
    Matrix Tn = power(T, n - 1);
    long long u_n = Tn[0][0]; // Assuming base cases u_1 = 1, u_0 = 0
    cout << "u_" << n << " = " << u_n << endl;
    return 0;
}
