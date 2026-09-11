#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: DHGTVT VMC2025 Prob. 7 - Nonlinear Fixed-Point Recurrence
 * x_1 = 2025, x_{n+1} = \sqrt{5} + 2*x_n / \sqrt{x_n^2 - 4}
 * Target Limit: L = 2*sqrt(5)
 * Complexity: O(k) iterations to achieve machine precision, O(1) space.
 */

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const double sqrt5 = std::sqrt(5.0);
    const double exact_limit = 2.0 * sqrt5;

    double x = 2025.0;
    std::cout << std::fixed << std::setprecision(12);
    std::cout << "Exact Theoretical Limit L = 2*sqrt(5) = " << exact_limit << "\n";
    std::cout << "Iterative convergence history:\n";

    for (int n = 1; n <= 15; ++n) {
        double error = std::abs(x - exact_limit);
        std::cout << "n = " << std::setw(2) << n 
                  << " | x_n = " << std::setw(16) << x 
                  << " | error = " << error << "\n";

        if (error < 1e-13) {
            std::cout << "Convergence reached machine precision at iteration " << n << ".\n";
            break;
        }

        assert(x > 2.0 + sqrt5);
        x = sqrt5 + (2.0 * x) / std::sqrt(x * x - 4.0);
    }

    assert(std::abs(x - exact_limit) < 1e-13);
    std::cout << "Verification successful: Sequence converges to 2*sqrt(5).\n";

    return 0;
}
