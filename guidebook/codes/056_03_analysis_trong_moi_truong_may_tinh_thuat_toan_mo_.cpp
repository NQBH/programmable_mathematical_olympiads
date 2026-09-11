#include <cmath>
#include <iostream>

using namespace std;

// Numeric continuous functional root solver
double find_mean_value_root(double a, double b, double I_f, double I_g) {
    double low = a, high = b, mid;
    double tol = 1e-6;

    // Abstract root finding using bisection for the functional equation
    // Assuming a test function configuration where root exists monotonically
    for (int i = 0; i < 50; ++i) {
        mid = (low + high) / 2.0;
        // Test functions f(x)=x, g(x)=x^2 for demonstration
        double f_mid = mid;
        double g_mid = mid * mid;

        double eval = I_f * g_mid - I_g * f_mid;

        if (abs(eval) < tol)
            break;
        if (eval > 0)
            high = mid; // Direction depends on specific test function
        else
            low = mid;
    }
    return mid;
}
