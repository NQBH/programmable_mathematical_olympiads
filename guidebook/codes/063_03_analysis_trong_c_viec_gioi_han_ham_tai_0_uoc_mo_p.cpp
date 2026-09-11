#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Numeric continuous limits mapped to Taylor derivative evaluation
void evaluate_trigonometric_bound() {
    vector<double> a = {0.5, 0.25}; // Example coefficients a_1, a_2
    double x = 1e-7;                // Epsilon evaluation

    double f_x = 0;
    for (size_t k = 0; k < a.size(); ++k) {
        f_x += a[k] * sin((k + 1) * x);
    }

    double derivative_approx = f_x / x;

    double analytic_derivative = 0;
    for (size_t k = 0; k < a.size(); ++k) {
        analytic_derivative += (k + 1) * a[k];
    }

    cout << "Numeric f(x)/x: " << derivative_approx << endl;
    cout << "Analytic sum(k*a_k): " << analytic_derivative << endl;
}
