#include <iostream>
#include <vector>

using namespace std;

// Computed over finite field F_p to prevent integer overflow
long long compute_determinant(vector<vector<long long>> &a, int n,
                              long long p) {
    long long det = 1;
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j][i] > a[pivot][i]) {
                pivot = j;
            }
        }
        if (a[pivot][i] == 0)
            return 0;

        if (i != pivot) {
            swap(a[i], a[pivot]);
            det = (p - det) % p; // Sign change for row swap
        }

        det = (det * a[i][i]) % p;

        // Compute modular inverse of a[i][i] using Fermat's Little Theorem
        long long inv = 1, base = a[i][i], exp = p - 2;
        while (exp > 0) {
            if (exp % 2 == 1)
                inv = (inv * base) % p;
            base = (base * base) % p;
            exp /= 2;
        }

        for (int j = i + 1; j < n; ++j) {
            long long factor = (a[j][i] * inv) % p;
            for (int k = i; k < n; ++k) {
                a[j][k] = (a[j][k] - factor * a[i][k]) % p;
                if (a[j][k] < 0)
                    a[j][k] += p;
            }
        }
    }
    return det;
}
