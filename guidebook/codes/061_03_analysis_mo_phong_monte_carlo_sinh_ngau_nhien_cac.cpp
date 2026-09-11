#include <cmath>
#include <iostream>

using namespace std;

// Numeric Monte Carlo evaluation for Kantorovich bounds
void evaluate_kantorovich_bounds() {
    double m = 1.0, M = 5.0;
    double a = 0.0, b = 2.0;
    int N = 1000;
    double dx = (b - a) / N;

    double int_f = 0, int_inv_f = 0;
    for (int i = 0; i < N; ++i) {
        double x = a + i * dx;
        // Test function oscillating strictly within [m, M]
        double f_x = m + (M - m) * (0.5 * sin(10 * x) + 0.5);
        int_f += f_x * dx;
        int_inv_f += (1.0 / f_x) * dx;
    }

    double product = int_f * int_inv_f;
    double CS_lower = (b - a) * (b - a);
    double Kantorovich_upper = pow(m + M, 2) / (4 * m * M) * CS_lower;

    cout << "Lower Bound (CS): " << CS_lower << endl;
    cout << "Computed Integral Product: " << product << endl;
    cout << "Upper Bound (Kantorovich): " << Kantorovich_upper << endl;
}
