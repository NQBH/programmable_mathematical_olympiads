#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Topic: Inverse Trigonometric Telescoping Series and Asymptotics
 * Identity 1: arctan((f(n) - f(n-1)) / (1 + f(n-1)*f(n))) = arctan(f(n)) - arctan(f(n-1))
 * Example: f(n) = n + 1 => Sum_{n=1}^N arctan(1 / (n^2 + n + 1)) = arctan(N + 1) - arctan(1) -> pi / 4
 * Identity 2: arcsin(f(n)*sqrt(1 - f(n-1)^2) - f(n-1)*sqrt(1 - f(n)^2)) = arcsin(f(n)) - arcsin(f(n-1))
 */

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(12);
    std::cout << "--- Verification of Inverse Trigonometric Telescoping ---\n";

    const double pi = 3.14159265358979323846;

    // 1. Arctan telescoping for f(n) = n + 1:
    // f(n) - f(n-1) = 1, 1 + f(n)*f(n-1) = n^2 + n + 1
    // term_n = arctan(1 / (n^2 + n + 1))
    double sum_arctan = 0.0;
    int N = 100000;

    for (int n = 1; n <= N; ++n) {
        double dn = static_cast<double>(n);
        double term = std::atan(1.0 / (dn * dn + dn + 1.0));
        sum_arctan += term;

        if (n == 10 || n == 100 || n == 1000 || n == N) {
            double expected_partial = std::atan(dn + 1.0) - std::atan(1.0);
            assert(std::abs(sum_arctan - expected_partial) < 1e-12);
        }
    }

    std::cout << "Partial Sum at N = " << N << ": " << sum_arctan << "\n";
    std::cout << "Exact arctan(N+1) - pi/4: " << (std::atan(static_cast<double>(N + 1)) - pi / 4.0) << "\n";
    std::cout << "Infinite Series Limit pi / 4: " << (pi / 4.0) << "\n";
    assert(std::abs(sum_arctan - (std::atan(static_cast<double>(N + 1)) - pi / 4.0)) < 1e-12);

    // 2. Arcsin telescoping for f(n) = 1 / (n + 1):
    // term_n = arcsin(f(n)*sqrt(1 - f(n-1)^2) - f(n-1)*sqrt(1 - f(n)^2))
    double sum_arcsin = 0.0;
    int M = 5000;
    for (int n = 1; n <= M; ++n) {
        double fn = 1.0 / (n + 1.0);
        double fn_prev = 1.0 / static_cast<double>(n);
        double arg = fn * std::sqrt(1.0 - fn_prev * fn_prev) - fn_prev * std::sqrt(1.0 - fn * fn);
        double term = std::asin(arg);
        sum_arcsin += term;
    }

    // Telescoping result: arcsin(f(M)) - arcsin(f(0)) with f(0) = 1
    // arcsin(1 / (M + 1)) - arcsin(1) = arcsin(1 / (M + 1)) - pi / 2
    double expected_arcsin_sum = std::asin(1.0 / (M + 1.0)) - (pi / 2.0);
    std::cout << "Arcsin Telescoping Sum: " << sum_arcsin << " (Expected: " << expected_arcsin_sum << ")\n";
    assert(std::abs(sum_arcsin - expected_arcsin_sum) < 1e-11);

    std::cout << "Verification successful: All inverse trigonometric identities match exact telescope.\n";
    return 0;
}
