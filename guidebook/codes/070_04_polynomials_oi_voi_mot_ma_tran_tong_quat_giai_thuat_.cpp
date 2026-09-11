#include <iostream>
#include <vector>
using namespace std;

// Compute the Vandermonde determinant via dimensional differences (O(n^2))
long long vandermondeDeterminant(const vector<long long> &x, long long MOD) {
    int n = x.size();
    long long det = 1;
    // Iterate across combinatorial pairs (i, j) maintaining i < j
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long diff = (x[j] - x[i]) % MOD;
            if (diff < 0)
                diff += MOD;
            det = (det * diff) % MOD;
        }
    }
    return det;
}
