#include <cmath>
#include <iostream>

using namespace std;

// Numeric continuous limits mapped to Harmonic series
void evaluate_harmonic_functional_limit(int n) {
    double x = 1e-6; // Epsilon approach to 0
    double k = 2.5;  // Let test function f(t) = sin(k*t), so f'(0) = k

    double sum_f = 0;
    for (int i = 1; i <= n; ++i) {
        sum_f += sin(k * (x / i));
    }

    double limit_val = sum_f / x;

    // Analytic Harmonic baseline
    double H_n = 0;
    for (int i = 1; i <= n; ++i)
        H_n += 1.0 / i;

    cout << "Numeric Limit for f(t)=sin(2.5t): " << limit_val << endl;
    cout << "Analytic H_n * f'(0): " << H_n * k << endl;
}
