#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Execute Laplacian determinant computation to evaluate spanning tree
// cardinality
long long countSpanningTrees(vector<vector<long long>> &adjacency_matrix,
                             long long MOD) {
    int n = adjacency_matrix.size();
    if (n <= 1)
        return 1;

    // Construct the standard Laplacian Matrix L = D - A
    vector<vector<long long>> L(n - 1, vector<long long>(n - 1, 0));
    for (int i = 0; i < n - 1; i++) {
        long long degree = 0;
        for (int j = 0; j < n; j++) {
            if (adjacency_matrix[i][j]) {
                degree++;
                if (j < n - 1) {
                    L[i][j] = (L[i][j] - adjacency_matrix[i][j] + MOD) % MOD;
                }
            }
        }
        L[i][i] = (L[i][i] + degree) % MOD;
    }

    // Compute principal minor determinant via Gaussian elimination O(n^3)
    long long det = 1;
    for (int i = 0; i < n - 1; i++) {
        // [Gaussian elimination, row permutation, and modular inversion
        // routines omitted]
        // ... (Algorithmic logic abbreviated to isolate the Laplacian
        // architecture)
        det = (det * L[i][i]) % MOD;
    }

    return det;
}
