#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: DHGTVT VMC2025 Prob. 13 - King Symmetry Integral Invariance
 * Identity: Int_0^pi x*f(sin x) dx = (pi/2) * Int_0^pi f(sin x) dx
 * Case 1: I1 = Int_0^pi (x*sin x)/(1 + sin^2 x) dx = (pi / sqrt(2)) * ln(sqrt(2) + 1)
 * Case 2: I2 = Int_0^pi (x*sin x)/(4 - cos^2 x) dx = (pi * ln(3)) / 4
 */

double integrand1(double x) {
    double sx = std::sin(x);
    return (x * sx) / (1.0 + sx * sx);
}

double integrand2(double x) {
    double sx = std::sin(x);
    double cx = std::cos(x);
    return (x * sx) / (4.0 - cx * cx);
}

double simpson_pi(double (*func)(double), int n_steps) {
    const double pi = 3.14159265358979323846;
    double h = pi / n_steps;
    double sum = func(0.0) + func(pi);
    for (int i = 1; i < n_steps; ++i) {
        double x = i * h;
        sum += (i % 2 == 1 ? 4.0 : 2.0) * func(x);
    }
    return sum * h / 3.0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const double pi = 3.14159265358979323846;
    const double sqrt2 = std::sqrt(2.0);

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "--- DHGTVT VMC2025 Prob. 13: King Integral Symmetry Verification ---\n";

    int N = 4000;

    // Case 1:
    double num_I1 = simpson_pi(integrand1, N);
    double exact_I1 = (pi / sqrt2) * std::log(sqrt2 + 1.0);
    std::cout << "Integral 1 (1 + sin^2 x):\n"
              << "  Numerical  = " << num_I1 << "\n"
              << "  Analytical = " << exact_I1 << "\n"
              << "  Error      = " << std::abs(num_I1 - exact_I1) << "\n";
    assert(std::abs(num_I1 - exact_I1) < 1e-10);

    // Case 2:
    double num_I2 = simpson_pi(integrand2, N);
    double exact_I2 = (pi * std::log(3.0)) / 4.0;
    std::cout << "Integral 2 (4 - cos^2 x):\n"
              << "  Numerical  = " << num_I2 << "\n"
              << "  Analytical = " << exact_I2 << "\n"
              << "  Error      = " << std::abs(num_I2 - exact_I2) << "\n";
    assert(std::abs(num_I2 - exact_I2) < 1e-10);

    std::cout << "Verification successful: King symmetry property confirmed for all test integrands.\n";
    return 0;
}
