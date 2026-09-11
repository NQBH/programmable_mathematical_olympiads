#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: UIT VMC2025 Prob. 14 & 17 - Factorial Polynomial & Sylvester Telescoping
 * Part (a): S_n = \sum_{i=0}^n (i^4 + 10i^3 + 35i^2 + 50i + 23) / (i+4)! -> 8/3
 * Part (b): x_{n+1} = x_n^2 - x_n + 1, \sum_{n=1}^\infty 1/x_n = 1/(a - 1)
 */

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(12);

    // --- Part (a): Factorial Series ---
    std::cout << "--- Part (a): Factorial Series Limit Verification ---\n";
    double sum_fact = 0.0;
    double fact = 24.0; // 4! = 24

    for (int i = 0; i <= 15; ++i) {
        if (i > 0) {
            fact *= (i + 4.0);
        }
        double num = std::pow(i, 4) + 10.0 * std::pow(i, 3) + 35.0 * std::pow(i, 2) + 50.0 * i + 23.0;
        sum_fact += num / fact;
    }

    const double exact_a = 8.0 / 3.0;
    std::cout << "Computed Sum (n=15): " << sum_fact << "\n";
    std::cout << "Exact Target (8/3) : " << exact_a << "\n";
    assert(std::abs(sum_fact - exact_a) < 1e-12);

    // --- Part (b): Sylvester Nonlinear Telescoping ---
    std::cout << "\n--- Part (b): Sylvester Recurrence Telescoping ---\n";
    double a = 2.0;
    double x = a;
    double sum_sylvester = 0.0;
    double sum_alt = 0.0;

    for (int n = 1; n <= 8; ++n) {
        double term = 1.0 / x;
        sum_sylvester += term;
        sum_alt += (n % 2 == 1 ? 1.0 : -1.0) * term;

        std::cout << "n = " << n << " | x_n = " << x 
                  << " | sum(1/x_k) = " << sum_sylvester << "\n";

        // Next term: x_{n+1} = x_n^2 - x_n + 1
        x = x * x - x + 1.0;
    }

    const double exact_b = 1.0 / (a - 1.0);
    std::cout << "Positive Sum Limit: " << sum_sylvester << " (Target 1/(a-1) = " << exact_b << ")\n";
    std::cout << "Alternating Sum   : " << sum_alt << "\n";
    assert(std::abs(sum_sylvester - exact_b) < 1e-12);

    std::cout << "Verification successful: Both limits verified to 12 decimal places.\n";
    return 0;
}
