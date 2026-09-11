#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// O(k*n^2) Iterative Neumann approximation for Leontief Systems
void evaluate_leontief_neumann() {
    // Leontief transition matrix A and demand vector d
    double A[2][2] = {{0.3, 0.2}, {0.1, 0.4}};
    double d[2] = {12.0, 8.0};

    double x[2] = {0.0, 0.0}; // Initial state vector
    double tol = 1e-9;
    double max_err = 1.0;

    // Iterative evaluation representing infinite sum A^k * d
    while (max_err > tol) {
        double x_next[2] = {A[0][0] * x[0] + A[0][1] * x[1] + d[0],
                            A[1][0] * x[0] + A[1][1] * x[1] + d[1]};

        max_err = max(abs(x_next[0] - x[0]), abs(x_next[1] - x[1]));
        x[0] = x_next[0];
        x[1] = x_next[1];
    }

    cout << "Production limits (Electric, Water): " << x[0] << ", " << x[1]
         << endl;
}
