#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: VMC2025GTA1B1 - Infinite Product Convergence & Positivity Bound
 * Computes a_n = \prod_{i=1}^n (1 - \pi / (i + 1)^2).
 * Complexity: O(n) operations, O(1) auxiliary space.
 */

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const double PI_CONST = std::acos(-1.0);
    const int N_MAX = 2000000;

    double product = 1.0;
    double log_sum = 0.0;
    
    // Euler sine product analytical value: sin(pi*sqrt(pi)) / (pi*sqrt(pi)*(1 - pi))
    const double sqrt_pi = std::sqrt(PI_CONST);
    const double exact_limit = std::sin(PI_CONST * sqrt_pi) / (PI_CONST * sqrt_pi * (1.0 - PI_CONST));

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Analytical asymptotic limit: " << exact_limit << "\n";

    for (int i = 1; i <= N_MAX; ++i) {
        double denom = static_cast<double>(i + 1) * static_cast<double>(i + 1);
        double factor = 1.0 - (PI_CONST / denom);
        
        assert(factor > 0.0 && factor < 1.0);
        product *= factor;
        log_sum += std::log(factor);

        if (i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == N_MAX) {
            std::cout << "n = " << std::setw(7) << i 
                      << " | a_n = " << product 
                      << " | log(a_n) = " << log_sum 
                      << " | diff = " << std::abs(product - exact_limit) << "\n";
        }
    }

    assert(product > 0.05);
    assert(std::abs(product - exact_limit) < 1e-4);
    std::cout << "Verification successful: Infinite product converges to non-zero positive limit.\n";

    return 0;
}
