#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: DHGTVT VMC2025 Prob. 6 - Matrix Rank Optimization
 * A(x) = {{x, 2, x, 2}, {2, x, 2, x}, {x, x, -1, -1}, {-1, -1, x, x}}
 * Invariants: col1 - col2 - col3 + col4 == 0 for all x => det A(x) == 0 identically.
 * Maximum rank is 3 for x not in {-1, 2}; rank is 2 for x in {-1, 2}.
 */

// Compute rank via Gaussian elimination
int compute_rank(std::vector<std::vector<double>> mat) {
    int n = mat.size();
    int m = mat[0].size();
    int rank = 0;
    const double EPS = 1e-9;

    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int pivot = row;
        for (int i = row + 1; i < n; ++i) {
            if (std::abs(mat[i][col]) > std::abs(mat[pivot][col])) {
                pivot = i;
            }
        }
        if (std::abs(mat[pivot][col]) < EPS) continue;

        std::swap(mat[row], mat[pivot]);
        for (int i = 0; i < n; ++i) {
            if (i != row && std::abs(mat[i][col]) > EPS) {
                double factor = mat[i][col] / mat[row][col];
                for (int j = col; j < m; ++j) {
                    mat[i][j] -= factor * mat[row][j];
                }
            }
        }
        ++row;
        ++rank;
    }
    return rank;
}

std::vector<std::vector<double>> build_matrix(double x) {
    return {
        {x, 2.0, x, 2.0},
        {2.0, x, 2.0, x},
        {x, x, -1.0, -1.0},
        {-1.0, -1.0, x, x}
    };
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << "--- DHGTVT VMC2025 Prob. 6: Rank Optimization Verification ---\n";

    // 1. Check singular values x in {-1, 2}
    int rank_minus1 = compute_rank(build_matrix(-1.0));
    int rank_plus2  = compute_rank(build_matrix(2.0));
    std::cout << "Rank at x = -1: " << rank_minus1 << " (Expected: 2)\n";
    std::cout << "Rank at x =  2: " << rank_plus2  << " (Expected: 2)\n";
    assert(rank_minus1 == 2);
    assert(rank_plus2 == 2);

    // 2. Check general values of x
    std::vector<double> test_vals = {-10.0, -3.5, 0.0, 0.5, 1.0, 3.0, 100.0};
    for (double x : test_vals) {
        int r = compute_rank(build_matrix(x));
        assert(r == 3);
    }
    std::cout << "Rank at general x != -1, 2 is universally 3 (Maximum rank).\n";

    std::cout << "Verification successful: Max rank is 3 on R \\ {-1, 2}, Min rank is 2 at {-1, 2}.\n";
    return 0;
}
