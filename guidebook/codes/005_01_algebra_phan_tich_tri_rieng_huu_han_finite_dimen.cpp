#include <iostream>

using namespace std;

// Analytical O(1) evaluator via Spectral extraction
void analyze_circulant_matrix() {
    long long c1 = 2022;
    long long c2 = 2023;
    long long S = c1 + c2;

    // Condition for rank < 3 in R: linear factor must be 0 (since Delta < 0)
    long long x_singular = -S;

    cout << "Real root for rank degradation: x = " << x_singular << "\n";
    cout << "At this root, the submatrix determinant is non-zero, hence rank = "
            "2.\n";
}
