#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: VMC2025GTA5 & GTB5 - Integral Mean Value Theorem Dynamics
 * f(x) = e^x / (sqrt(e) + e^x) on [0, 1]
 * Verification: Int_0^1 f = 1/2, unique c = 1/2, distinct pairs a != b with f(a)*f(b) = I^2
 */

double f_eval(double x) {
    double sqrt_e = std::sqrt(std::exp(1.0));
    double ex = std::exp(x);
    return ex / (sqrt_e + ex);
}

// Composite Simpson quadrature on [0, 1]
double simpson_integrate(double (*func)(double), int n_steps) {
    double h = 1.0 / n_steps;
    double sum = func(0.0) + func(1.0);
    for (int i = 1; i < n_steps; ++i) {
        double x = i * h;
        sum += (i % 2 == 1 ? 4.0 : 2.0) * func(x);
    }
    return sum * h / 3.0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "--- VMC 2025 GTB5: Verification of f(x) = e^x / (sqrt(e) + e^x) ---\n";

    // 1. Numerical integral of f
    int N = 2000;
    double I_f = simpson_integrate(f_eval, N);
    std::cout << "Computed Int_0^1 f(x) dx = " << I_f << " (Exact: 0.5)\n";
    assert(std::abs(I_f - 0.5) < 1e-12);

    // 2. Verification of point c = 0.5
    double f_at_half = f_eval(0.5);
    std::cout << "f(1/2) = " << f_at_half << "\n";
    assert(std::abs(f_at_half - 0.5) < 1e-12);

    // 3. GTA5 Part (b): Find distinct a != b in (0, 1) such that f(a)*f(b) = (1/2)^2 = 0.25
    // For any x in (0, 1/2), let a = x, f(a) < 0.5.
    // Target f(b) = 0.25 / f(a). Since f is strictly increasing from f(0) to f(1):
    // f(0) = 1 / (sqrt(e) + 1) ~ 0.37754
    // f(1) = e / (sqrt(e) + e) ~ 0.62246
    // Choose a = 0.2:
    double a = 0.2;
    double fa = f_eval(a);
    double target_fb = 0.25 / fa;

    // Invert f(x) = y: y*(sqrt_e + e^x) = e^x => e^x*(1 - y) = y*sqrt_e => x = ln(y*sqrt_e / (1 - y))
    double sqrt_e = std::sqrt(std::exp(1.0));
    double b = std::log((target_fb * sqrt_e) / (1.0 - target_fb));
    double fb = f_eval(b);

    std::cout << "Found distinct pair: a = " << a << " (f(a) = " << fa << "), "
              << "b = " << b << " (f(b) = " << fb << ")\n";
    std::cout << "Product f(a)*f(b) = " << (fa * fb) << " (Expected: 0.25)\n";

    assert(a != b);
    assert(b > 0.0 && b < 1.0);
    assert(std::abs(fa * fb - 0.25) < 1e-12);

    // 4. GTB5 Part (c): Variance non-vanishing for non-constant function
    auto f_sq = [](double x) { double y = f_eval(x); return y * y; };
    double I_f2 = simpson_integrate(f_sq, N);
    double variance = I_f2 - I_f * I_f;
    std::cout << "Int_0^1 f^2 = " << I_f2 << " | Variance = " << variance << " > 0\n";
    assert(variance > 1e-4); // Proves f must be constant for Int f^2 = (Int f)^2

    std::cout << "Verification successful: All Mean Value Theorem properties confirmed.\n";
    return 0;
}
