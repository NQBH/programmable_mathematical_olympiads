#include <iostream>
#include <vector>
using namespace std;

// Binary modular exponentiation to compute the finite field inverse
long long powerMod(long long base, long long exp, long long p) {
    long long res = 1;
    base %= p;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % p;
        base = (base * base) % p;
        exp /= 2;
    }
    return res;
}

// Compute modular inverse via Fermat's Little Theorem
long long modInverse(long long n, long long p) { return powerMod(n, p - 2, p); }

// Gaussian determinant computation over F_p bounded at O(n^3)
long long determinantModP(vector<vector<long long>> M, long long p) {
    int n = M.size();
    long long det = 1;
    for (int i = 0; i < n; i++) {
        if (M[i][i] == 0) {
            bool swapped = false;
            for (int j = i + 1; j < n; j++) {
                if (M[j][i] != 0) {
                    swap(M[i], M[j]);
                    det = (p - det) % p; // Doi dau dinh thuc
                    swapped = true;
                    break;
                }
            }
            if (!swapped)
                return 0;
        }
        det = (det * M[i][i]) % p;
        long long inv = modInverse(M[i][i], p);
        for (int j = i + 1; j < n; j++) {
            long long factor = (M[j][i] * inv) % p;
            for (int k = i; k < n; k++) {
                M[j][k] = (M[j][k] - factor * M[i][k]) % p;
                if (M[j][k] < 0)
                    M[j][k] += p;
            }
        }
    }
    return det;
}
