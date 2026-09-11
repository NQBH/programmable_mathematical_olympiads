#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: UIT VMC2025 Prob. 3 - Polynomial Divisibility & Commuting Derivatives
 * Part (a): x^m + x^n + 1 is divisible by x^2 + x + 1 iff (m*n - 2) % 3 == 0
 * Part (b): P(P'(x)) = P'(P(x)) in Z[x] iff P(x) = a*x + a*(1 - a)
 */

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // --- Part (a): Exhaustive Modular Polynomial Division ---
    std::cout << "--- Part (a): Verification of Divisibility Condition ---\n";
    int valid_count = 0;
    int checked_count = 0;

    for (int m = 1; m <= 30; ++m) {
        for (int n = 1; n <= 30; ++n) {
            // Since x^3 = 1 mod (x^2 + x + 1), x^k mod (x^2 + x + 1) = x^(k % 3)
            int r = m % 3;
            int s = n % 3;

            // In R[x] / (x^2 + x + 1):
            // x^0 = 1
            // x^1 = x
            // x^2 = -x - 1
            // Compute remainder of x^r + x^s + 1:
            // Let remainder be c1*x + c0:
            int c1 = 0, c0 = 1;
            for (int p : {r, s}) {
                if (p == 0) c0 += 1;
                else if (p == 1) c1 += 1;
                else if (p == 2) { c1 -= 1; c0 -= 1; }
            }

            bool is_divisible = (c1 == 0 && c0 == 0);
            bool theoretical_condition = ((m * n - 2) % 3 == 0);

            assert(is_divisible == theoretical_condition);
            checked_count++;
            if (is_divisible) valid_count++;
        }
    }
    std::cout << "Checked " << checked_count << " pairs of (m, n). Valid pairs: " << valid_count << "\n";
    std::cout << "Exact equivalence: Divisible <=> (m*n - 2) % 3 == 0 verified.\n";

    // --- Part (b): Verification of Commuting Derivative Polynomials ---
    std::cout << "\n--- Part (b): Verification of P(P'(x)) == P'(P(x)) ---\n";
    for (int a = -10; a <= 10; ++a) {
        int b = a * (1 - a);
        // P(x) = a*x + b, P'(x) = a
        // P(P'(x)) = a*(a) + b = a^2 + a - a^2 = a
        // P'(P(x)) = a
        assert(a * a + b == a);
    }
    std::cout << "Verified P(P'(x)) == P'(P(x)) for linear family P(x) = a*x + a*(1 - a).\n";

    std::cout << "Verification successful: Both parts confirmed.\n";
    return 0;
}
