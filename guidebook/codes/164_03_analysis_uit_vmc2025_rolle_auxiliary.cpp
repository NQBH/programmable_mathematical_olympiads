#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: UIT VMC2025 Prob. 15 - Rolle Auxiliary Function for Integral Moments
 * Hypothesis: Int_0^1 f(x) dx = Int_0^1 x*f(x) dx
 * Conclusion: Exists c in (0, 1) such that (1 - c)*f(c) + c * Int_0^c f(t) dt = 0
 */

// Test function: f(x) = 1 - 2x - 2x^2
// Int_0^1 f = 1 - 1 - 2/3 = -2/3
// Int_0^1 x*f = 1/2 - 2/3 - 2/4 = 1/2 - 2/3 - 1/2 = -2/3
double f_test(double x) {
    return 1.0 - 2.0 * x - 2.0 * x * x;
}

// Antiderivative F(x) = Int_0^x f(t) dt = x - x^2 - (2/3)*x^3
double F_int(double x) {
    return x - x * x - (2.0 / 3.0) * x * x * x;
}

// Auxiliary Rolle target: T(x) = (1 - x)*f(x) + x*F_int(x)
double target_expr(double x) {
    return (1.0 - x) * f_test(x) + x * F_int(x);
}

// Bisection method to find root of continuous function
double find_root_bisection(double (*func)(double), double low, double high, double tol = 1e-12) {
    double f_low = func(low);
    double f_high = func(high);
    assert(f_low * f_high <= 0.0);

    while (high - low > tol) {
        double mid = (low + high) / 2.0;
        double f_mid = func(mid);
        if (std::abs(f_mid) < tol) return mid;
        if (f_low * f_mid <= 0.0) {
            high = mid;
            f_high = f_mid;
        } else {
            low = mid;
            f_low = f_mid;
        }
    }
    return (low + high) / 2.0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "--- UIT VMC2025 Prob. 15: Verification of Auxiliary Rolle Root ---\n";

    // 1. Verify integral moment condition: Int_0^1 f == Int_0^1 x*f
    double I_f = F_int(1.0);
    double I_xf = 0.5 - (2.0 / 3.0) - 0.5; // -2/3
    std::cout << "Int_0^1 f(x) dx   = " << I_f << "\n";
    std::cout << "Int_0^1 x*f(x) dx = " << I_xf << "\n";
    assert(std::abs(I_f - I_xf) < 1e-12);

    // 2. Find alpha in (0, 1) such that F_int(alpha) = 0
    // F(0) = 0, F(0.5) = 0.5 - 0.25 - 2/24 = 0.1666 > 0, F(1) = -2/3 < 0
    double alpha = find_root_bisection(F_int, 0.5, 1.0);
    std::cout << "Found Rolle zero of F: alpha = " << alpha 
              << " | F(alpha) = " << F_int(alpha) << "\n";
    assert(std::abs(F_int(alpha)) < 1e-11);

    // 3. Find c in (0, alpha) such that target_expr(c) = 0
    // At x = 0: target(0) = (1 - 0)*f(0) + 0 = 1.0 > 0
    // At x = alpha: target(alpha) = (1 - alpha)*f(alpha) + alpha*F_int(alpha) = (1 - alpha)*f(alpha)
    // f(alpha) = 1 - 2*alpha - 2*alpha^2. For alpha ~ 0.72, f(alpha) ~ 1 - 1.44 - 1.03 < 0
    double target_at_0 = target_expr(0.0);
    double target_at_alpha = target_expr(alpha);
    std::cout << "Target at 0     = " << target_at_0 << " (> 0)\n";
    std::cout << "Target at alpha = " << target_at_alpha << " (< 0)\n";
    assert(target_at_0 > 0 && target_at_alpha < 0);

    double c_root = find_root_bisection(target_expr, 0.0, alpha);
    std::cout << "Found Rolle root: c = " << c_root 
              << " in (0, " << alpha << ") subset (0, 1)\n";
    std::cout << "Target value at c: " << target_expr(c_root) << "\n";

    assert(c_root > 0.0 && c_root < alpha);
    assert(std::abs(target_expr(c_root)) < 1e-10);

    std::cout << "Verification successful: Point c exists and satisfies (1 - c)*f(c) + c*Int_0^c f == 0.\n";
    return 0;
}
