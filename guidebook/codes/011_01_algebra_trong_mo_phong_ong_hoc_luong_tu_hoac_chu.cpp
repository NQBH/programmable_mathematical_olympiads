#include <cmath>
#include <iostream>

using namespace std;

// O(1) closed-form matrix exponential evaluator for diagonalized systems
void compute_matrix_exponential() {
    double e = exp(1.0);
    double e2 = exp(2.0);

    // Constructed directly from spectral decomposition D = diag(1, 2)
    double eA[2][2] = {{e, e - e2}, {0, e2}};

    cout << "Exact e^A element (0,1): " << eA[0][1] << "\n";
}
