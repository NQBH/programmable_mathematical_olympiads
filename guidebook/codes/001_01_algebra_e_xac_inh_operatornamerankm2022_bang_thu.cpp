#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Compute the algebraic rank of matrix M(a)
int matrixRank(vector<vector<double>> M) {
    int n = M.size();
    int rank = 0;
    for (int i = 0; i < n; i++) {
        // Pivot selection to mitigate floating-point degradation
        if (abs(M[i][i]) < 1e-9) {
            bool swapped = false;
            for (int j = i + 1; j < n; j++) {
                if (abs(M[j][i]) > 1e-9) {
                    swap(M[i], M[j]);
                    swapped = true;
                    break;
                }
            }
            if (!swapped)
                continue;
        }
        rank++;
        // Execute Gaussian elimination on subsequent rows
        for (int j = i + 1; j < n; j++) {
            double factor = M[j][i] / M[i][i];
            for (int k = i; k < n; k++) {
                M[j][k] -= factor * M[i][k];
            }
        }
    }
    return rank;
}
