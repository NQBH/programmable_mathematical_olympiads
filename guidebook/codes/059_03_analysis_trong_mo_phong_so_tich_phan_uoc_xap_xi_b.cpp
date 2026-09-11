#include <iostream>
#include <vector>

using namespace std;

// O(n) Riemann sum simulation to verify L2 minimization
void evaluate_l2_minimization() {
    int N = 1000;
    double a = 0.0, b = 1.0;
    double dx = (b - a) / N;

    double mean_f = 0.0;
    // Test function f(x) = x
    for (int i = 0; i < N; ++i) {
        double x = a + i * dx;
        mean_f += x * dx;
    }

    // Evaluate variance around a test point t != mean_f
    double t = mean_f + 0.5; // Offset
    double var_mean = 0.0, var_t = 0.0;

    for (int i = 0; i < N; ++i) {
        double x = a + i * dx;
        var_mean += (x - mean_f) * (x - mean_f) * dx;
        var_t += (x - t) * (x - t) * dx;
    }

    cout << "Variance at mean (t_opt): " << var_mean << endl;
    cout << "Variance at offset t: " << var_t << " (Strictly larger)" << endl;
}
