#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: UIT VMC2025 Prob. 16 - Implicit Curve Integral
 * Equation: z^4 + x*z^2 = 2025, z(x) > 0
 * Target: I = \int_0^{2024} z^3 dx
 * Exact Analytical Value: 14580*sqrt(5) - 20252/5
 */

// Explicit positive root z(x) of z^4 + x*z^2 - 2025 = 0
double z_func(double x) {
    double discriminant = x * x + 4.0 * 2025.0; // x^2 + 8100
    double z_sq = (-x + std::sqrt(discriminant)) / 2.0;
    return std::sqrt(z_sq);
}

// Integrand: z(x)^3
double integrand(double x) {
    double z = z_func(x);
    return z * z * z;
}

// Composite Simpson's 1/3 Rule
double simpson_integrate(double a, double b, int n_intervals) {
    assert(n_intervals % 2 == 0);
    double h = (b - a) / n_intervals;
    double sum = integrand(a) + integrand(b);

    for (int i = 1; i < n_intervals; ++i) {
        double x = a + i * h;
        sum += (i % 2 == 1 ? 4.0 : 2.0) * integrand(x);
    }
    return sum * (h / 3.0);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(10);

    const double sqrt5 = std::sqrt(5.0);
    const double exact_I = 14580.0 * sqrt5 - (20252.0 / 5.0);
    std::cout << "Exact Analytical Value: 14580*sqrt(5) - 20252/5 = " << exact_I << "\n";

    std::cout << "\nConvergence of Numerical Quadrature:\n";
    for (int intervals : {1000, 10000, 100000, 1000000}) {
        double approx = simpson_integrate(0.0, 2024.0, intervals);
        double error = std::abs(approx - exact_I);
        std::cout << "Intervals: " << std::setw(8) << intervals 
                  << " | Approx: " << approx 
                  << " | Error: " << error << "\n";
    }

    double final_approx = simpson_integrate(0.0, 2024.0, 1000000);
    assert(std::abs(final_approx - exact_I) < 1e-5);
    std::cout << "\nVerification successful: Numerical integral matches analytical closed-form.\n";

    return 0;
}
